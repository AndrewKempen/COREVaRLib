#ifndef SRC_CORELIBRARY_COREHARDWARE_COREMOTOR_H_
#define SRC_CORELIBRARY_COREHARDWARE_COREMOTOR_H_
#include <Robotics/COREPID.h>
#include <vector>

#include "../CORESubsystemsManager.h"

class CANTalon;
class Jaguar;
class Victor;

#ifndef SIMULATION
//#include "WPILib.h"
#endif

namespace CORE {
namespace COREHardware {
using namespace CORE;

template <class T>
class COREMotor : private CORETask {
public:
	std::shared_ptr<T> motor;
	std::shared_ptr<T> PIDController;
	enum controlMode {
		Voltage,
		Percentage,
		Current,
		VelPID,
		PosPID
	};
	COREMotor(int port, controlMode controlMethod = Voltage);
	COREMotor(int port, controlMode controlMethod = Voltage, double pProfile1Value = 0, double iProfile1Value = 0, double dProfile1Value = 0, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1);
	void Set(double speed);
	double Get();
	double getEncoderValue();
	void setControlMode(controlMode controlMethod);
	controlMode getControlMode();
	void addSlave(COREMotor *slaveMotor);
	void postTeleopTask();
private:
	double motorSpeed = 0;
	double lastTrapizodalSum = 0;
	COREMotor::controlMode motorControlMode;
	std::vector<COREMotor*> slaveMotors;
};

}
}
#endif
