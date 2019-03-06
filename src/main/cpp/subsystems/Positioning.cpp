#include "subsystems/Positioning.h"
#include "RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
}

void Positioning::UpdateDashboard(){
/*	
	frc::SmartDashboard::PutNumber("Front Left", GetFrontLeftDistance());
	frc::SmartDashboard::PutNumber("Front Right", GetFrontRightDistance());
	frc::SmartDashboard::PutNumber("Rear Left", GetRearLeftDistance());
	frc::SmartDashboard::PutNumber("Rear Right", GetRearRightDistance());
*/

	if (RobotMap::pixySPI != nullptr) {
		FRCPixyBlock* spiBlock = RobotMap::pixySPI->GetBlocks(0);
		if (spiBlock == nullptr){
			frc::SmartDashboard::PutNumber("SPI Blocks", 0);
			frc::SmartDashboard::PutNumber("SPI Block - X", 0);
			frc::SmartDashboard::PutNumber("SPI Block - Y", 0);
			frc::SmartDashboard::PutNumber("SPI Block - H", 0);
			frc::SmartDashboard::PutNumber("SPI Block - W", 0);
		} else {
			frc::SmartDashboard::PutNumber("SPI Blocks", 1);
			frc::SmartDashboard::PutNumber("SPI Block - X", spiBlock->getX()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - Y", spiBlock->getY()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - H", spiBlock->getHeight()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - W", spiBlock->getWidth()/1000);
		}
	}

	if (RobotMap::pixyI2C != nullptr) {
		FRCPixyBlock* spiBlock = RobotMap::pixyI2C->GetBlocks(0);
		if (spiBlock == nullptr){
			frc::SmartDashboard::PutNumber("I2C Blocks", 0);
			frc::SmartDashboard::PutNumber("I2C Block - X", 0);
			frc::SmartDashboard::PutNumber("I2C Block - Y", 0);
			frc::SmartDashboard::PutNumber("I2C Block - H", 0);
			frc::SmartDashboard::PutNumber("I2C Block - W", 0);
		} else {
			frc::SmartDashboard::PutNumber("I2C Blocks", 1);
			frc::SmartDashboard::PutNumber("I2C Block - X", spiBlock->getX()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - Y", spiBlock->getY()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - H", spiBlock->getHeight()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - W", spiBlock->getWidth()/1000);
		}
	}
/*
	FRCPixyVersion* version = RobotMap::pixySPI->CheckVersion();
	if (version == nullptr){
		std::wcout << L"Pixy - unknown version" << std::endl;
	} else {
		std::wcout << L"Pixy - version " << version->getFirmware() << std::endl;
	}
	*/

}


void Positioning::InitDefaultCommand() {
}

