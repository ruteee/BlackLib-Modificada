#include <iostream>
#include "PWM/PWM.h"
#include "ADC/Adc.h"
#include "unistd.h"



int main(int argc, char * argv[]){
	//ADC adc4(AINx::AIN4);
	PWM pwm(P9_21);
	pwm.setState(run);
	
	std::cout << "run value " << pwm.getState() << endl;
	while(true){
		//float dutyCycle  = adc4.getPercentValue();
		//std::cout << "Duty Value " << dutyCycle << endl;
		pwm.setPeriod(100000000);
		pwm.setDutyCycle(90000000);
		//std::cout << "run value " << pwm.getState() << endl;
		//std::cout << "dutyCycle " << pwm.getDutyCycle() << endl;
		 
	}
}
