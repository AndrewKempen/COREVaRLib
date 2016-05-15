#include <vector>
#include <string>
#define quote(x)

namespace CORE {
class CORESubsystem;

class CORESubsystemsManager {
private:
	static std::vector<CORESubsystem*> subsystems;
public:
	static void addSubsystem(CORESubsystem* subsystem);
	static void robotInit();
	static void teleopInit();
	static void teleop();
	static void teleopEnd();
};

class CORESubsystem {
public:
	std::string name;
	CORESubsystem() {
		name = std::string(quote(this));
		CORESubsystemsManager::addSubsystem(this);
	}
	virtual void robotInit() = 0;
	virtual void teleopInit() = 0;
	virtual void teleop() = 0;
	virtual void teleopEnd(){
		//Teleop end not implemented for:  + name
	}
};
}
