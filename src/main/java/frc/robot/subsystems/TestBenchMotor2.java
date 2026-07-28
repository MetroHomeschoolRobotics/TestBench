// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.wpilibj.motorcontrol.Talon;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

public class TestBenchMotor2 extends SubsystemBase {
  /** Creates a new TestBenchMotor2. */
  private Talon TestBenchMotor2Object = new Talon(0);

  public TestBenchMotor2() {
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }

  public void DriveForward(double Output) {
    TestBenchMotor2Object.setVoltage(Output*12);
  }

  public void DriveBackwards(double Output) {
    TestBenchMotor2Object.setVoltage(Output*12);
  }
}
