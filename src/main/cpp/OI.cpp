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

OI::OI(DriveSystem *drive, Positioning *positioning) {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));

    _driveCommand.reset(new Drive(driveJoystick.get(), manipulatorJoystick.get()));
    _drive = drive;
	_positioning = positioning;

    autoChooser = new frc::SendableChooser<frc::Command*>();
}

void OI::SetupDashboard() {
    //SmartDashboard Buttons
}

frc::SendableChooser<frc::Command*> *OI::getAutoChooser() {
	return autoChooser;
}

frc::Command* OI::DriveCommand() {
	return _driveCommand.get();
}
