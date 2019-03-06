/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"
#include "subsystems/Positioning.h"
#include "subsystems/DriveSystem.h"

class OI {

private:

	//Create Private Objects
	std::shared_ptr<frc::Command> _driveCommand;
	std::shared_ptr<frc::Joystick> driveJoystick;
	std::shared_ptr<frc::Joystick> manipulatorJoystick;
	frc::SendableChooser<frc::Command*> *autoChooser;

	DriveSystem *_drive;
	Positioning *_positioning; 

public:

	OI(DriveSystem *drive, Positioning *positioning);

	void SetupDashboard();

	//Create Private Inputs
	frc::Command* DriveCommand();
	frc::SendableChooser<frc::Command*> *getAutoChooser();
};
