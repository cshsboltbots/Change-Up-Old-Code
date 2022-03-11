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
  task::sleep(200);
  //the rollers spit ball one into home row  center goal and descore one ball 
  roller1.spin(vex::directionType::fwd, 600,vex::velocityUnits::pct);
  roller2.spin(vex::directionType::fwd, 600,vex::velocityUnits::pct);
  task::sleep(700);

  leftintake.spin(vex::directionType::fwd, 200,vex::velocityUnits::pct);
  rightintake.spin(vex::directionType::fwd, 200,vex::velocityUnits::pct);


  //Back up
  LFD.spin(vex::directionType::rev, 50,vex::velocityUnits::pct);
  LBD.spin(vex::directionType::rev, 50,vex::velocityUnits::pct);
  RFD.spin(vex::directionType::fwd, 50,vex::velocityUnits::pct);
  RBD.spin(vex::directionType::fwd, 50,vex::velocityUnits::pct);
  roller1.stop();
  roller2.stop();
  task::sleep(2000);
  //robot stop
  LFD.stop();
  LBD.stop();
  RFD.stop();
  RBD.stop();
  task::sleep(100);

  //robo go foward
  LFD.spin(vex::directionType::fwd, 75,vex::velocityUnits::pct);
  LBD.spin(vex::directionType::fwd, 75,vex::velocityUnits::pct);
  RFD.spin(vex::directionType::rev, 75,vex::velocityUnits::pct);
  RBD.spin(vex::directionType::rev, 75,vex::velocityUnits::pct);
  task::sleep(490);

  LFD.stop();
  LBD.stop();
  RFD.stop();
  RBD.stop();
  
 // leftintake.stop();
 // rightintake.stop();
 // roller1.stop();
 // roller2.stop();
 
  //robo go back by little bit
  //LFDrive.spin(vex::directionType::rev, 30,vex::velocityUnits::pct);
  //LBDrive.spin(vex::directionType::rev, 30,vex::velocityUnits::pct);
  //RFDrive.spin(vex::directionType::fwd, 30,vex::velocityUnits::pct);
  //RBDrive.spin(vex::directionType::fwd, 30,vex::velocityUnits::pct);
  //task::sleep(5);
  //LFDrive.stop();
  //LBDrive.stop();
  //RFDrive.stop();
  //RBDrive.stop();
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
   LFD.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2), vex::velocityUnits::pct);
   LBD.spin(vex::directionType::fwd, (Controller1.Axis3.value()*2), vex::velocityUnits::pct);
   RFD.spin(vex::directionType::rev, (Controller1.Axis2.value()*2), vex::velocityUnits::pct);
   RBD.spin(vex::directionType::rev, (Controller1.Axis2.value()*2), vex::velocityUnits::pct);
   
  }
{
   if(Controller1.ButtonL1.pressing()) {
    roller1.spin(vex::directionType::fwd, 600, vex::velocityUnits::pct);
    roller2.spin(vex::directionType::fwd, 600, vex::velocityUnits::pct);
   }
   else if(Controller1.ButtonL2.pressing()) {
   roller1.spin(vex::directionType::rev, 600, vex::velocityUnits::pct);
   roller2.spin(vex::directionType::rev, 600, vex::velocityUnits::pct);
   }
   else{

   roller1.stop(vex::brakeType::brake);
   roller2.stop(vex::brakeType::brake);
   }

   //dogs are better than cats 
    if(Controller1.ButtonR2.pressing()) {
      leftintake.spin(vex::directionType::fwd, 200, vex::velocityUnits::pct);
      rightintake.spin(vex::directionType::fwd, 200, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonR1.pressing()) {
      
      leftintake.spin(vex::directionType::rev, 200, vex::velocityUnits::pct);
      rightintake.spin(vex::directionType::rev, 200, vex::velocityUnits::pct);
    }
    else{
      
      leftintake.stop(vex::brakeType::brake);
      rightintake.stop(vex::brakeType::brake);      
    }
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
