#ifndef Positioning_H
#define Positioning_H

#include "frc/Commands/Subsystem.h"
//#include "../LidarV3.h"
#include "frc/WPILib.h"
#include <iostream>
#include <fstream>
#include "RobotMap.h"
using namespace std;


class Positioning : public frc::Subsystem {

private:


public:
	Positioning();
	void UpdateDashboard();
	void InitDefaultCommand();
};

#endif  // Positioning_H
