/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FollowObject.h"

FollowObject::FollowObject(PixyPort port) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _port = port;
}

// Called just before this Command runs the first time
void FollowObject::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FollowObject::Execute() {
  FRCPixyBlock* block = _visionTracking->GetBlocks(_port, 1);
  if (block != nullptr){

  }
}

// Make this return true when this Command no longer needs to run execute()
bool FollowObject::IsFinished() { return false; }

// Called once after isFinished returns true
void FollowObject::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowObject::Interrupted() {}
