/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "RobotMap.h"

class SendSetLEDColor : public frc::Command {
 private:
 PixyPort _port;
 u_int8_t _red;
 u_int8_t _green;
 u_int8_t _blue;
 public:
  SendSetLEDColor(PixyPort port, u_int8_t red, u_int8_t green, uint8_t blue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
