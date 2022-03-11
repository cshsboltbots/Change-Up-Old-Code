/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;

// A global instance of competition
competition Competition;
//Method to calculate the revolutions based on inches
static double driveInches(int inches)
{
  double degree = (inches/12.56)*360;
  return degree;
}
/*static void turnR(int turnfor)
{
    // Calibrate the Gyro, and wait for it to finish.
  Inertia.calibrate();
  waitUntil(!Inertia.isCalibrating());
  // Set the Gyro's heading to 0.
  Inertia.setHeading(0, degrees);

  // Turn right by spinning the LeftMotor forward and the RightMotor reverse.
  LFDrive.spin(forward);
  LBDrive.spin(forward);

  RFDrive.spin(reverse);
  RBDrive.spin(reverse);
  // Wait until the Gyro's heading is greater than 90 degrees.
  waitUntil(Inertia.heading() == turnfor);
  // Stop both motors.
  LBDrive.stop();
  LFDrive.stop();
  RFDrive.stop();
  RBDrive.stop();
}

static void turnL(int turnfor)
{
  
  // Set the Gyro's heading to 0.
  Inertia.setHeading(0, degrees);

  // Turn right by spinning the LeftMotor forward and the RightMotor reverse.
  LFDrive.spin(reverse);
  LBDrive.spin(reverse);

  RFDrive.spin(forward);
  RBDrive.spin(forward);
  // Wait until the Gyro's heading is greater than 90 degrees.
  waitUntil(Inertia.heading() > turnfor);
  // Stop both motors.
  LBDrive.stop();
  LFDrive.stop();
  RFDrive.stop();
  RBDrive.stop();
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

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

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
  // Calibrate the Gyro, and wait for it to finish.
//Spin top rollers
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
  task::sleep(1000);
 TRollers.stop();
 //drive forward
/*LFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
//turn left 
task::sleep(1700);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
 task::sleep(100);
LFDrive.startRotateTo(235,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(-235,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
LBDrive.startRotateTo(235,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(-235,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
//turn left 
  task::sleep(430);
 RBDrive.stop();
 LBDrive.stop();
 RFDrive.stop();
 LFDrive.stop();
 task::sleep(100);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
 task::sleep(100);
//start intake and driive forward for __ inches
LIntake.spin(directionType::fwd, 100, velocityUnits::pct);
RIntake.spin(directionType::fwd, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 40,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 37,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 40,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 37,vex::velocityUnits::pct);
task::sleep(2500);

//intake continue to spin in but roller begin to spin
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
 task::sleep(1500);
TRollers.stop();
BRollers.stop();
LIntake.stop();
RIntake.stop();
 
 task::sleep(100);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
 task::sleep(100);
 LIntake.spin(directionType::rev, 100, velocityUnits::pct);
RIntake.spin(directionType::rev, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(-18),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-18),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-18),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-18),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
task::sleep(2000);
*/
//turnL(45);
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
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
int RollerSpeedPCT = 200;
  int IntakeSpeedPCT = 200;
 

  LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()*2), vex::velocityUnits::pct);
  RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()*2), vex::velocityUnits::pct);
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

//
// Main will set up the competition functions and callbacks.
//
int main() {
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
