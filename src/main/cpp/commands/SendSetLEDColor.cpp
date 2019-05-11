/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendSetLEDColor.h"

SendSetLEDColor::SendSetLEDColor(PixyPort port, u_int8_t red, u_int8_t green, uint8_t blue) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(RobotMap::visionTracking.get());
  _red = red;
  _green = green;
  _blue = blue;
  _port = port;
}

// Called just before this Command runs the first time
void SendSetLEDColor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendSetLEDColor::Execute() {
  RobotMap::visionTracking.get()->SetLED(_port, _red, _green, _blue);
}

// Make this return true when this Command no longer needs to run execute()
bool SendSetLEDColor::IsFinished() { return true; }

// Called once after isFinished returns true
void SendSetLEDColor::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendSetLEDColor::Interrupted() {}
