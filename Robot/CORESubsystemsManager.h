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
	virtual void run();
};

class CORESubsystemsManager {
private:
	static vector<CORESubsystem*> subsystems;
	static vector<CORETask*> robotInitTasks;
	static vector<CORETask*> teleopInitTasks;
	static vector<CORETask*> teleopTasks;
	static vector<CORETask*> teleopEndTasks;
public:
	static void addSubsystem(CORESubsystem* subsystem) {
		subsystems.push_back(subsystem);
		//TODO: Log -> SUBSYSTEMNAME added
	}
	static void robotInit() {
		for(auto task : robotInitTasks) {
			task->run();
		}
		for(auto subsystem : subsystems) {
			subsystem->teleopInit();
		}
		//TODO: Log -> RobotInit Complete
	}
	static void teleopInit() {
		for(auto task : teleopInitTasks) {
			task->run();
		}
		for(CORESubsystem* subsystem : subsystems) {
			subsystem->teleopInit();
		}
		//TODO: Log -> TeleopInit Complete
	}
	static void teleop() {
		for(auto task : teleopTasks) {
			task->run();
		}
		for(CORESubsystem* subsystem : subsystems) {
			subsystem->teleop();
		}
	}
	void teleopEnd() {
		for(auto task : teleopEndTasks) {
			task->run();
		}
		for(CORESubsystem* subsystem : subsystems) {
			subsystem->teleopEnd();
		}
		//TODO: Log -> TeleopEnd Complete
	}
	static void addRobotInitTask(CORETask* task) {
		robotInitTasks.push_back(task);
	}
	static void addTeleopInitTask(CORETask* task) {
		teleopInitTasks.push_back(task);
	}
	static void addTeleopTask(CORETask* task) {
		teleopTasks.push_back(task);
	}
	static void addTeleopEndTask(CORETask* task) {
		teleopEndTasks.push_back(task);
	}
};
}
