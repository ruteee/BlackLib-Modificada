#ifndef PWM_H_
#define PWM_H_

#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<sstream>

#endif 

const string PWM0_DIR "/sys/devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/*\"";
const string PWM1_DIR "/sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/*\"";
const strinf PWM2_DIR "/sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/*\"";

using namespace std;

enum pwmName            {   P8_13                   = 0,
                                P8_19                   = 1,
                                P9_14                   = 2,
                                P9_16                   = 3,
                                P9_21                   = 4,
                                P9_22                   = 5,
                                
                                EHRPWM2B                = P8_13,
                                EHRPWM2A                = P8_19,
                                EHRPWM1A                = P9_14,
                                EHRPWM1B                = P9_16,
                                EHRPWM0B                = P9_21,
                                EHRPWM0A                = P9_22,
                            };


enum statePwm { run = 1, stop = 0,};


class PWM {

	private:
		int pinName;
		string baseDir;
		void loadPWM();
		void setPwmBoard();

	public:
		PWM(pwmName pinName);
		int getPeriod();
		void setPeriod(int period);
		
		int getDutyCycle();
		void setDutyCycle(int duty);

		int getState()		
		void setState(statePwm state);
		

		

};
