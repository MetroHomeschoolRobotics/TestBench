/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendSetLamp.h"

SendSetLamp::SendSetLamp(PixyPort port, u_int8_t upper, u_int8_t lower) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(RobotMap::visionTracking.get());
  _port = port;
  _upper = upper;
  _lower = lower;
}

// Called just before this Command runs the first time
void SendSetLamp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendSetLamp::Execute() {
  RobotMap::visionTracking.get()->SetLamp(_port, _upper, _lower);
}

// Make this return true when this Command no longer needs to run execute()
bool SendSetLamp::IsFinished() { return true; }

// Called once after isFinished returns true
void SendSetLamp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendSetLamp::Interrupted() {}
