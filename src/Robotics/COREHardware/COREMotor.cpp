#include "COREMotor.h"

namespace CORE {
namespace COREHardware {

template<>
COREMotor<CANTalon>::COREMotor(int port, controlMode controlMethod):
	motorControlMode(controlMethod)

{
#ifndef SIMULATION
	motor = new CANTalon(port);
#else

#endif
}

template<>
COREMotor<CANTalon>::COREMotor(int port, controlMode controlMethod = Voltage, double pProfile1Value = 0, double iProfile1Value = 0, double dProfile1Value = 0, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1):
	motorControlMode(controlMethod)
{
#ifndef SIMULATION
	COREPID::PIDType PIDControllerType = motorControlMode == PosPID ? COREPID::PIDType::Pos : COREPID::PIDType::Vel;
	motor = new CANTalon(port);
	PIDController = new COREPID(PIDControllerType, pProfile1Value, iProfile1Value, dProfile1Value, pProfile2Value, iProfile2Value, dProfile2Value, integralAccuracy);

#else

#endif
}

template<>
COREMotor<Jaguar>::COREMotor(int port, controlMode controlMethod):
	motorControlMode(controlMethod)

{
#ifndef SIMULATION
	motor = new Jaguar(port);
#else

#endif
}

template<>
COREMotor<Victor>::COREMotor(int port, controlMode controlMethod):
	motorControlMode(controlMethod)

{
#ifndef SIMULATION
	motor = new Victor(port);
#else

#endif
}

template<class T>
void COREMotor<T>::Set(double speed) {
	if(motorControlMode <= Current) {
		motorSpeed = speed;
	}
	else {

	}
}

template<class T>
double COREMotor<T>::Get() {
	return motorSpeed;
}

template<>
double COREMotor<CANTalon>::getEncoderValue() {
#ifndef SIMULATION
	return motor->GetEncPosition();
#else
	//TODO:Do a trapezoidal sum
#endif
	return -1;
}

template<class T>
void COREMotor<T>::setControlMode(controlMode controlMethod) {
	motorControlMode = controlMethod;
}

template<class T>
COREMotor<T>::controlMode COREMotor<T>::getControlMode() {
	return motorControlMode;
}

template<class T>
void COREMotor<T>::addSlave(COREMotor *slaveMotor) {
	slaveMotors.push_back(slaveMotor);
}

template<>
void COREMotor<CANTalon>::postTeleopTask() {
#ifndef SIMULATION
	for(auto motor : slaveMotors) {
		motor->Set(motorSpeed);
	}
	motor->Set(motorSpeed);
#endif
	motorSpeed = 0;
}

template<>
void COREMotor<Jaguar>::postTeleopTask() {
#ifndef SIMULATION
	for(auto motor : slaveMotors) {
		motor->Set(motorSpeed);
	}
	motor->Set(motorSpeed);
#endif
	motorSpeed = 0;
}
}
}
