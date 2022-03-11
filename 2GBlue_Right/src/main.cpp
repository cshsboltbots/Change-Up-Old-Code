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
  Inertia.calibrate();
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
//waitUntil(!Inertia.isCalibrating());
Inertia.setHeading(0, degrees);
task::sleep(1000);
TRollers.stop();
 //drive forward
task::sleep(1000);
//LIntake.spin(directionType::fwd, 100, velocityUnits::pct);
//RIntake.spin(directionType::fwd, 100, velocityUnits::pct);

LFDrive.startRotateTo(driveInches(44),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(44),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(44),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(44),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1000);
LFDrive.spin(forward);
LBDrive.spin(forward);
RFDrive.spin(reverse);
RBDrive.spin(reverse);
waitUntil(Inertia.rotation(degrees) >= 70 );
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(500);
LIntake.spin(directionType::fwd, 100, velocityUnits::pct);
RIntake.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(23),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(23),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(23),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(23),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(2000);
LIntake.stop();
RIntake.stop();
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(500);
LIntake.spin(directionType::rev, 100, velocityUnits::pct);
RIntake.spin(directionType::rev, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(-10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2000);
LIntake.stop();
RIntake.stop();
/*LFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1000);
LFDrive.spin(reverse);
LBDrive.spin(reverse);
RFDrive.spin(forward);
RBDrive.spin(forward);
waitUntil(Inertia.rotation(degrees) >= 90 );
task::sleep(1000);
LFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(39),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LIntake.spin(directionType::fwd, 100, velocityUnits::pct);
RIntake.spin(directionType::fwd, 100, velocityUnits::pct);
//turn left 
task::sleep(1700);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
Inertia.calibrate();
Inertia.setHeading(0, degrees);
 task::sleep(100);
 //turn left 
LFDrive.spin(reverse);
LBDrive.spin(reverse);
RFDrive.spin(forward);
RBDrive.spin(forward);
waitUntil(Inertia.rotation(degrees) <= -90 );
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
  
//start intake and driive forward for __ inches
LIntake.spin(directionType::fwd, 100, velocityUnits::pct);
RIntake.spin(directionType::fwd, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 70, velocityUnits::pct);
TRollers.spin(directionType::rev, 70, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 40,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 37,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 40,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 37,vex::velocityUnits::pct);

task::sleep(2500);
Inertia.calibrate();
waitUntil(!Inertia.isCalibrating());
Inertia.setHeading(0, degrees);
task::sleep(1000);
//intake continue to spin in but roller begin to spin
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
 task::sleep(1500);
TRollers.stop();
BRollers.stop();
LIntake.stop();
RIntake.stop();
//turn 180 
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
//turnL(45);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
Inertia.calibrate();
waitUntil(!Inertia.isCalibrating());
Inertia.setHeading(0, degrees);
task::sleep(1000);
LFDrive.startRotateTo(driveInches(24),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(24),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(24),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(24),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LFDrive.spin(reverse);
LBDrive.spin(reverse);
RFDrive.spin(forward);
RBDrive.spin(forward);
waitUntil(Inertia.rotation(degrees) <= -90 );
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
Inertia.setHeading(0, degrees);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(1000);
LFDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(12),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LFDrive.spin(forward);
LBDrive.spin(forward);
RFDrive.spin(reverse);
RBDrive.spin(reverse);
waitUntil(Inertia.rotation(degrees) >= 45 );
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();


//go forwardand back 
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
Inertia.calibrate();
waitUntil(!Inertia.isCalibrating());
Inertia.setHeading(0, degrees);
  task::sleep(2500);
 TRollers.stop();
  LIntake.spin(directionType::rev, 100, velocityUnits::pct);
RIntake.spin(directionType::rev, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(76),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(76),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(76),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(76),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
 task::sleep(4500);
 LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(4),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(1),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(4),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(1),vex::rotationUnits::deg, 50,vex::velocityUnits::pct);
 task::sleep(4500);
 LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
  LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(3000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);

LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
LFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 100,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-6),vex::rotationUnits::deg, 80,vex::velocityUnits::pct);
task::sleep(1000);
LBDrive.stop();
LFDrive.stop();
RFDrive.stop();
RBDrive.stop();
task::sleep(1000);
 LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
*/
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
    /*Optical2.setLightPower(100,pct);
  Optical2.setLight(ledState::on);
    Optical7.setLightPower(100,pct);
  Optical7.setLight(ledState::on);
    Optical8.setLightPower(100,pct);
  Optical8.setLight(ledState::on);*/
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
/*int RollerSpeedPCT = 200;
int IntakeSpeedPCT = 200;*/
 
  
  LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 + Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 - Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  LBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 + Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  RBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 - Controller1.Axis1.value()/3), vex::velocityUnits::pct);


int RollerSpeedPCT = 200;
int IntakeSpeedPCT = 200;

Optical2.setLightPower(100,pct);
  Optical2.setLight(ledState::on);
    Optical7.setLightPower(100,pct);
  Optical7.setLight(ledState::on);
    Optical8.setLightPower(100,pct);
  Optical8.setLight(ledState::on);

  //Roller Control
    if(Controller1.ButtonL2.pressing()) { //If button up is pressed...
        //...Spin the Tilter motor forward.
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonB.pressing()) { //If the down button is pressed...
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
    /*if(Controller1.ButtonL1.pressing()) { //If button up is pressed...
        //...Spin the Intake motors In.
        LIntake.spin(vex::directionType::fwd, IntakeSpeedPCT, vex::velocityUnits::pct);
        RIntake.spin(vex::directionType::fwd, IntakeSpeedPCT, vex::velocityUnits::pct);
     
    }*/
   //Optical Sensor Test  
    if(Controller1.ButtonL1.pressing() && Optical2.color()==blue) {
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical7.color()==red);
        task::sleep(20);
        TRollers.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==red && Optical7.color()!=blue) {
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }
    /*else {
        TRollers.stop(vex::brakeType::brake);
        BRollers.stop(vex::brakeType::brake);
    }*/
    
    if(Controller1.ButtonL1.pressing() && Optical2.color()==blue && Optical7.color()==blue) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical8.color()==blue);
        task::sleep(50);
        BRollers.stop(vex::brakeType::brake);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==red && Optical7.color()==blue) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }
  }

    /*else {
        BRollers.stop(vex::brakeType::brake);
    }*/
    
    /*if(Controller1.ButtonL2.pressing() && Optical2.color()==red) {
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical7.color()==red);
        task::sleep(500);
        TRollers.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }*/
    /*else if(Controller1.ButtonA.pressing() && Optical2.color()==blue) {
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }*/

    /*if(Controller1.ButtonL2.pressing() && Optical2.color()==red) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
      if(Controller1.ButtonL2.pressing() && Optical2.color()==blue) {
        BRollers.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
        waitUntil(Optical8.color()==blue);
        BRollers.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
      }
    }*/
    

    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    //Intentional space
      // Buitton A is used to rotate drive 90 degrees

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
