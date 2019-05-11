/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "OI.h"

class SendSelectedSPICommand : public frc::Command {
private:
 std::unique_ptr<OI> _oi;
 std::unique_ptr<frc::Command> _selectedCommand;
public:
  SendSelectedSPICommand(OI *oi);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
