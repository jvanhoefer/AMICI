
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include <include/rdata.h>
#include <include/edata.h>
#include "model_neuron_w.h"

int dJzdz_model_neuron(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
memset(tdata->dJzdz,0,sizeof(realtype)*udata->nz*udata->nztrue*udata->nJ);
status = w_model_neuron(t,x,NULL,user_data);
int iz;
if(!amiIsNaN(edata->mz[0*udata->nmaxevent+tdata->nroots[ie]])){
    iz = 0;
  tdata->dJzdz[iz+(0)*udata->nztrue] = 1.0/(tdata->sigmaz[0]*tdata->sigmaz[0])*(edata->mz[tdata->nroots[ie]+udata->nmaxevent*0]*2.0-rdata->z[tdata->nroots[ie]+udata->nmaxevent*0]*2.0)*-5.0E-1;
}
return(status);

}


