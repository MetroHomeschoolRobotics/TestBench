#include "RobotMap.h"

std::shared_ptr<frc::Spark> RobotMap::tankDriveFrontLeft;
std::shared_ptr<frc::Spark> RobotMap::tankDriveFrontRight;
std::shared_ptr<frc::Spark> RobotMap::tankDriveRearRight;
std::shared_ptr<frc::Spark> RobotMap::tankDriveRearLeft;
std::shared_ptr<FRCPixy2> RobotMap::pixySPI;
std::shared_ptr<FRCPixy2> RobotMap::pixyI2C;

void RobotMap::init() {
    tankDriveFrontLeft.reset(new frc::Spark(1));
   
    tankDriveFrontRight.reset(new frc::Spark(3));

    tankDriveRearRight.reset(new frc::Spark(4));

    tankDriveRearLeft.reset(new frc::Spark(2));

    frc::SpeedController *fLeft = tankDriveFrontLeft.get();
    frc::SpeedController *rLeft = tankDriveRearLeft.get();
    frc::SpeedController *fRight = tankDriveFrontRight.get();
    frc::SpeedController *rRight = tankDriveRearRight.get();

    pixySPI.reset(new FRCPixy2(frc::SPI::kOnboardCS0));
    pixyI2C.reset(new FRCPixy2(frc::I2C::kOnboard , 0));

}

