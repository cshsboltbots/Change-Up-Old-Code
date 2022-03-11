/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LFDrive              motor         12              
// LBDrive              motor         15              
// RFDrive              motor         11              
// RBDrive              motor         14              
// BRollers             motor         3               
// TRollers             motor         4               
// LIntake              motor         5               
// RIntake              motor         1               
// Inertial             inertial      20              
// LSensor              optical       19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
motor_group leftDrive(LFDrive,LBDrive);
motor_group rightDrive(RFDrive,RBDrive);
smartdrive    Drivetrain( leftDrive, rightDrive, Inertial, 12.56, 16, 14, distanceUnits::in );
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
int displayTask();
waitUntil(!Inertial.isCalibrating());
    while(1) {
      // display some useful info
      Brain.Screen.setCursor(2,1);
      Brain.Screen.print( "  LBDrive    speed: %4.0f   position: %6.2f", LBDrive.velocity( percent ), LBDrive.position( rev ) );
      Brain.Screen.newLine();
      Brain.Screen.print( "  LFDrive    speed: %4.0f   position: %6.2f", LFDrive.velocity( percent ), LFDrive.position( rev ));
      Brain.Screen.newLine();
      Brain.Screen.print( "  RBDrive    speed: %4.0f   position: %6.2f", RBDrive.velocity( percent ), RBDrive.position( rev ));
      Brain.Screen.newLine();
      Brain.Screen.print( "  RFDrive    speed: %4.0f   position: %6.2f", RFDrive.velocity( percent ), RFDrive.position( rev ));
      Brain.Screen.newLine();
      Brain.Screen.newLine();

      // motor group velocity and position is returned for the first motor in the group
      Brain.Screen.print( "  leftDrive  speed: %4.0f   position: %6.2f", leftDrive.velocity( percent ), leftDrive.position( rev ));
      Brain.Screen.newLine();
      Brain.Screen.print( "  rightDrive speed: %4.0f   position: %6.2f", rightDrive.velocity( percent ), rightDrive.position( rev ));
      Brain.Screen.newLine();
      Brain.Screen.newLine();

      // drivetrain velocity is the average of the motor velocities for left and right
      Brain.Screen.print( "  Drivetrain speed: %4.0f", Drivetrain.velocity( percent ) );
      Brain.Screen.newLine();

      // no need to run this loop too quickly
      wait( 20, timeUnits::msec );
    }

   
}

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
 RFDrive.setStopping(brake);
  RBDrive.setStopping(brake);
  LFDrive.setStopping(brake);
  LBDrive.setStopping(brake);

  TRollers.spin(directionType::rev, 100, velocityUnits::pct);
  task::sleep(1500);
 TRollers.stop();
  /*LFDrive.spin(directionType::fwd, 70, velocityUnits::pct);
  RFDrive.spin(directionType::fwd, 70, velocityUnits::pct);
  LBDrive.spin(directionType::fwd, 70, velocityUnits::pct);
  RBDrive.spin(directionType::fwd, 70, velocityUnits::pct);
  task::sleep(1500);
*/
LFDrive.startRotateFor(960,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
RFDrive.startRotateFor(960,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
LBDrive.startRotateFor(960,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
RBDrive.startRotateFor(960,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
 task::sleep(1500);
 LIntake.spin(directionType::rev, 70, velocityUnits::pct);
RIntake.spin(directionType::rev, 70, velocityUnits::pct);
LFDrive.startRotateFor(340,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
RFDrive.startRotateFor(-340,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
LBDrive.startRotateFor(340,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
RBDrive.startRotateFor(-340,vex::rotationUnits::deg,200,vex::velocityUnits::pct);
 task::sleep(540);
LIntake.spin(directionType::fwd, 70, velocityUnits::pct);
RIntake.spin(directionType::fwd, 70, velocityUnits::pct);
LFDrive.startRotateFor(600,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
RFDrive.startRotateFor(600,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
LBDrive.startRotateFor(600,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
RBDrive.startRotateFor(600,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
TRollers.spin(directionType::rev, 70, velocityUnits::pct);
BRollers.spin(directionType::rev, 70, velocityUnits::pct);
task::sleep(2500);
 LIntake.stop();
 RIntake.stop();
 TRollers.stop();
  BRollers.stop();
  task::sleep(2500);
LFDrive.spin(directionType::rev , 70, velocityUnits::pct);
  RFDrive.spin(directionType::rev, 70, velocityUnits::pct);
  LBDrive.spin(directionType::rev, 70, velocityUnits::pct);
  RBDrive.spin(directionType::rev, 70, velocityUnits::pct);
  task::sleep(750);
  LFDrive.stop();
  LBDrive.stop();
  RFDrive.stop();
  RBDrive.stop();
  task::sleep(1500);
/*
  LFDrive.rotateFor(360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
  RFDrive.rotateFor(360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    task::sleep(100);
*/
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
  int RollerSpeedPCT = 200;
  int IntakeSpeedPCT = 200;
 

  LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()*2), vex::velocityUnits::pct);
  RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()*2), vex::velocityUnits::pct);
  LBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()*2), vex::velocityUnits::pct);
  RBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()*2), vex::velocityUnits::pct);

 
  //Roller Control
    if(Controller1.ButtonL1.pressing()) { //If button up is pressed...
        //...Spin the Tilter motor forward.
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing()) { //If the down button is pressed...
        //...Spin the Tilter motor backward.
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
    }
    else { //If the the up or down button is not pressed...
        //...Stop the Tilter motor.
        TRollers.stop(vex::brakeType::brake);
        BRollers.stop(vex::brakeType::brake);     
    }



    //Intake Control
    if(Controller1.ButtonR1.pressing()) { //If button up is pressed...
        //...Spin the Intake motors In.
        LIntake.spin(vex::directionType::fwd, IntakeSpeedPCT, vex::velocityUnits::pct);
        RIntake.spin(vex::directionType::fwd, IntakeSpeedPCT, vex::velocityUnits::pct);
     
    }
    else if(Controller1.ButtonR2.pressing()) { //If the down button is pressed...
        //...Spin the Intake motors out.
        LIntake.spin(vex::directionType::rev, IntakeSpeedPCT, vex::velocityUnits::pct);
        RIntake.spin(vex::directionType::rev, IntakeSpeedPCT, vex::velocityUnits::pct);
    }
    else { //If the the up or down button is not pressed...
        //...Stop the intake motors.
        LIntake.stop(vex::brakeType::brake);
        RIntake.stop(vex::brakeType::brake);
    }
   
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    //Intentional space
      // Buitton A is used to rotate drive 90 degrees
      if( Controller1.ButtonA.pressing() ) {
        // tell drivetrain to rotate 90 deg
        Drivetrain.turnFor( 90, degrees );
        // wait for it to be done
        while( Drivetrain.isMoving() )
          wait( 10, timeUnits::msec );
      }
      else {}

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}


int main(){ 
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

