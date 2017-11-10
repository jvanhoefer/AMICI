
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/tdata.h>
#include <include/udata.h>
#include "model_robertson_dwdx.h"
#include "model_robertson_w.h"

using namespace amici;

void JSparseB_model_robertson(realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) {
TempData *tdata = (TempData*) user_data;
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
realtype *x_tmp = nullptr;
if(x)
    x_tmp = N_VGetArrayPointer(x);
realtype *dx_tmp = nullptr;
if(dx)
    dx_tmp = N_VGetArrayPointer(dx);
realtype *xB_tmp = nullptr;
if(xB)
    xB_tmp = N_VGetArrayPointer(xB);
realtype *dxB_tmp = nullptr;
if(dxB)
    dxB_tmp = N_VGetArrayPointer(dxB);
realtype *xBdot_tmp = nullptr;
if(xBdot)
    xBdot_tmp = N_VGetArrayPointer(xBdot);
  SparseSetMatToZero(JB);
  JB->indexvals[0] = 0;
  JB->indexvals[1] = 1;
  JB->indexvals[2] = 2;
  JB->indexvals[3] = 0;
  JB->indexvals[4] = 1;
  JB->indexvals[5] = 2;
  JB->indexvals[6] = 0;
  JB->indexvals[7] = 1;
  JB->indexvals[8] = 2;
  JB->indexptrs[0] = 0;
  JB->indexptrs[1] = 3;
  JB->indexptrs[2] = 6;
  JB->indexptrs[3] = 9;
w_model_robertson(t,x,dx,tdata);
dwdx_model_robertson(t,x,dx,user_data);
  JB->data[0] = cj+tdata->p[0];
  JB->data[1] = -tdata->dwdx[0];
  JB->data[2] = -tdata->dwdx[1];
  JB->data[3] = -tdata->p[0];
  JB->data[4] = cj+tdata->dwdx[0]+tdata->p[2]*x_tmp[1]*2.0;
  JB->data[5] = tdata->dwdx[1];
  JB->data[6] = -1.0;
  JB->data[7] = -1.0;
  JB->data[8] = -1.0;
return;

}

