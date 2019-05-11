/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SendSelectedSPICommand.h"

SendSelectedSPICommand::SendSelectedSPICommand(OI *oi) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _oi.reset(oi);
}

// Called just before this Command runs the first time
void SendSelectedSPICommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SendSelectedSPICommand::Execute() {
  Command* cmd = _oi.get()->getSPIChooser()->GetSelected();
  cmd->Run();
}

// Make this return true when this Command no longer needs to run execute()
bool SendSelectedSPICommand::IsFinished() { return true; }

// Called once after isFinished returns true
void SendSelectedSPICommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendSelectedSPICommand::Interrupted() {}
