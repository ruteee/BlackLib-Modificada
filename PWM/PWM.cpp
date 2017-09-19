#include "PWM.h"

PWM:PWM(pwmName pwmName)
{
	this->pwmName = pwmName;
	loadPWM();
	setPwmBoard()
}

void PWM::loadPWM()
{
	system("sudo sh -c \"echo 'cape-universaln' > /sys/devices/platform/bone_capemgr/slots\"");
	system("sudo sh -c \"echo 0 > " + PWM0_DIR;
	system("sudo sh -c \"echo 1 > " + PWM0_DIR); 

	system("sudo sh -c \"echo 0 > " + PWM1_DIR); 
	system("sudo sh -c \"echo 1 > " + PWM1_DIR );

	system("sudo sh -c \"echo 0 > " + PWM2_DIR);
	system("sudo sh -c \"echo 1 > " + PWM2_DIR); 
}


void PWM::setPwmBoard(){
	switch (this->pwmName){
		case 0:
			this.baseDIR = PWM2_DIR + "/pwm1";
			break;
		case 1:
			this.baseDIR = PWM2_DIR + "/pwm0";
			break;
		case 2:
			this.baseDIR = PWM1_DIR + "/pwm0";
			break;
		case 3:
			this.baseDIR = PWM1_DIR + "/pwm1";
			break;
		case 4:
			this.baseDIR = PWM0_DIR + "/pwm1";
			break;
		case 5:
			this.baseDIR = PWM0_DIR + "/pwm0";
			break;
		default:
			std::cout << "Pino invalido"
		
	}

}


void PWM::setPeriod(int period)
{
	fstream fs;
	fs.open(this->baseDIR + "/period", fstream::out);
	fs << period
	fs.close();
}

int PWM::getPeriod()
{
	float period;
	fstream fs;
	fs.open(this->baseDir.c_str(), fstream::in);
	fs >> retorno;
	fs.close();
	return retorno;
}

void PWM::setDutyCycle(int duty)
{
	fstream fs;
	fs.open(this->baseDIR + "/duty_cycle", fstream::out);
	fs << duty
	fs.close();
}

int PWM::getDutyCycle()
{
	int duty;
	fstream fs;
	fs.open(this->baseDir.c_str(), fstream::in);
	fs >> duty;
	fs.close();
	return retorno;
}

void PWM::setState(statePwm state)
{
	if (state == 0 || state == 1){
		fstream fs;
		fs.open(this->baseDIR + "/enable", fstream::out);
		fs << state
		fs.close();
	}
}

int PWM::getState()
{
	int state;
	fstream fs;
	fs.open(this->baseDir.c_str(), fstream::in);
	fs >> state;
	fs.close();
	return retorno;
}

