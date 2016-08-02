#include "../Robotics/CORESubsystemsManager.h"

using namespace CORE;

CORESubsystem::CORESubsystem() {
	name = string(quote(this));
	CORESubsystemsManager::addSubsystem(this);
}
CORETask::CORETask() {
	CORESubsystemsManager::addTask(this);
}

vector<CORESubsystem*> CORESubsystemsManager::subsystems;
