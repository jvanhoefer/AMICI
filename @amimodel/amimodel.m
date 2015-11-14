%
% @file amimodel
% @brief definition of amimodel class
%
classdef amimodel
    % amimodel is the object in which all model definitions are stored 
    
    properties ( GetAccess = 'public', SetAccess = 'public' )
        % symbolic definition struct @type struct
        sym;
        % struct which stores information for which functions c code needs to be generated @type struct
        fun;
        % short names for symbolic variables @type struct
        strsym;
        % name of the model @type string
        modelname;
        % struct that contains hash values for the symbolic model definitions @type struct
        HTable;
        % default absolute tolerance @type double
        atol = 1e-8;
        % default relative tolerance @type double
        rtol = 1e-8;
        % default maximal number of integration steps @type int
        maxsteps = 1e4;
        % flag indicating whether debugging symbols should be compiled @type bool
        debug = false;
        % flag indicating whether adjoint sensitivities should be enabled @type bool
        adjoint = true;
        % flag indicating whether forward sensitivities should be enabled @type bool
        forward = true;
        % default initial time @type double
        t0 = 0;
        % type of wrapper (cvodes/idas) @type string
        wtype;
        % number of states @type int
        nx;
        % number of original states for second order sensitivities @type int
        nxtrue = 0;
        % number of observables @type int
        ny;
        % number of original observables for second order sensitivities @type int
        nytrue = 0;
        % number of events @type int
        nr;
        % number of discontinuities @type int
        ndisc;
        % number of parameters @type int
        np;
        % number of constants @type int
        nk;
        % flag for DAEs @type *int
        id;
        % upper Jacobian bandwidth @type int
        ubw;
        % lower Jacobian bandwidth @type int
        lbw;
        % number of nonzero entries in Jacobian @type int
        nnz;
        % dataindexes of sparse Jacobian @type *int
        sparseidx;
        % rowindexes of sparse Jacobian @type *int
        rowvals;
        % columnindexes of sparse Jacobian @type *int
        colptrs;
        % dataindexes of sparse Jacobian @type *int
        sparseidxB;
        % rowindexes of sparse Jacobian @type *int
        rowvalsB;
        % columnindexes of sparse Jacobian @type *int
        colptrsB;
        % cell array of functions to be compiled @type *cell
        funs;
        % optimisation flag for compilation @type string
        coptim = '-O3';
        % default parametrisation @type string
        param = 'lin';
        % path to wrapper
        wrap_path;
        % flag to enforce recompilation of the model
        recompile = false;
    end
    
    methods
        function AM = amimodel(symfun,modelname)
            % constructor of the amimodel class. this function initializes the model object based on the provided
            % symfun and modelname
            %
            % Parameters:
            %  symfun: this is the string to the function which generates
            %  the modelstruct. You can also directly pass the struct here @type string
            %  modelname: name of the model @type string
            % 
            % Return values:
            %  AM: model definition object
            if(isa(symfun,'char'))
                model = eval(symfun);
            elseif(isa(symfun,'struct'))
                model = symfun;
            else
                error('invalid input symfun')
            end
            
            if(isfield(model,'sym'))
                AM.sym = model.sym;
            else
                error('symbolic definitions missing in struct returned by symfun')
            end
            
            props = properties(AM);
            
            for j = 1:length(props)
                if(~strcmp(props{j},'sym')) % we already checked for the sym field
                    if(isfield(model,props{j}))
                       AM.(props{j}) = model.(props{j});
                    end
                end
            end

            AM.modelname = modelname;
            % set path and create folder
            AM.wrap_path=fileparts(which('amiwrap.m'));
            if(~exist(fullfile(AM.wrap_path,'models'),'dir'))
                mkdir(fullfile(AM.wrap_path,'models'));
                mkdir(fullfile(AM.wrap_path,'models',AM.modelname));
            else
                if(~exist(fullfile(AM.wrap_path,'models',AM.modelname),'dir'))
                    mkdir(fullfile(AM.wrap_path,'models',AM.modelname))
                end
            end
        end
        
        this = parseModel(this)
        
        this = generateC(this)
        
        this = compileC(this)
        
        this = writeCcode_sensi(this,svar,fid)
        
        this = writeCcode(this, funstr, fid, ip, jp)
        
        this = gccode(this,csym,funstr,cvar,fid)
        
        this = generateM(this,amimodelo2)
        
        this = getFun(this,HTable,funstr)
        
        [ deps ] = getFunDeps(this, funstr )
        
        [ argstr ] = getFunArgs(this, funstr )
        
        [ cvar ] = getFunCVar(this, funstr )
        
        [ svar ] = getFunSVar(this, funstr )
        
        [this,cflag] = checkDeps(this,HTable,deps)
        
        [this,HTable] = loadOldHashes(this) 
        
        [this] = augmento2(this)

    end
end
