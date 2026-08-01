package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.Command;
import frc.robot.subsystems.TestBenchMotor1;
import frc.robot.subsystems.TestBenchMotor2;

public class AlternateMotors extends Command {
    TestBenchMotor1 m_TestBenchMotor1;
    TestBenchMotor2 m_TestBenchMotor2;
    int timer;
    public AlternateMotors(TestBenchMotor1 _motor1,TestBenchMotor2 _motor2){
        m_TestBenchMotor1=_motor1;
        m_TestBenchMotor2=_motor2;

        addRequirements(_motor1);
        addRequirements(_motor2);
    }
    public void initialize(){
        timer = 0;
    }
    public void execute(){
        if(timer%50<25){
            m_TestBenchMotor1.DriveForward(0.5);
            m_TestBenchMotor2.DriveForward(0);
        }else{
            m_TestBenchMotor2.DriveForward(0.5);
            m_TestBenchMotor1.DriveForward(0);
        }
            timer++;
    }
    public void end(boolean interrupted){
        m_TestBenchMotor1.DriveForward(0);
            m_TestBenchMotor2.DriveForward(0);
    }
    public boolean isFinished(){
        return false;
    }
}
