#include "CORESubsystemsManager.h"

using namespace CORE;

void CORESubsystemsManager::addSubsystem(CORESubsystem* subsystem) {
	subsystems.push_back(subsystem);
}
void CORESubsystemsManager::robotInit() {
	for (CORESubsystem* subsystem : subsystems) {
		subsystem->robotInit();
	}
}
void CORESubsystemsManager::teleopInit() {
	for (CORESubsystem* subsystem : subsystems) {
		subsystem->teleopInit();
	}
}
void CORESubsystemsManager::teleop() {
	for (CORESubsystem* subsystem : subsystems) {
		subsystem->teleop();
	}
}
void CORESubsystemsManager::teleopEnd() {
	for (CORESubsystem* subsystem : subsystems) {
		subsystem->teleopEnd();
	}
}
