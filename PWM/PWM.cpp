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
	sleep(2);
}


void PWM::setPwmBoard(){

	this->pwm0 = getPwmChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/");
	this->pwm1 = getPwmChipPath("/sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/");
	this->pwm2 = getPwmChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/");
	
	cout << this->pwm0 << endl;
	
	switch (this->pwmPin){
		case 0:
			this->baseDir = this->pwm2 + "/pwm1";
			system(("sudo sh -c 'echo 1 > " + this->pwm2 + "/export'").c_str()); 
			break;
		case 1:
			this->baseDir = this->pwm2 + "/pwm0";
			system(("sudo sh -c 'echo 0 > " + this->pwm2 + "/export'").c_str());	
			break;
		case 2:
			this->baseDir = this->pwm1 + "/pwm0";
			system(("sudo sh -c 'echo 0 > " + this->pwm1 + "/export'").c_str()); 
			break;
		case 3:
			this->baseDir = this->pwm1 + "/pwm1";
			system(("sudo sh -c 'echo 1 > " + this->pwm1 + "/export'").c_str());
			break;
		case 4:
			this->baseDir = this->pwm0 + "/pwm1";
			system(("sudo sh -c 'echo 1 > " + this->pwm0 + "/export'").c_str()); 
			break;
		case 5:
			this->baseDir = this->pwm0 + "/pwm0";
			system(("sudo sh -c 'echo 0 > " + this->pwm0 + "/export'").c_str());
			break;
		default:
			std::cout << "Pino invalido";
		
	}
	std::cout << this->baseDir << endl;
	system(("config-pin " + pwmMap[pwmPin] + " pwm").c_str());
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


string PWM::getPwmChipPath(std::string path){
	DIR *dir = opendir(path);
	struct dirent *entry;
	while (entry = readdir(dir)) {
        if (entry->d_type == DT_DIR) {
			return = entry->d_name;
		}
    }
}


