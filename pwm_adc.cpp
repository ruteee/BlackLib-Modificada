#include <iostream>
#include "PWM/PWM.h"
#include "ADC/Adc.h"
#include "unistd.h"



int main(int argc, char * argv[]){
	ADC adc0(AINx::AIN0);
	PWM pwm(P9_21);
	pwm.setState(run);
	int period = 100000000;
	
	std::cout << "run value " << pwm.getState() << endl;
	while(true){
		int dutyCycle  = adc0.getIntValue();
		std::cout << "Duty Value " << dutyCycle << endl;
		pwm.setPeriod(period);
		pwm.setDutyCycle(period*dutyCycle/100.0);		 
	}
	return 0;
}
