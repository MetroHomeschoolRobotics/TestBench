/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendSelectedI2CCommand.h"

SendSelectedI2CCommand::SendSelectedI2CCommand(OI *oi) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _oi.reset(oi);
}

// Called just before this Command runs the first time
void SendSelectedI2CCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SendSelectedI2CCommand::Execute() {
  Command* cmd = _oi.get()->getI2CChooser()->GetSelected();
  _selectedCommand.reset(cmd);
  cmd->Run();
}

// Make this return true when this Command no longer needs to run execute()
bool SendSelectedI2CCommand::IsFinished() { return true; }

// Called once after isFinished returns true
void SendSelectedI2CCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendSelectedI2CCommand::Interrupted() {}
