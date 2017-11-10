#ifndef _am_model_nested_events_dsigma_ydp_h
#define _am_model_nested_events_dsigma_ydp_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

using namespace amici;

namespace amici {
class UserData;
class ReturnData;
class TempData;
class ExpData;
}

void dsigma_ydp_model_nested_events(realtype t, amici::TempData *tdata);


#endif /* _am_model_nested_events_dsigma_ydp_h */