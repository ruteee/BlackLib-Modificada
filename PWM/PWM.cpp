#include "PWM.h"

PWM::PWM(pwmName pinName)
{
	this->pwmPin = pinName;
	loadPWM();
	setPwmBoard();
}

void PWM::loadPWM()
{
	system("sudo sh -c \"echo 'cape-universaln' > /sys/devices/platform/bone_capemgr/slots\"");
	
	system(("sudo sh -c \"echo 0 > " + PWM0_DIR).c_str());
	system(("sudo sh -c \"echo 1 > " + PWM0_DIR).c_str()); 

	system(("sudo sh -c \"echo 0 > " + PWM1_DIR).c_str()); 
	system(("sudo sh -c \"echo 1 > " + PWM1_DIR).c_str());

	system(("sudo sh -c \"echo 0 > " + PWM2_DIR).c_str());
	system(("sudo sh -c \"echo 1 > " + PWM2_DIR).c_str()); 
}


void PWM::setPwmBoard(){
	switch (this->pwmPin){
		case 0:
			this->baseDir = PWM2_DIR + "/pwm1";
			break;
		case 1:
			this->baseDir = PWM2_DIR + "/pwm0";
			break;
		case 2:
			this->baseDir = PWM1_DIR + "/pwm0";
			break;
		case 3:
			this->baseDir = PWM1_DIR + "/pwm1";
			break;
		case 4:
			this->baseDir = PWM0_DIR + "/pwm1";
			break;
		case 5:
			this->baseDir = PWM0_DIR + "/pwm0";
			break;
		default:
			std::cout << "Pino invalido";
		
	}
	

}


void PWM::setPeriod(int period)
{
	std::fstream fs;
	fs.open(this->baseDir + "/period", fstream::out);
	fs << period;
	fs.close();
}

int PWM::getPeriod()
{
	float period;
	std::fstream fs;
	fs.open(this->baseDir + "/period", fstream::in);
	fs >> period;
	fs.close();
	return period;
}

void PWM::setDutyCycle(int duty)
{
	std::fstream fs;
	fs.open(this->baseDir + "/duty_cycle", fstream::out);
	fs << duty;
	fs.close();
}

int PWM::getDutyCycle()
{
	int duty;
	std::fstream fs;
	fs.open(this->baseDir + "/duty_cycle", fstream::in);
	fs >> duty;
	fs.close();
	return duty;
}

void PWM::setState(statePwm state)
{
	if (state == 0 || state == 1){
		std::fstream fs;
		fs.open(this->baseDir + "/enable", fstream::out);
		fs << state;
		fs.close();
		std::cout << this->baseDir + "/enable";
	}
}

int PWM::getState()
{
	int state;
	std::fstream fs;
	fs.open(this->baseDir + "/enable", fstream::in);
	fs >> state;
	fs.close();
	return state;
}

