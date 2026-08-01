package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.Command;
import edu.wpi.first.wpilibj2.command.button.CommandXboxController;
import frc.robot.subsystems.TestBenchMotor1;

public class MovePIDWithJoystick extends Command {
    CommandXboxController joystick;
    TestBenchMotor1 m_TestBenchMotor1;
    public MovePIDWithJoystick(TestBenchMotor1 _motor1, CommandXboxController _joystick){
        m_TestBenchMotor1 = _motor1;
        joystick=_joystick;
        addRequirements(m_TestBenchMotor1);
    }
    public void initialize(){}
    public void execute(){
        m_TestBenchMotor1.setPID(joystick.getLeftX()*2);
    }
    public void end(boolean interrupted){}
    public boolean isFinished(){
        return false;
    }
}
