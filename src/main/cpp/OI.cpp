/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/Drive.h"
#include "commands/SendCheckVersion.h"
#include "commands/SendGetAllFeatures.h"
#include "commands/SendGetBlocks.h"
#include "commands/SendGetFPS.h"
#include "commands/SendGetMainFeatures.h"
#include "commands/SendGetResolution.h"
#include "commands/SendReverseVector.h"
#include "commands/SendSetCameraBrightness.h"
#include "commands/SendSetDefaultTurn.h"
#include "commands/SendSetLamp.h"
#include "commands/SendSetLEDColor.h"
#include "commands/SendSetLineMode.h"
#include "commands/SendSetNextTurn.h"
#include "commands/SendSetVector.h"

#include "commands/SendSelectedI2CCommand.h"
#include "commands/SendSelectedSPICommand.h"

OI::OI(DriveSystem *drive) {

	//Instantiate the Joystick
    _driveJoystick.reset(new frc::Joystick(0));
    _manipulatorJoystick.reset(new frc::Joystick(1));

    _driveCommand.reset(new Drive(_driveJoystick.get(), _manipulatorJoystick.get()));
    _drive = drive;

    _autoChooser = new frc::SendableChooser<frc::Command*>();

    _i2cChooser = new frc::SendableChooser<frc::Command*>();
    _i2cChooser->SetDefaultOption("Get Version", new SendCheckVersion(PixyPort::I2C));
    _i2cChooser->AddOption("Set Upper Lamp", new SendSetLamp(PixyPort::I2C, 1, 0));
    _i2cChooser->AddOption("Set Lower Lamp", new SendSetLamp(PixyPort::I2C, 0, 1));
    _i2cChooser->AddOption("Set Upper & Lower Lamp", new SendSetLamp(PixyPort::I2C, 1, 1));
    _i2cChooser->AddOption("Set LED Red", new SendSetLEDColor(PixyPort::I2C, 255, 0, 0));
    _i2cChooser->AddOption("Set LED Blue", new SendSetLEDColor(PixyPort::I2C, 0, 0, 255));
    _i2cChooser->AddOption("Set LED Green", new SendSetLEDColor(PixyPort::I2C, 0, 255, 0));
    _i2cChooser->AddOption("Set Camera Low Brightness", new SendSetCameraBrightness(PixyPort::I2C, 20));
    _i2cChooser->AddOption("Set Camera High Brightness", new SendSetCameraBrightness(PixyPort::I2C, 200));
    _i2cChooser->AddOption("Get Resolution", new SendGetResolution(PixyPort::I2C));
    _i2cChooser->AddOption("Get FPS", new SendGetFPS(PixyPort::I2C));
    _i2cChooser->AddOption("Get Blocks", new SendGetBlocks(PixyPort::I2C));
    _i2cChooser->AddOption("Get Main Features", new SendGetMainFeatures(PixyPort::I2C));
    _i2cChooser->AddOption("Get All Features", new SendGetAllFeatures(PixyPort::I2C));
    _i2cChooser->AddOption("Set Line Mode - 1", new SendSetLineMode(PixyPort::I2C, 1));
    _i2cChooser->AddOption("Set Line Mode - 2", new SendSetLineMode(PixyPort::I2C, 2));
    _i2cChooser->AddOption("Set Line Mode - 3", new SendSetLineMode(PixyPort::I2C, 3));
    _i2cChooser->AddOption("Set Next Turn - 20", new SendSetNextTurn(PixyPort::I2C, 20));
    _i2cChooser->AddOption("Set Next Turn - 90", new SendSetNextTurn(PixyPort::I2C, 90));
    _i2cChooser->AddOption("Set Next Turn - 170", new SendSetNextTurn(PixyPort::I2C, 170));
    _i2cChooser->AddOption("Set Vector - 1", new SendSetVector(PixyPort::I2C, 1));
    _i2cChooser->AddOption("Set Vector - 2", new SendSetVector(PixyPort::I2C, 2));
    _i2cChooser->AddOption("Set Vector - 3", new SendSetVector(PixyPort::I2C, 3));

    _spiChooser = new frc::SendableChooser<frc::Command*>();
    _spiChooser->SetDefaultOption("Get Version", new SendCheckVersion(PixyPort::SPI));
    _spiChooser->AddOption("Set Upper Lamp", new SendSetLamp(PixyPort::SPI, 1, 0));
    _spiChooser->AddOption("Set Lower Lamp", new SendSetLamp(PixyPort::SPI, 0, 1));
    _spiChooser->AddOption("Set Upper & Lower Lamp", new SendSetLamp(PixyPort::SPI, 1, 1));
    _spiChooser->AddOption("Set LED Red", new SendSetLEDColor(PixyPort::SPI, 255, 0, 0));
    _spiChooser->AddOption("Set LED Blue", new SendSetLEDColor(PixyPort::SPI, 0, 0, 255));
    _spiChooser->AddOption("Set LED Green", new SendSetLEDColor(PixyPort::SPI, 0, 255, 0));
    _spiChooser->AddOption("Set Camera Low Brightness", new SendSetCameraBrightness(PixyPort::SPI, 20));
    _spiChooser->AddOption("Set Camera High Brightness", new SendSetCameraBrightness(PixyPort::SPI, 200));
    _spiChooser->AddOption("Get Resolution", new SendGetResolution(PixyPort::SPI));
    _spiChooser->AddOption("Get FPS", new SendGetFPS(PixyPort::SPI));
    _spiChooser->AddOption("Get Blocks", new SendGetBlocks(PixyPort::SPI));
    _spiChooser->AddOption("Get Main Features", new SendGetMainFeatures(PixyPort::SPI));
    _spiChooser->AddOption("Get All Features", new SendGetAllFeatures(PixyPort::SPI));
    _spiChooser->AddOption("Set Line Mode - 1", new SendSetLineMode(PixyPort::SPI, 1));
    _spiChooser->AddOption("Set Line Mode - 2", new SendSetLineMode(PixyPort::SPI, 2));
    _spiChooser->AddOption("Set Line Mode - 3", new SendSetLineMode(PixyPort::SPI, 3));
    _spiChooser->AddOption("Set Next Turn - 20", new SendSetNextTurn(PixyPort::SPI, 20));
    _spiChooser->AddOption("Set Next Turn - 90", new SendSetNextTurn(PixyPort::SPI, 90));
    _spiChooser->AddOption("Set Next Turn - 170", new SendSetNextTurn(PixyPort::SPI, 170));
    _spiChooser->AddOption("Set Vector - 1", new SendSetVector(PixyPort::SPI, 1));
    _spiChooser->AddOption("Set Vector - 2", new SendSetVector(PixyPort::SPI, 2));
    _spiChooser->AddOption("Set Vector - 3", new SendSetVector(PixyPort::SPI, 3));
}

void OI::SetupDashboard() {
    //SmartDashboard Buttons
    frc::SmartDashboard::PutData("I2C Commands", _i2cChooser);
    frc::SmartDashboard::PutData("Send I2C Command", new SendSelectedI2CCommand(this));
    frc::SmartDashboard::PutString("I2C Message", "");
    frc::SmartDashboard::PutString("I2C Response", "");

    frc::SmartDashboard::PutData("SPI Commands", _spiChooser);
    frc::SmartDashboard::PutData("Send SPI Command", new SendSelectedSPICommand(this));
    frc::SmartDashboard::PutString("SPI Message", "");
    frc::SmartDashboard::PutString("SPI Response", "");
}

frc::SendableChooser<frc::Command*> *OI::getAutoChooser() {
	return _autoChooser;
}

frc::SendableChooser<frc::Command*> *OI::getI2CChooser() {
	return _i2cChooser;
}

frc::SendableChooser<frc::Command*> *OI::getSPIChooser() {
	return _spiChooser;
}

frc::Command* OI::DriveCommand() {
	return _driveCommand.get();
}
