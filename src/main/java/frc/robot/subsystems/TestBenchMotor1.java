// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;
import com.ctre.phoenix6.hardware.TalonFX;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

public class TestBenchMotor1 extends SubsystemBase {
    /** Creates a new TestBenchMotor1. */
  private TalonFX TestBenchMotor1Object = new TalonFX(0);

  public TestBenchMotor1() {
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }

  public void DriveForward(double Output) {
    TestBenchMotor1Object.setVoltage(Output*12);
  }

  public void DriveBackwards(double Output) {
    TestBenchMotor1Object.setVoltage(Output*12);
  }
}
