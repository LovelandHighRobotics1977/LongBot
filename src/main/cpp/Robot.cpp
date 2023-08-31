// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
  m_drive.SetNeutralMode(Coast);
  m_turn.SetNeutralMode(Brake);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  timer.Reset();
  timer.Start();
}
void Robot::AutonomousPeriodic() {
  std::cout<<"Starting Autonomous Routine"<<std::endl;

  std::cout<<"Autonomous Routine Complete"<<std::endl;
}

void Robot::TeleopInit() {
}
void Robot::TeleopPeriodic() {
  //calling drive with xbox stick input
  m_drive.Set((0.8 * m_driverController.GetRightY()));
  m_turn.Set((
    (
      m_driverController.GetLeftBumper() -  
      m_driverController.GetRightBumper()
    )*
    (1)

  )
  *0.9
  );
  
}

void Robot::DisabledInit() {
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif