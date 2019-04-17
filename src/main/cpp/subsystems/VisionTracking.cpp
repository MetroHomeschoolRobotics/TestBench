/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/VisionTracking.h"

VisionTracking::VisionTracking() : Subsystem("VisionTracking") {
  
}

void VisionTracking::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  _pixySPI.reset(new FRCPixy2(frc::SPI::kOnboardCS0));
  _pixyI2C.reset(new FRCPixy2(frc::I2C::kOnboard , 0));
}

  FRCPixyVersion* VisionTracking::CheckVersion(PixyPort port) {
    return Resolve(port)->CheckVersion();
  }

	FRCPixyBlock* VisionTracking::GetBlocks(PixyPort port, int sigmap) {
    return Resolve(port)->GetBlocks(sigmap);
  }
 
	FRCPixyBlock* VisionTracking::GetBlocks(PixyPort port, int sigmap, int maxBlocks) {
    return Resolve(port)->GetBlocks(sigmap, maxBlocks);
  }
 
	void VisionTracking::SetServos(PixyPort port, uint16_t s0, uint16_t s1) {
    Resolve(port)->SetServos(s0, s1);
  }
 
	void VisionTracking::SetCameraBrightness(PixyPort port, uint8_t brightness) {
    Resolve(port)->SetCameraBrightness(brightness);
  }
 
	void VisionTracking::SetLED(PixyPort port, uint8_t r, uint8_t g, uint8_t b) {
    Resolve(port)->SetLED(r, g, b);
  }
 
	void VisionTracking::SetLamp(PixyPort port, uint8_t upper, uint8_t lower) {
    Resolve(port)->SetLamp(upper, lower);
  }
 
	uint8_t VisionTracking::GetResolution(PixyPort port) {
    return Resolve(port)->GetResolution();  
  }
 
	uint8_t VisionTracking::GetFPS(PixyPort port) {
    return Resolve(port)->GetFPS();
  }
 
	LineFeatures* VisionTracking::GetFeatures(PixyPort port, char type, char features, bool wait) {
    return Resolve(port)->GetFeatures(type, features, wait);
  }
 
	LineFeatures* VisionTracking::GetAllFeatures(PixyPort port) {
    return Resolve(port)->GetAllFeatures();
  }
 
	LineFeatures*VisionTracking:: GetMainFeatures(PixyPort port) {
    return Resolve(port)->GetMainFeatures();
  }
 
	void VisionTracking::SetLineMode(PixyPort port, int mode) {
    Resolve(port)->SetLineMode(mode);
  }
 
	void VisionTracking::SetNextTurn(PixyPort port, short angle) {
    Resolve(port)->SetNextTurn(angle);
  }
 
	void VisionTracking::SetDefaultTurn(PixyPort port, short angle) {
    Resolve(port)->SetDefaultTurn(angle);
  }
 
	void VisionTracking::SetVector(PixyPort port, int index) {
    Resolve(port)->SetVector(index);
  }
 
	void VisionTracking::ReverseVector(PixyPort port) {
    Resolve(port)->ReverseVector();
  }
 

 FRCPixy2* VisionTracking::Resolve(PixyPort port){
   if (port == PixyPort::I2C){
     return _pixyI2C.get();
   } else if (port == PixyPort::SPI){
     return _pixySPI.get();
   }
   return nullptr;
 }