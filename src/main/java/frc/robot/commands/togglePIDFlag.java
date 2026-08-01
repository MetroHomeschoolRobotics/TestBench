package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.Command;
import frc.robot.subsystems.TestBenchMotor1;

public class togglePIDFlag extends Command {
    TestBenchMotor1 m_TestBenchMotor1;
    public togglePIDFlag(TestBenchMotor1 _motor1){
        m_TestBenchMotor1 = _motor1;  
    }
    public void initialize(){
        m_TestBenchMotor1.togglePID();
    }
    public void execute(){}
    public void end(boolean interrupted){}
    public boolean isFinished(){
        return true;
    }

}
