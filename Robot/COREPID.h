#ifndef SRC_CORELIBRARY_COREPID_H_
#define SRC_CORELIBRARY_COREPID_H_
#include <vector>
#include "WPILIB.h"
#include "../navx2.0/AHRS.h"

namespace CORE {
class COREPID {
private:
	enum inputDeviceType {
		NoInput,
		CANTalonInput,
		AHRSInput
	};
	enum outputDeviceType {
		NoOutput,
		CANTalonOutput
	};
	struct PIDProfile {
		double P,I,D,porportional,integral,derivative,output;
		std::vector<double> mistake;
	}PID1, PID2;
	double setPointValue,actualPosition;
	bool calculated,enabled = false;
	Timer timer;
	CANTalon *inputCANTalonDevice;
	AHRS *inputGyro;
	CANTalon *outputMotor;
	inputDeviceType inputDevice;
	outputDeviceType outputDevice;
	PIDProfile *getProfile(int profile);
public:
	COREPID(double pProfile1Value, double iProfile1Value, double dProfile1Value, double pProfile2Value = 0, double iProfile2Value = 0, double dProfile2Value = 0, int integralAccuracy = 1);
	double calculate(int profile = 1);
	double calculate(double newSetpoint, int profile = 1);
	void setPoint(double setPoint);
	void setActualPosition(double actualPosition);
	void bindInputDevice(CANTalon * CANTalonInput, CANTalon::FeedbackDevice inputDevice);
	void bindInputDevice(AHRS * gyro);
	void bindOutputDevice(CANTalon * motor);
	double getSetPoint();
	double getP(int profile = 1);
	double getI(int profile = 1);
	double getD(int profile = 1);
	void setProfile(int profile);
	void setP(double value, int profile = 1);
	void setI(double value, int profile = 1);
	void setD(double value, int profile = 1);
	double getOutput(int profile = 1);
	double getPorportional(int profile = 1);
	double getIntegral(int profile = 1);
	double getDerivative(int profile = 1);
};
}
#endif
