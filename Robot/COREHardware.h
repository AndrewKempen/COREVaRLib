#ifndef SRC_CORELIBRARY_COREHARDWARE_H_
#define SRC_CORELIBRARY_COREHARDWARE_H_
#include <vector>

#include "COREPID.h"
#include "WPILIB.h"

namespace CORE {
namespace COREHardware {
bool SIMULATION = true;

class COREMotor : COREPID {
private:

public:
	enum motorControllerType {
		CANTalon
	};
	enum controlMode {
		Voltage,
		Percentage,
		Current,
		Slave,
		VelocityPID,
		PositionalPID
	};
	COREMotor(int port, motorControllerType controllerType = CANTalon, controlMode controlMethod = Voltage, double pProfile1Value = 0, double iProfile1Value = 0, double dProfile1Value = 0, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1);
	void Set(double speed);
	double Get();
	void setEncoderType();
	double getEncoderValue();
	void setControlMode(controlMode controlMethod);
	controlMode getControlMode();
	void addSlave(COREMotor *slaveMotor);
};
}
}
#endif
