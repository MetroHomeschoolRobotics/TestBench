/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"
#include "subsystems/DriveSystem.h"

class OI {

private:

	//Create Private Objects
	std::shared_ptr<frc::Command> _driveCommand;
	std::shared_ptr<frc::Joystick> _driveJoystick;
	std::shared_ptr<frc::Joystick> _manipulatorJoystick;
	frc::SendableChooser<frc::Command*> *_autoChooser;
	frc::SendableChooser<frc::Command*> *_i2cChooser;
	frc::SendableChooser<frc::Command*> *_spiChooser;

	DriveSystem *_drive;

public:

	OI(DriveSystem *drive);

	void SetupDashboard();

	//Create Private Inputs
	frc::Command* DriveCommand();
	frc::SendableChooser<frc::Command*> *getAutoChooser();
	frc::SendableChooser<frc::Command*> *getI2CChooser();
	frc::SendableChooser<frc::Command*> *getSPIChooser();
};
