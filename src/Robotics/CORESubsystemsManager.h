#ifndef SRC_CORELIBRARY_CORESUBSYSTEMSMANAGER_H_
#define SRC_CORELIBRARY_CORESUBSYSTEMSMANAGER_H_

#include <vector>
#include <string>
#define quote(x)
using namespace std;
namespace CORE {

class CORESubsystem {
public:
	std::string name;
	CORESubsystem();
	virtual void robotInit() = 0;
	virtual void teleopInit() = 0;
	virtual void teleop() = 0;
	virtual void teleopEnd(){
		//TODO: Log -> Teleop end not implemented for: NAME
	}
};

class CORETask {
public:
	CORETask();
	virtual ~CORETask(){}
	virtual void robotInitTask();
	virtual void teleopInitTask();
	virtual void preTeleopTask();
	virtual void postTeleopTask();
	virtual void teleopEndTask();
};

class CORESubsystemsManager {
private:
	static vector<CORESubsystem*> subsystems;
	static vector<CORETask*> tasks;
public:
	static void addSubsystem(CORESubsystem* subsystem) {
		subsystems.push_back(subsystem);
		//TODO: Log -> SUBSYSTEMNAME added
	}
	static void robotInit() {
		for(auto subsystem : subsystems) {
			subsystem->teleopInit();
		}
		for(auto task : tasks) {
			task->robotInitTask();
		}
		//TODO: Log -> RobotInit Complete
	}
	static void teleopInit() {
		for(auto subsystem : subsystems) {
			subsystem->teleopInit();
		}
		for(auto task : tasks) {
			task->teleopInitTask();
		}
		//TODO: Log -> TeleopInit Complete
	}
	static void teleop() {
		for(auto task : tasks) {
			task->preTeleopTask();
		}
		for(auto subsystem : subsystems) {
			subsystem->teleop();
		}
		for(auto task : tasks) {
			task->postTeleopTask();
		}
	}
	static void teleopEnd() {
		for(auto task : tasks) {
			task->teleopEndTask();
		}
		for(auto* subsystem : subsystems) {
			subsystem->teleopEnd();
		}
		//TODO: Log -> TeleopEnd Complete
	}
	static void addTask(CORETask* task) {
		tasks.push_back(task);
	}
};
}
#endif
