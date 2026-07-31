// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.Command;
import frc.robot.subsystems.TestBenchMotor1;

public class Motor1SlowForward extends Command {
  /** Creates a new Motor1SlowForward. */
  private TestBenchMotor1 m_TestBenchMotor1;
  public Motor1SlowForward(TestBenchMotor1 m_TestBenchMotor1) {
    this.m_TestBenchMotor1=m_TestBenchMotor1;
    addRequirements(m_TestBenchMotor1);
  }

  // Called when the command is initially scheduled.
  @Override
  public void initialize() {
    m_TestBenchMotor1.DriveForward(0.3);
  }

  // Called every time the scheduler runs while the command is scheduled.
  @Override
  public void execute() {
    m_TestBenchMotor1.DriveForward(0.3);
  }

  // Called once the command ends or is interrupted.
  @Override
  public void end(boolean interrupted) {
    m_TestBenchMotor1.DriveForward(0);
  }

  // Returns true when the command should end.
  @Override
  public boolean isFinished() {
    return false;
  }
}
