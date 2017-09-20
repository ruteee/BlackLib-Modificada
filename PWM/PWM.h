#ifndef PWM_H_
#define PWM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <experimental/filesystem>
#include <unistd.h>
#include <dirent.h>



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

const std::string pwmMap[6] = {
				"P8.13",
				"P9.19",
				"P9.14",
				"P9.16",
				"P9.21",
				"P9.22",
				};

class PWM {

	private:
		int pwmPin;
		string pwm0;
		string pwm1;
		string pwm2;
		string baseDir;
		void loadPWM();
		void setPwmBoard();
		string getPwmChipPath(std::string path);

	public:
		PWM(pwmName pinName);
		int getPeriod();
		void setPeriod(int period);
		
		int getDutyCycle();
		void setDutyCycle(int duty);

		int getState();	
		void setState(statePwm state);
		

		

};
#endif 
