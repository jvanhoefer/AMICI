
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include "model_jakstat_adjoint_o2_w.h"

int dydx_model_jakstat_adjoint_o2(realtype t, int it, N_Vector x, void *user_data, TempData *tdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
status = w_model_jakstat_adjoint_o2(t,x,NULL,user_data);
  tdata->dydx[0+1*54] = udata->p[13]/udata->p[4];
  tdata->dydx[0+2*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[1+0*54] = udata->p[12]/udata->p[4];
  tdata->dydx[1+1*54] = udata->p[12]/udata->p[4];
  tdata->dydx[1+2*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[3+10*54] = udata->p[13]/udata->p[4];
  tdata->dydx[3+11*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[4+9*54] = udata->p[12]/udata->p[4];
  tdata->dydx[4+10*54] = udata->p[12]/udata->p[4];
  tdata->dydx[4+11*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[6+19*54] = udata->p[13]/udata->p[4];
  tdata->dydx[6+20*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[7+18*54] = udata->p[12]/udata->p[4];
  tdata->dydx[7+19*54] = udata->p[12]/udata->p[4];
  tdata->dydx[7+20*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[9+28*54] = udata->p[13]/udata->p[4];
  tdata->dydx[9+29*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[10+27*54] = udata->p[12]/udata->p[4];
  tdata->dydx[10+28*54] = udata->p[12]/udata->p[4];
  tdata->dydx[10+29*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[12+37*54] = udata->p[13]/udata->p[4];
  tdata->dydx[12+38*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[13+36*54] = udata->p[12]/udata->p[4];
  tdata->dydx[13+37*54] = udata->p[12]/udata->p[4];
  tdata->dydx[13+38*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[15+1*54] = -1.0/(udata->p[4]*udata->p[4])*udata->p[13];
  tdata->dydx[15+2*54] = 1.0/(udata->p[4]*udata->p[4])*udata->p[13]*-2.0;
  tdata->dydx[15+46*54] = udata->p[13]/udata->p[4];
  tdata->dydx[15+47*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[16+0*54] = -1.0/(udata->p[4]*udata->p[4])*udata->p[12];
  tdata->dydx[16+1*54] = -1.0/(udata->p[4]*udata->p[4])*udata->p[12];
  tdata->dydx[16+2*54] = 1.0/(udata->p[4]*udata->p[4])*udata->p[12]*-2.0;
  tdata->dydx[16+45*54] = udata->p[12]/udata->p[4];
  tdata->dydx[16+46*54] = udata->p[12]/udata->p[4];
  tdata->dydx[16+47*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[18+55*54] = udata->p[13]/udata->p[4];
  tdata->dydx[18+56*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[19+54*54] = udata->p[12]/udata->p[4];
  tdata->dydx[19+55*54] = udata->p[12]/udata->p[4];
  tdata->dydx[19+56*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[21+64*54] = udata->p[13]/udata->p[4];
  tdata->dydx[21+65*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[22+63*54] = udata->p[12]/udata->p[4];
  tdata->dydx[22+64*54] = udata->p[12]/udata->p[4];
  tdata->dydx[22+65*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[24+73*54] = udata->p[13]/udata->p[4];
  tdata->dydx[24+74*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[25+72*54] = udata->p[12]/udata->p[4];
  tdata->dydx[25+73*54] = udata->p[12]/udata->p[4];
  tdata->dydx[25+74*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[27+82*54] = udata->p[13]/udata->p[4];
  tdata->dydx[27+83*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[28+81*54] = udata->p[12]/udata->p[4];
  tdata->dydx[28+82*54] = udata->p[12]/udata->p[4];
  tdata->dydx[28+83*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[30+91*54] = udata->p[13]/udata->p[4];
  tdata->dydx[30+92*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[31+90*54] = udata->p[12]/udata->p[4];
  tdata->dydx[31+91*54] = udata->p[12]/udata->p[4];
  tdata->dydx[31+92*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[33+100*54] = udata->p[13]/udata->p[4];
  tdata->dydx[33+101*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[34+99*54] = udata->p[12]/udata->p[4];
  tdata->dydx[34+100*54] = udata->p[12]/udata->p[4];
  tdata->dydx[34+101*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[36+109*54] = udata->p[13]/udata->p[4];
  tdata->dydx[36+110*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[37+108*54] = udata->p[12]/udata->p[4];
  tdata->dydx[37+109*54] = udata->p[12]/udata->p[4];
  tdata->dydx[37+110*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[39+118*54] = udata->p[13]/udata->p[4];
  tdata->dydx[39+119*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[40+0*54] = 1.0/udata->p[4];
  tdata->dydx[40+1*54] = 1.0/udata->p[4];
  tdata->dydx[40+2*54] = 2.0/udata->p[4];
  tdata->dydx[40+117*54] = udata->p[12]/udata->p[4];
  tdata->dydx[40+118*54] = udata->p[12]/udata->p[4];
  tdata->dydx[40+119*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[42+1*54] = 1.0/udata->p[4];
  tdata->dydx[42+2*54] = 2.0/udata->p[4];
  tdata->dydx[42+127*54] = udata->p[13]/udata->p[4];
  tdata->dydx[42+128*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[43+126*54] = udata->p[12]/udata->p[4];
  tdata->dydx[43+127*54] = udata->p[12]/udata->p[4];
  tdata->dydx[43+128*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[45+136*54] = udata->p[13]/udata->p[4];
  tdata->dydx[45+137*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[46+135*54] = udata->p[12]/udata->p[4];
  tdata->dydx[46+136*54] = udata->p[12]/udata->p[4];
  tdata->dydx[46+137*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[48+145*54] = udata->p[13]/udata->p[4];
  tdata->dydx[48+146*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[49+144*54] = udata->p[12]/udata->p[4];
  tdata->dydx[49+145*54] = udata->p[12]/udata->p[4];
  tdata->dydx[49+146*54] = (udata->p[12]*2.0)/udata->p[4];
  tdata->dydx[51+154*54] = udata->p[13]/udata->p[4];
  tdata->dydx[51+155*54] = (udata->p[13]*2.0)/udata->p[4];
  tdata->dydx[52+153*54] = udata->p[12]/udata->p[4];
  tdata->dydx[52+154*54] = udata->p[12]/udata->p[4];
  tdata->dydx[52+155*54] = (udata->p[12]*2.0)/udata->p[4];
return(status);

}

