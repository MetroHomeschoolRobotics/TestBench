/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FollowLine.h"

FollowLine::FollowLine(PixyPort port) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _port = port;
}

// Called just before this Command runs the first time
void FollowLine::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FollowLine::Execute() {
  LineFeatures* features = _visionTracking->GetMainFeatures(_port);
  if (features != nullptr){

  }
}

// Make this return true when this Command no longer needs to run execute()
bool FollowLine::IsFinished() { return false; }

// Called once after isFinished returns true
void FollowLine::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowLine::Interrupted() {}
