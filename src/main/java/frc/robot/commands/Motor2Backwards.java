// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.Command;
import frc.robot.subsystems.TestBenchMotor2;

public class Motor2Backwards extends Command {
  /** Creates a new Motor2Backwards. */
  TestBenchMotor2 m_TestBenchMotor2;
  public Motor2Backwards(TestBenchMotor2 m_TestBenchMotor2) {
    // Use addRequirements() here to declare subsystem dependencies.
    addRequirements(m_TestBenchMotor2);
  }

  // Called when the command is initially scheduled.
  @Override
  public void initialize() {
    m_TestBenchMotor2.DriveBackwards(0.5);
  }

  // Called every time the scheduler runs while the command is scheduled.
  @Override
  public void execute() {
    m_TestBenchMotor2.DriveBackwards(0.5);
  }

  // Called once the command ends or is interrupted.
  @Override
  public void end(boolean interrupted) {
    m_TestBenchMotor2.DriveBackwards(0);
  }

  // Returns true when the command should end.
  @Override
  public boolean isFinished() {
    return false;
  }
}
