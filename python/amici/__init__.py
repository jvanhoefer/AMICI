""" @package amici
The AMICI Python module (in doxygen this will also contain documentation about the C++ library)

The AMICI Python module provides functionality for importing SBML models and turning them into C++ Python extensions.

Getting started:
```
# creating a extension module for an SBML model:
import amici
amiSbml = amici.SbmlImporter('mymodel.sbml')
amiSbml.sbml2amici('modelName', 'outputDirectory')

# using the created module (set python path)
import modelName
help(modelName)
```

Attributes:
    amici_path: absolute root path of the amici repository
    amiciSwigPath: absolute path of the amici swig directory
    amiciSrcPath: absolute path of the amici source directory
    amiciModulePath: absolute root path of the amici module
    hdf5_enabled: boolean indicating if amici was compiled with hdf5 support
    has_clibs: boolean indicating if this is the full package with swig
               interface or the raw package without
    capture_cstdout: context to redirect C/C++ stdout to python stdout if
        python stdout was redirected (doing nothing if not redirected).
"""

import os
import re
import sys
from contextlib import suppress

# redirect C/C++ stdout to python stdout if python stdout is redirected,
# e.g. in ipython notebook
capture_cstdout = suppress
if sys.stdout != sys.__stdout__:
    try:
        from wurlitzer import sys_pipes as capture_cstdout
    except ModuleNotFoundError:
        pass

hdf5_enabled = False
has_clibs = False

try:
    from . import amici
    from .amici import *
    hdf5_enabled = True
    has_clibs = True
except (ImportError, ModuleNotFoundError, AttributeError):  # pragma: no cover
    try:
        from . import amici_without_hdf5 as amici
        from .amici_without_hdf5 import *
        has_clibs = True
    except (ImportError, ModuleNotFoundError, AttributeError):
        pass

# determine package installation path, or, if used directly from git
# repository, get repository root
if os.path.exists(os.path.join(os.path.dirname(__file__), '..', '..', '.git')):
    amici_path = os.path.abspath(os.path.join(
        os.path.dirname(__file__), '..', '..'))
else:
    amici_path = os.path.dirname(__file__)

amiciSwigPath = os.path.join(amici_path, 'swig')
amiciSrcPath = os.path.join(amici_path, 'src')
amiciModulePath = os.path.dirname(__file__)

# Get version number from file
with open(os.path.join(amici_path, 'version.txt')) as f:
    __version__ = f.read().strip()

# get commit hash from file
_commitfile = next(
    (
        file for file in [
            os.path.join(amici_path, '..', '..', '..', '.git', 'FETCH_HEAD'),
            os.path.join(amici_path, '..', '..', '..', '.git', 'ORIG_HEAD'),
        ]
        if os.path.isfile(file)
    ),
    None
)

if _commitfile:
    with open(_commitfile) as f:
        __commit__ = str(re.search(r'^([\w]*)', f.read().strip()).group())
else:
    __commit__ = 'unknown'


try:
    # These module require the swig interface and other dependencies which will
    # be installed if the the AMICI package was properly installed. If not,
    # AMICI was probably imported from setup.py and we don't need those.
    from .sbml_import import SbmlImporter, assignmentRules2observables, \
        constantSpeciesToParameters
    from .numpy import rdataToNumPyArrays, edataToNumPyArrays
    from .pandas import getEdataFromDataFrame, \
        getDataObservablesAsDataFrame, getSimulationObservablesAsDataFrame, \
        getSimulationStatesAsDataFrame, getResidualsAsDataFrame
    from .ode_export import ODEModel, ODEExporter
    from .pysb_import import pysb2amici, ODEModel_from_pysb_importer
except ImportError:
    pass


def runAmiciSimulation(model, solver, edata=None):
    """ Convenience wrapper around amici.runAmiciSimulation (generated by swig)

    Arguments:
        model: Model instance
        solver: Solver instance, must be generated from Model.getSolver()
        edata: ExpData instance (optional)

    Returns:
        ReturnData object with simulation results

    Raises:

    """
    if edata and edata.__class__.__name__ == 'ExpDataPtr':
        edata = edata.get()

    with capture_cstdout():
        rdata = amici.runAmiciSimulation(solver.get(), edata, model.get())
    return rdataToNumPyArrays(rdata)


def ExpData(*args):
    """ Convenience wrapper for ExpData constructors

    Arguments:
        args: arguments

    Returns:
        ExpData Instance

    Raises:

    """
    if isinstance(args[0], dict):
        # rdata dict created by rdataToNumPyArrays
        return amici.ExpData(args[0]['ptr'].get(), *args[1:])
    elif isinstance(args[0], ExpDataPtr):
        # the *args[:1] should be empty, but by the time you read this,
        # the constructor signature may have changed and you are glad this
        # wrapper did not break.
        return amici.ExpData(args[0].get(), *args[:1])
    else:
        return amici.ExpData(*args)


def runAmiciSimulations(model, solver, edata_list, num_threads=1):
    """ Convenience wrapper for loops of amici.runAmiciSimulation

    Arguments:
        model: Model instance
        solver: Solver instance, must be generated from Model.getSolver()
        edata_list: list of ExpData instances
        num_threads: number of threads to use
                     (only used if compiled with openmp)

    Returns:
        list of ReturnData objects with simulation results

    Raises:

    """
    with capture_cstdout():
        edata_ptr_vector = amici.ExpDataPtrVector(edata_list)
        rdata_ptr_list = amici.runAmiciSimulations(solver.get(),
                                                   edata_ptr_vector,
                                                   model.get(),
                                                   num_threads)
    return [numpy.rdataToNumPyArrays(r) for r in rdata_ptr_list]
