#include <iostream>
#include "PWM/PWM.h"
#include "ADC/Adc.h"
#include "unistd.h"

int main(int argc, char * argv[]){
	ADC adc(AINx::AIN0);
	PWM pwm(P9_21);
	pwm.setState(run);
	
	std::cout << "run value " << pwm.getState() << endl;
	while(true){
		float dutyCycle  = adc.getPercentValue();
		std::cout << "Duty Value " << dutyCycle << endl;
		int period = 1000000000;		
		pwm.setPeriod(period);
		pwm.setDutyCycle(dutyCycle*period/100.0);
		//std::cout << "dutyCycle " << pwm.getDutyCycle() << endl;
		 
	}
	
	return 0;
}
