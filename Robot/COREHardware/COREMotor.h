#ifndef SRC_CORELIBRARY_COREHARDWARE_COREMOTOR_H_
#define SRC_CORELIBRARY_COREHARDWARE_COREMOTOR_H_
#include <vector>
#include "../COREPID.h"

class CANTalon;

#ifndef SIMULATION
#include "WPILib.h"
#endif

namespace CORE {
namespace COREHardware {
using namespace CORE;

class COREMotor : COREPID {
public:
	CANTalon * CANTalonDevice;
	enum motorControllerType {
		CANTalonController
	};
	enum controlMode {
		Voltage,
		Percentage,
		Current,
		Slave,
		VelocityPID,
		PositionalPID
	};
	COREMotor(int port, motorControllerType controllerType = CANTalonController, controlMode controlMethod = Voltage, double pProfile1Value = 0, double iProfile1Value = 0, double dProfile1Value = 0, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1);
	void Set(double speed);
	double Get();
	double getEncoderValue();
	void setControlMode(controlMode controlMethod);
	controlMode getControlMode();
	void addSlave(COREMotor *slaveMotor);
private:
	COREPID motorPID;
	double motorSpeed;
	int motorPort;
	double lastTrapizodalSum = 0;
	COREMotor::controlMode motorControlMode;
	motorControllerType motorControlType;
};

}
}
#endif
