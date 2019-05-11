/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendSetCameraBrightness.h"

SendSetCameraBrightness::SendSetCameraBrightness(PixyPort port, u_int8_t brightness) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(RobotMap::visionTracking.get());
  _port = port;
  _brightness = brightness;
}

// Called just before this Command runs the first time
void SendSetCameraBrightness::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendSetCameraBrightness::Execute() {
  RobotMap::visionTracking.get()->SetCameraBrightness(_port, _brightness);
}

// Make this return true when this Command no longer needs to run execute()
bool SendSetCameraBrightness::IsFinished() { return true; }

// Called once after isFinished returns true
void SendSetCameraBrightness::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendSetCameraBrightness::Interrupted() {}
