#include <iostream>
#include "PWM/PWM.h"
#include "ADC/Adc.h"



int main(int argc, char * argv[]){
	//ADC adc4(AINx::AIN4);
	PWM pwm(P9_22);
	pwm.setState(run);
	
	while(true){
		//float dutyCycle  = adc4.getPercentValue();
		//std::cout << "Duty Value " << dutyCycle << endl;
		pwm.setPeriod(1000000);
		pwm.setDutyCycle(800000);
		std::cout << "run value " << pwm.getState() << endl;
		//std::cout << "Duty Cycle from ain " << pwm.getDutyValue() << endl; 
	}
}
