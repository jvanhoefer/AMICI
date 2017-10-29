#ifndef AMICI_STEADYSTATEPROBLEM_H
#define AMICI_STEADYSTATEPROBLEM_H

#include "include/amici_defines.h"
#include <sundials/sundials_nvector.h>

namespace amici {

class UserData;
class TempData;
class ReturnData;
class ExpData;
class Solver;
class Model;
class NewtonSolver;

/**
 * @brief The SteadystateProblem class solves a steady-state problem using
 * Newton's method and falls back to integration on failure.
 */

class SteadystateProblem {
  public:
    static void workSteadyStateProblem(const UserData *udata, TempData *tdata,
                                      ReturnData *rdata, Solver *solver,
                                      Model *model, int it);

    /**
     * applyNewtonsMethod applies Newtons method to the current state x to
     * find the steady state
     */
    static void applyNewtonsMethod(const UserData *udata, ReturnData *rdata,
                                  TempData *tdata, Model *model,
                                  NewtonSolver *newtonSolver, int newton_try);

    static void getNewtonOutput(TempData *tdata, ReturnData *rdata,
                                Model *model, int newton_status,
                                double run_time, int it);

    static void getNewtonSimulation(const UserData *udata, TempData *tdata,
                                   ReturnData *rdata, Solver *solver,
                                   Model *model, int it);
  private:
    SteadystateProblem();
};

} // namespace amici
#endif // STEADYSTATEPROBLEM_H
