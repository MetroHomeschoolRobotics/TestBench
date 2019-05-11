#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "DriveSystem.h"

class TankDrive: public DriveSystem {

private:

	std::shared_ptr<frc::Spark> frontLeft;
	std::shared_ptr<frc::Spark> frontRight;
	std::shared_ptr<frc::Spark> rearRight;
	std::shared_ptr<frc::Spark> rearLeft;

public:
	double threshold = 0.1;

	TankDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z) override;
};

#endif
