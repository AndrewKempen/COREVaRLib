#ifndef SRC_CORELIBRARY_COREHARDWARE_COREJOYSTICK_H_
#define SRC_CORELIBRARY_COREHARDWARE_COREJOYSTICK_H_
#include <vector>
#include "../CORESubsystemsManager.h"


#ifndef SIMULATION
#include "WPILib.h"
#endif

namespace CORE {
namespace COREHardware {
using namespace CORE;

class COREJoystick {
public:
	static enum Axis {
		LeftX,
		LeftY,
		RightX,
		RightY,
	};
	static enum Button {
		DPadN,
		DPadNE,
		DPadE,
		DPadSE,
		DPadS,
		DPadSW,
		DPadW,
		DPadNW,
		LeftStick,
		RightStick,
		Back,
		Logo,
		Start,
		Y,
		B,
		A,
		X,
		LeftButton,
		RightButton,
		LeftTrigger,
		RightTrigger
	};
	COREJoystick(int joystickNumber) :
		updateCacheTask()
	{

	}
	void UpdateCache();
	void RegisterAxis(Axis axis);
	void RegisterButton(Button button);
	double GetAxis(Axis axis);
	bool GetButton(Button button);
private:
	CORETask updateCacheTask;
};

}
}
#endif
