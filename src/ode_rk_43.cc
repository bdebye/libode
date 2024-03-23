//! \file ode_rk_43.cc

#include "ode_rk_43.h"

namespace ode {

OdeRK43::OdeRK43 (unsigned long neq) :
    OdeEmbedded (neq, false, 3),
    OdeRK (neq, 5),
    OdeERK (neq) {

    method_ = "RK43";
    //tableau of coefficents
    c2 = 1.0/3; a21 =    c2;
    c3 = 2.0/3; a31 = -1./3; a32 =     1;
    c4 =   1.0; a41 =     1; a42 =    -1; a43 = 1;
    c5 =   1.0; a51 = 1.0/8; a52 = 3.0/8; a53 = 3.0/8; a54 = 1.0/8;
                b1 =  1.0/8; b2  = 3.0/8; b3 =  3.0/8; b4  = 1.0/8;
                d1 =  1./12; d2 =   1./2; d3  = 1.0/4;              d5  = 1./6;
}

void OdeRK43::step_ (double dt) {

    unsigned long i;

    //------------------------------------------------------------------
    ode_fun_(sol_, k_[0]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*a21*k_[0][i];
    ode_fun_(soltemp_, k_[1]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a31*k_[0][i]
                                                     + a32*k_[1][i]);
    ode_fun_(soltemp_, k_[2]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a41*k_[0][i]
                                                     + a42*k_[1][i]
                                                     + a43*k_[2][i]);
    ode_fun_(soltemp_, k_[3]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a51*k_[0][i]
                                                     + a52*k_[1][i]
                                                     + a53*k_[2][i]
                                                     + a54*k_[3][i]);
    ode_fun_(soltemp_, k_[4]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) {
        solemb_[i] = sol_[i] + dt*(d1*k_[0][i]
                                 + d2*k_[1][i]
                                 + d3*k_[2][i]
                                 + d5*k_[4][i]);
        sol_[i] = sol_[i] + dt*(b1*k_[0][i]
                              + b2*k_[1][i]
                              + b3*k_[2][i]
                              + b4*k_[3][i]);
    }
}

} // namespace ode
