
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include "model_jakstat_adjoint_w.h"

int dsigma_ydp_model_jakstat_adjoint(realtype t, void *user_data, TempData *tdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
int ip;
memset(tdata->dsigmaydp,0,sizeof(realtype)*3*udata->nplist);
for(ip = 0; ip<udata->nplist; ip++) {
switch (udata->plist[ip]) {
  case 14: {
  tdata->dsigmaydp[ip*udata->ny + 0] = 1.0;

  } break;

  case 15: {
  tdata->dsigmaydp[ip*udata->ny + 1] = 1.0;

  } break;

  case 16: {
  tdata->dsigmaydp[ip*udata->ny + 2] = 1.0;

  } break;

}
}
return(status);

}

