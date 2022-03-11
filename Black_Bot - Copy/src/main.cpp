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
motor_group Intakes (RIntake, LIntake);
motor_group Rollers (BRollers, TRollers);
motor_group Driveleft (LBDrive, LFDrive);
motor_group Driveright (RBDrive, RFDrive);
motor_group drivetrain (LBDrive, LFDrive, RBDrive, RFDrive);

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
vex::task dtask;
vex::task stask;
vex::task itask;
vex::task rtask;
vex::task auton;

int RollerSpeedPCT = 200;
int IntakeSpeedPCT = 200;

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
int autonTask() {
 Optical2.setLightPower(100,pct);
 Optical2.setLight(ledState::off);
 Optical7.setLightPower(100,pct);
 Optical7.setLight(ledState::off);
 Optical8.setLightPower(100,pct);
 Optical8.setLight(ledState::on);
  while(1) {
    if (Optical2.color()==red && Optical7.color()!=red) {
      TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
      BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
      waitUntil(Optical7.color()==red);
      //task::sleep(20);
      TRollers.stop(vex::brakeType::hold);
      BRollers.stop(vex::brakeType::hold);
    }
    else if (Optical2.color()==red && Optical7.color()==red) {
      BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
      waitUntil(Optical8.color()==red);
      //task::sleep(20);
      BRollers.stop(vex::brakeType::hold);
    }
  }
  return(0);
}

void autonomous(void) {
dtask.stop();
stask.stop();
itask.stop();
rtask.stop();
//Spin top rollers
auton = vex::task(autonTask);
//Goal 1
/*
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
Inertia.setHeading(0, degrees);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(400);
TRollers.stop();
task::sleep(100);
//Goal 2
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//62
RFDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2250);
Intakes.stop();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >=17 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(34),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//34
RFDrive.startRotateTo(driveInches(34),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(34),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(34),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1450);
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= 100 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//34
RFDrive.startRotateTo(driveInches(10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(10),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1450);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(500);
Inertia.calibrate();
Inertia.setHeading(0, degrees);
task::sleep(2550);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-8
RFDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);

//Goal 3
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -77 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
task::sleep(250);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(46),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//46
RFDrive.startRotateTo(driveInches(46),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(46),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(46),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2500);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -55 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(16),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//16
RFDrive.startRotateTo(driveInches(16),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(16),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(16),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(800);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(4000);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-13),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(-13),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-11
LBDrive.startRotateTo(driveInches(-13),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-13),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
//Goal 4 PROBLEMS START HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -164 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(41),vex::rotationUnits::deg, 60,vex::velocityUnits::pct);//46
RFDrive.startRotateTo(driveInches(41),vex::rotationUnits::deg, 60,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(41),vex::rotationUnits::deg, 60,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(41),vex::rotationUnits::deg, 60,vex::velocityUnits::pct);
task::sleep(2500);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -110 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//10
RFDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(7),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
Inertia.calibrate();
Inertia.setHeading(0, degrees);
task::sleep(2200);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-17),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-22
RFDrive.startRotateTo(driveInches(-17),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-17),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-17),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
//Goal 5
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -60 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
task::sleep(250);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(100);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(42),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//51
RFDrive.startRotateTo(driveInches(42),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(42),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(42
),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2000);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-9),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-13
RFDrive.startRotateTo(driveInches(-9),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-9),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-9),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -40 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(21),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//31
RFDrive.startRotateTo(driveInches(21),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(21),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(21),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1000);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(1500);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-12),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-17
RFDrive.startRotateTo(driveInches(-12),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-12),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-12),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
//Goal 6
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -187 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//48
RFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2000);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -97 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RFDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//30
LBDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(20),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(1200);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
Inertia.calibrate();
Inertia.setHeading(0, degrees);
task::sleep(2200);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-6
RFDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
//Goal 7
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -70 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(31),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//46
RFDrive.startRotateTo(driveInches(31),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(31),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(31),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2500);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -40 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//14
RFDrive.startRotateTo(driveInches(8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(1500);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-13
RFDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-8),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
//Goal 8
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(reverse, 75,vex::velocityUnits::pct);
LBDrive.spin(reverse, 75,vex::velocityUnits::pct);
RFDrive.spin(forward, 75,vex::velocityUnits::pct);
RBDrive.spin(forward, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) <= -175 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
Intakes.spin(directionType::fwd, 100, velocityUnits::pct);
LFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//46
RFDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(32),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(2500);
Intakes.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= -90 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(6),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//8
RFDrive.startRotateTo(driveInches(6),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(6),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(6),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
TRollers.spin(directionType::rev, 100, velocityUnits::pct);
BRollers.spin(directionType::rev, 100, velocityUnits::pct);
task::sleep(1500);
TRollers.stop();
BRollers.stop();
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
LFDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);//-6
RFDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
LBDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
RBDrive.startRotateTo(driveInches(-4),vex::rotationUnits::deg, 90,vex::velocityUnits::pct);
task::sleep(500);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
LFDrive.spin(forward, 75,vex::velocityUnits::pct);
LBDrive.spin(forward, 75,vex::velocityUnits::pct);
RFDrive.spin(reverse, 75,vex::velocityUnits::pct);
RBDrive.spin(reverse, 75,vex::velocityUnits::pct);
waitUntil(Inertia.rotation(degrees) >= 90 );
LBDrive.stop(vex::brakeType::hold);
LFDrive.stop(vex::brakeType::hold);
RFDrive.stop(vex::brakeType::hold);
RBDrive.stop(vex::brakeType::hold);
LBDrive.resetRotation();
LFDrive.resetRotation();
RFDrive.resetRotation();
RBDrive.resetRotation();
task::sleep(250);
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

int storeBall() {
  Optical2.setLightPower(100,pct);
  Optical2.setLight(ledState::on);
    Optical7.setLightPower(100,pct);
  Optical7.setLight(ledState::on);
    Optical8.setLightPower(100,pct);
  Optical8.setLight(ledState::on);

  while(1) {
    if(Controller1.ButtonL1.pressing() && Optical2.color()==red) {
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical7.color()==red);
        //task::sleep(20);
        TRollers.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==blue && Optical7.color()!=red) {
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }
    /*else {
        TRollers.stop(vex::brakeType::brake);
        BRollers.stop(vex::brakeType::brake);
    }*/
    
    if(Controller1.ButtonL1.pressing() && Optical2.color()==red && Optical7.color()==red) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical8.color()==red);
        //task::sleep(50);
        BRollers.stop(vex::brakeType::brake);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==blue && Optical7.color()==red) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }

    //Roller Control
    if(Controller1.ButtonL2.pressing()) { //If button up is pressed...
        //...Spin the Tilter motor forward.
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonB.pressing()) { //If the down button is pressed...
        //...Spin the Tilter motor backward.
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
    }
    else { //If the the up or down button is not pressed...
        //...Stop the Tilter motor.
        TRollers.stop(vex::brakeType::hold);
        BRollers.stop(vex::brakeType::hold);     
    }
  }
  return(0);
}

int driveTask() {
  while(1) {
    LFDrive.setBrake(coast);
    LBDrive.setBrake(coast);
    RFDrive.setBrake(coast);
    RBDrive.setBrake(coast);
    LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()/2), vex::velocityUnits::pct);
    RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()/2), vex::velocityUnits::pct);
    LBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()/2), vex::velocityUnits::pct);
    RBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()/2), vex::velocityUnits::pct);
  }
  return(0);
}

/*int rollerTask() {
  while(1) {
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
  }
  return(0);
}*/

int intakeTask() {
  while(1) {
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
        LIntake.stop(vex::brakeType::hold);
        RIntake.stop(vex::brakeType::hold);
    }
  }
  return(0);
}
void usercontrol(void) {
  // User control code here, inside the loop
  dtask = vex::task(driveTask);
  stask = vex::task(storeBall);
  //rtask = vex::task(rollerTask);
  itask = vex::task(intakeTask);
  /*while (1) {

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

 
  LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 + Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 - Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  LBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 + Controller1.Axis1.value()/3), vex::velocityUnits::pct);
  RBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2 - Controller1.Axis1.value()/3), vex::velocityUnits::pct);

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

    storeBall();

  }*/
    
   //Optical Sensor Test  
    /*if(Controller1.ButtonL1.pressing() && Optical2.color()==red) {
        TRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical7.color()==red);
        task::sleep(20);
        TRollers.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==blue && Optical7.color()!=red) {
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }
   
    
    if(Controller1.ButtonL1.pressing() && Optical2.color()==red && Optical7.color()==red) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        waitUntil(Optical8.color()==red);
        task::sleep(50);
        BRollers.stop(vex::brakeType::brake);
    }
    else if(Controller1.ButtonL1.pressing() && Optical2.color()==blue && Optical7.color()==red) {
        BRollers.spin(vex::directionType::rev, RollerSpeedPCT, vex::velocityUnits::pct);
        task::sleep(1000);
    }*/
  
  
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
