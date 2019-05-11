/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendGetResolution.h"

SendGetResolution::SendGetResolution(PixyPort port) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(RobotMap::visionTracking.get());
  _port = port;
}

// Called just before this Command runs the first time
void SendGetResolution::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendGetResolution::Execute() {
  RobotMap::visionTracking.get()->GetResolution(_port);
}

// Make this return true when this Command no longer needs to run execute()
bool SendGetResolution::IsFinished() { return true; }

// Called once after isFinished returns true
void SendGetResolution::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendGetResolution::Interrupted() {}
