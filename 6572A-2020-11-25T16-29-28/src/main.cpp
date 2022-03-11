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
// LFDrive              motor         11              
// RFDrive              motor         12              
// LBDrive              motor         15              
// RBDrive              motor         14              
// RIntake              motor         1               
// LIntake              motor         5               
// BRollers             motor         3               
// TRollers             motor         4               
// Inertia              inertial      10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
/*static double driveInches(int inches)
{
  double degree = (inches/12.56)*360;
  return degree;
}*/

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
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
int displayTask();

    while(1) {
      // display some useful info
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

LFDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
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

