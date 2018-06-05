# PID_controller
PID --- proportional, integral, derivative

## chapter 0:
    0-1 ~ 0-3

## chapter 1:

    1-1 ~ 1-9

## chapter 2:

    2-1 ~ 2-4



## proportional only

        u(t) = Kp * e(t)    error = setpoint - processValue;
                            output = K * error;
                    
        

## proportional + Integral

        u(t) = Kp * e(t) + Kt*∫e(t)dt           error: = setpoint - processValue;
        u(t) = Kp * e(t) + Ki*∑e(t)             Reset: = Reset + K/tau_i + Reset;
        u(t) = Kp * e(t) + Kt*∑{(K/†i)*e(t)}    output: = K * Error + Reset;


units of tuning constants

K - 
    Gain --------------> Dimensionless -> K*e(t)
    Proportional Band -> % of Span ------> e(t)/K

Tau_i -
    Seconds per Repeat ---> K/tau * sum(e(t))
    Repeats per Minute ---> K * tau * sum(e(t))


## proportional + Derivative

        u(t) = Kp * e(t) + Kd * de(t)/dt
        u(t) = K * [e(t) + 1/†d * de(t)/dt]
        u(t) = K * e(t) + K / †i * ∆e(t)        Error : = setpoint - processValue;

                                                output: = K * Error + K/tau_i * (Error - LatError);

                                                LastError := Error; // save for next scan


units of tuning constants

Tau_d -
    seconds per repeat ---> K/tau
    repeat per minute ---> k * tau



## proportional + Integral + Derivative

        u(t) = Kp * e(t) + Kt*∫e(t)dt + Kd * de(t)/dt

        Output = Proportional + Integral + Derivative
        Output = error now + errors past + error future

