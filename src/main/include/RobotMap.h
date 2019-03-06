/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "pixy2/FRCPixy2.h"

class RobotMap {

public:
	static std::shared_ptr<frc::Spark> tankDriveFrontLeft;
	static std::shared_ptr<frc::Spark> tankDriveFrontRight;
	static std::shared_ptr<frc::Spark> tankDriveRearRight;
	static std::shared_ptr<frc::Spark> tankDriveRearLeft;

	static std::shared_ptr<FRCPixy2> pixySPI;
	static std::shared_ptr<FRCPixy2> pixyI2C;
	static void init();
};
