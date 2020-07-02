#include "main.h"
#include "pidcontrol.h"

PidControl::PidControl(double p, double i, double d, int iLimit){
    f_kP = kP = p;
    f_kI = kI = i;
    f_kD = kD = d;
    i_limit = iLimit;
}

void PidControl::pidInit(double p, double i, double d, int iLimit){
    kP = p;
    kI = i;
    kD = d;
    i_limit = iLimit;
}

void PidControl::pidInit(PidControl pid){
    kP = pid.kP;
    kI = pid.kI;
    kD = pid.kD;
    i_limit = pid.i_limit;
}

void PidControl::resetConstants(){
    kP = f_kP; 
    kI = f_kI;
    kD = f_kD;
}

void PidControl::slewOverride(){
    slewError = output - slew_output;

    if(fabs(slewError) >= slewRate)
    {
        slew_output += sgn(slewError)*slewRate;
    }
    else
    {
        slew_output += slewError;
    }
    if(abs(output) > abs(slew_output))
    {
        output = slew_output;
    }
}

void PidControl::moveTo(){
    dt = pros::c::millis() - clock_last;
    clock_last = pros::c::millis();

    error = target - currentPosition;
    if(fabs(error) < i_bound && fabs(error) > 0){
        if(fabs(integral) < i_limit)
            integral += error*(dt/20);
        else{
            integral = sgn(integral)*i_limit;
        }
    }
    else{
        integral = 0;
    }
    derivative = (error - last_error)*(20/dt);
    dsmooth = (3*dsmooth + derivative)/4;
    last_error = error;

    temp_output = kP*error + kI*integral + kD*(emaEnable?dsmooth:derivative);

    output = std::clamp(temp_output, -max_mV, max_mV);

    if(slewOverrideEnable){
        slewOverride();
    }
}

void PidControl::reset_variables(){
    currentPosition = 0;
    error           = 0;
    integral        = 0;
    derivative      = 0;
    last_error      = 0;
    temp_output     = 0;
    output          = 0;
    slew_output     = 0;
    slewError       = 0;
}

void PidControl::reset_integral(){
    integral = 0;
}