#include "subsystems/Positioning.h"
#include "RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
}

void Positioning::UpdateDashboard(){
/*	
	frc::SmartDashboard::PutNumber("Front Left", GetFrontLeftDistance());
	frc::SmartDashboard::PutNumber("Front Right", GetFrontRightDistance());
	frc::SmartDashboard::PutNumber("Rear Left", GetRearLeftDistance());
	frc::SmartDashboard::PutNumber("Rear Right", GetRearRightDistance());
*/
}


void Positioning::InitDefaultCommand() {
}

