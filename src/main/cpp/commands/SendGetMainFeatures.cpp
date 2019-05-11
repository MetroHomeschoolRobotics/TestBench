/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendGetMainFeatures.h"

SendGetMainFeatures::SendGetMainFeatures(PixyPort port) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(RobotMap::visionTracking.get());
  _port = port;
}

// Called just before this Command runs the first time
void SendGetMainFeatures::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendGetMainFeatures::Execute() {
  RobotMap::visionTracking.get()->GetMainFeatures(_port);
}

// Make this return true when this Command no longer needs to run execute()
bool SendGetMainFeatures::IsFinished() { return true; }

// Called once after isFinished returns true
void SendGetMainFeatures::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendGetMainFeatures::Interrupted() {}
