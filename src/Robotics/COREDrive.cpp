#include "COREDrive.h"

#include "COREHardware.h"

using namespace CORE;

COREPID::PIDProfile *COREPID::getProfile(int profile) {
	switch(profile) {
	case 1:
		return &PID1;
		break;
	case 2:
		return &PID2;
		break;
	default:
		return &PID1;
		break;
	}
}
