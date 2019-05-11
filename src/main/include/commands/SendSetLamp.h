/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "RobotMap.h"

class SendSetLamp : public frc::Command {
 private:
 PixyPort _port;
 u_int8_t _upper;
 u_int8_t _lower;
 public:
  SendSetLamp(PixyPort port, u_int8_t upper, u_int8_t lower);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
