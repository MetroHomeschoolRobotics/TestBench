/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../pixy2/FRCPixy2.h"

  enum PixyPort {
    SPI,
    I2C
  };

class VisionTracking : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  std::shared_ptr<FRCPixy2> _pixySPI;
  std::shared_ptr<FRCPixy2> _pixyI2C;

  FRCPixy2* Resolve(PixyPort port);

 public:
  VisionTracking();
  void InitDefaultCommand() override;


  virtual FRCPixyVersion* CheckVersion(PixyPort port);
	virtual FRCPixyBlock* GetBlocks(PixyPort port, int sigmap);
	virtual FRCPixyBlock* GetBlocks(PixyPort port, int sigmap, int maxBlocks);
	void SetServos(PixyPort port, uint16_t s0, uint16_t s1);
	void SetCameraBrightness(PixyPort port, uint8_t brightness);
	void SetLED(PixyPort port, uint8_t r, uint8_t g, uint8_t b);
	void SetLamp(PixyPort port, uint8_t upper, uint8_t lower);
	uint8_t GetResolution(PixyPort port);
	uint8_t GetFPS(PixyPort port);
	LineFeatures* GetFeatures(PixyPort port, char type, char features, bool wait);
	LineFeatures* GetAllFeatures(PixyPort port);
	LineFeatures* GetMainFeatures(PixyPort port);
	void SetLineMode(PixyPort port, u_int8_t mode);
	void SetNextTurn(PixyPort port, short angle);
	void SetDefaultTurn(PixyPort port, short angle);
	void SetVector(PixyPort port, u_int8_t index);
	void ReverseVector(PixyPort port);
};
