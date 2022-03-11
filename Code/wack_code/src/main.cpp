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
// opti                 optical       15              
// inert                inertial      16              
// rfdrive              motor         20              
// rbdrive              motor         17              
// lbdrive              motor         4               
// lfdrive              motor         5               
// rintake              motor         18              
// lintake              motor         19              
// elevator             motor         10              
// roller               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

//10 and 20 = left drive
//1 and 11 = right drive
//3 = inertial sensor
#include "vex.h"

using namespace vex;
// A global instance of competition+
competition Competition;

motor_group intakes (rintake, lintake);

motor_group Left (lfdrive, lbdrive);
motor_group Right (rfdrive, rbdrive);

smartdrive Drivetrain (Left, Right, inert, 12.56, 8, 13.75, distanceUnits::in);


// 1 : red score
// 2 : blue score


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
  inert.calibrate();
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
  vex::task::sleep(2000);
  opti.setLightPower(100,pct);
  opti.setLight(ledState::on);
  Drivetrain.setDriveVelocity(90, percent);
  Drivetrain.setTurnVelocity(80,pct);
  roller.spin(directionType::fwd, 600, velocityUnits::rpm);
  vex::task::sleep(250);
  roller.stop(brakeType::brake);
  Drivetrain.driveFor(forward, 36, inches);
  Drivetrain.turnFor(right, 65, degrees);
  intakes.spin(fwd, 100, velocityUnits::pct);
  Drivetrain.driveFor(forward, 18 , inches);
  intakes.stop(brake);
  elevator.spin(directionType::fwd, 100, velocityUnits::pct);
  roller.spin(directionType::fwd, 100, velocityUnits::pct);
  vex::task::sleep(2500);
  elevator.stop(brakeType::brake);
  roller.stop(brakeType::brake);
  intakes.stop(brakeType::brake);
  Drivetrain.setDriveVelocity(70, pct);
  Drivetrain.driveFor(reverse, 25, inches);
  /*vex::task::sleep(375);
  Drivetrain.turnFor(right, 100/2, degrees);
  Drivetrain.setDriveVelocity(100, pct);
  Drivetrain.driveFor(forward, 6.2*12, inches);
  Drivetrain.setTurnVelocity(95, pct);
  vex::task::sleep(250);
  Drivetrain.turnFor(left, 90/2, degrees);
  intakes.spin(fwd, 100, velocityUnits::pct);
  elevator.spin(directionType::fwd, 100, velocityUnits::pct);
  roller.spin(directionType::fwd, 100, velocityUnits::pct);
  Drivetrain.driveFor(forward, 26, inches);
  vex::task::sleep(1750);
  intakes.stop(brakeType::brake);
  roller.stop(brakeType::brake);
  elevator.stop(brakeType::brake);
  intakes.spin(reverse, 100, pct);
  Drivetrain.driveFor(reverse, 10, inches);*/


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


    rfdrive.spin(directionType::fwd, (Controller1.Axis3.value() - (.8*Controller1.Axis1.value())), velocityUnits::pct); //(Axis3+Axis4)/2;
	  lfdrive.spin(directionType::fwd, (Controller1.Axis3.value() +  (.8*Controller1.Axis1.value())), velocityUnits::pct);//(Axis3-Axis4)/2;
    rbdrive.spin(directionType::fwd, (Controller1.Axis3.value() -  (.8*Controller1.Axis1.value())), velocityUnits::pct); //(Axis3+Axis4)/2;
	  lbdrive.spin(directionType::fwd, (Controller1.Axis3.value() +  (.8*Controller1.Axis1.value())), velocityUnits::pct);//(Axis3-Axis4)/2;
    
    // This is the main execution loop for the user control program.
    opti.setLight(ledState::on);
    opti.setLightPower(100, pct);

    if (Controller1.ButtonL2.pressing()){
        roller.setVelocity(100,percent);
        elevator.setVelocity(100,percent);
        if (opti.hue() > 50){
          elevator.spin(fwd);
          roller.spin(reverse);
        }
        else{
          elevator.spin(forward);
          roller.spin(forward);
        }
        elevator.spin(forward);
        roller.spin(forward);
        
      }
    

    else if (Controller1.ButtonL1.pressing()){
      elevator.spin(directionType::rev, 200, velocityUnits::pct);
      roller.spin(directionType::rev, 200, velocityUnits::pct);
    }

    else {
      roller.stop(brakeType::brake);
      elevator.stop(brakeType::brake);
    }
    
    if (Controller1.ButtonR1.pressing()){
      lintake.spin(directionType::rev, 100, velocityUnits::pct);
      rintake.spin(directionType::rev, 100, velocityUnits::pct);
      //elevator.spin(directionType::rev, 100, velocityUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()){
      lintake.spin(directionType::fwd, 100, velocityUnits::pct);
      rintake.spin(directionType::fwd, 100, velocityUnits::pct);
      //elevator.spin(directionType::fwd, 100, velocityUnits::pct);
    }

    else {
      lintake.stop(brakeType::brake);
      rintake.stop(brakeType::brake);
      //elevator.stop(brakeType::brake);
    }
    

    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(15, msec); // Sleep the task for a short amount of time to
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
