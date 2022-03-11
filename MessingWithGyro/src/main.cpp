/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  Accurate Turns                                            */
/*                  This program will use the Gyro to make a 90 degree turn.  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1
// RightMotor           motor         10
// GyroD                gyro          D
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Calibrate the Gyro, and wait for it to finish.
  GyroD.calibrate();
  waitUntil(!GyroD.isCalibrating());

  // Set the Gyro's heading to 0.
  GyroD.setHeading(0, degrees);

  // Turn right by spinning the LeftMotor forward and the RightMotor reverse.
  LeftMotor.spin(forward);
  RightMotor.spin(reverse);

  // Wait until the Gyro's heading is greater than 90 degrees.
  waitUntil(GyroD.heading() > 90);

  // Stop both motors.
  LeftMotor.stop();
  RightMotor.stop();
}
