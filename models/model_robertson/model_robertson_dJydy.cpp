
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/tdata.h>
#include <include/udata.h>
#include <include/rdata.h>
#include <include/edata.h>
#include "model_robertson_w.h"

using namespace amici;

void dJydy_model_robertson(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) {
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
realtype *x_tmp = nullptr;
if(x)
    x_tmp = N_VGetArrayPointer(x);
memset(tdata->dJydy,0,sizeof(realtype)*model->ny*model->nytrue*model->nJ);
int iy;
if(!amiIsNaN(edata->my[0* udata->nt+it])){
    iy = 0;
  tdata->dJydy[iy+(0+0*1)*model->nytrue] = 1.0/(tdata->sigmay[0]*tdata->sigmay[0])*(edata->my[it+udata->nt*0]*2.0-rdata->y[it + udata->nt*0]*2.0)*-5.0E-1;
}
if(!amiIsNaN(edata->my[1* udata->nt+it])){
    iy = 1;
  tdata->dJydy[iy+(0+1*1)*model->nytrue] = 1.0/(tdata->sigmay[1]*tdata->sigmay[1])*(edata->my[it+udata->nt*1]*2.0-rdata->y[it + udata->nt*1]*2.0)*-5.0E-1;
}
if(!amiIsNaN(edata->my[2* udata->nt+it])){
    iy = 2;
  tdata->dJydy[iy+(0+2*1)*model->nytrue] = 1.0/(tdata->sigmay[2]*tdata->sigmay[2])*(edata->my[it+udata->nt*2]*2.0-rdata->y[it + udata->nt*2]*2.0)*-5.0E-1;
}
return;

}

