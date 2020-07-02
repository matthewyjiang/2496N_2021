#pragma once

template <typename T> int sgn(T val){
    return (T(0) < val) - (val < T(0));
}

class PidControl{
    public:
    double currentPosition;
    double error; //position
    double integral; //absement
    double derivative; //velocity
    double dsmooth;
    double last_error;
    int i_limit;
    int i_bound;

    double kP, kI, kD;
    double f_kP, f_kI, f_kD;

    double target;
    int   max_mV           = 12000;
    long  clock_last;
    long  dt;

    int   temp_output;
    int   output;
    int   slew_output;

    bool slewOverrideEnable = false;
    bool emaEnable  = true;

    double slewError;
    double slewRate;

    PidControl(double p, double i, double d, int iLimit);

    void pidInit(double p, double i, double d, int iLimit);

    void pidInit(PidControl pid);

    void resetConstants();

    void slewOverride();

    void moveTo();

    void reset_variables();

    void reset_integral();
};

extern PidControl chassisStraight;
extern PidControl chassisTurn;



