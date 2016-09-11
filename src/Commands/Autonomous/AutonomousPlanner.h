#ifndef AutonomousPlanner_H
#define AutonomousPlanner_H


#include <string> // Should work, despite the error
#include <map>

#include "../CommandBase.h"
#include "WPILib.h"


class AutonomousPlanner: public CommandBase
{
public:
	AutonomousPlanner(string, int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	string defense;
	int position;
	bool hasLoaded;

	map<int, int> encoderInfo;
	map<int, double> angleInfo;
	map<string, double> speedInfo;

	void InitInformation();
	void LoadDriveInfo(string, int);
};

#endif
