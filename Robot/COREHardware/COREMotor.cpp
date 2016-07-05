#include "COREMotor.h"

using namespace CORE;
using namespace CORE::COREHardware;

COREMotor::COREMotor(int port, motorControllerType controllerType, controlMode controlMethod, double pProfile1Value, double iProfile1Value, double dProfile1Value, double pProfile2Value, double iProfile2Value, double dProfile2Value, int integralAccuracy):
	motorPID(pProfile1Value, iProfile1Value, dProfile1Value, pProfile2Value, iProfile2Value, dProfile2Value, integralAccuracy)
{
#ifndef SIMULATION
	if(motorControlType == CANTalonController) {
		static CANTalon CanTalonDevice(port);
		CANTalonDevice = &CanTalonDevice;
	}
#else

#endif
}
void COREMotor::Set(double speed) {
	motorSpeed = speed;
#ifndef SIMULATION
	if(motorControlType == CANTalonController) {
		CANTalonDevice->Set(speed);
	}
#endif
}
double COREMotor::Get() {
	return motorSpeed;
}
double COREMotor::getEncoderValue() {
#ifndef SIMULATION
	if(motorControlType == CANTalonController) {
		return CANTalonDevice->GetEncPosition();
	}
#else
	//TODO:Do a trapezoidal sum
#endif
	return -1;
}
void COREMotor::setControlMode(controlMode controlMethod) {
	motorControlMode = controlMethod;
}
COREMotor::controlMode COREMotor::getControlMode() {
	return motorControlMode;
}
void COREMotor::addSlave(COREMotor *slaveMotor) {

}
