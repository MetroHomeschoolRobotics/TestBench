#include "RobotMap.h"

std::shared_ptr<frc::Spark> RobotMap::tankDriveFrontLeft;
std::shared_ptr<frc::Spark> RobotMap::tankDriveFrontRight;
std::shared_ptr<frc::Spark> RobotMap::tankDriveRearRight;
std::shared_ptr<frc::Spark> RobotMap::tankDriveRearLeft;

std::shared_ptr<VisionTracking> RobotMap::visionTracking;

void RobotMap::init() {
    tankDriveFrontLeft.reset(new frc::Spark(1));
   
    tankDriveFrontRight.reset(new frc::Spark(3));

    tankDriveRearRight.reset(new frc::Spark(4));

    tankDriveRearLeft.reset(new frc::Spark(2));

    visionTracking.reset(new VisionTracking());
}

