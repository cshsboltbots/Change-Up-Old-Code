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
#include "RobotState.h"

using namespace vex;

// A global instance of competition
competition Competition;
//Method to calculate the revolutions based on inches
/*static double driveInches(int inches)
{
  double degree = (inches/12.56)*360;
  return degree;
}
*/
motor_group Intakes (RIntake, LIntake);
motor_group Rollers (BRollers, TRollers);
motor_group Driveleft (LBDrive, LFDrive);
motor_group Driveright (RBDrive, RFDrive);
motor_group drivetrain (LBDrive, LFDrive, RBDrive, RFDrive);

/* move_to function inputs:
  11 rows and 11 columns
  move_to(col, row); example:: (5, 4)
*/

double encl = LFDrive.position(turns);
double encr = RFDrive.position(turns);
double rot = Inertia.rotation(degrees);

double ptunedrive;

int PID (double dist, double curr, double p){
  double mtrspeed = p *  (dist - curr);

  double velmax = 90;

  if (mtrspeed > velmax){
    mtrspeed = velmax;
  } 
  
  if (mtrspeed < -velmax){
    mtrspeed = -velmax;
  }

  return (int) mtrspeed; 
} 

double short_error(double cmd, double cur){

  double error = cmd - cur;

  if (error > 180){
    error = error - 360;
  }

  else if (error < -180){
    error = error + 360;
  }

  return error;
}

int Turn_PID (double degrees, double curr_t, double t){

  double error = short_error(degrees, curr_t);

  double mtrspeed = t * error;

  double velmax = 70;

  if (mtrspeed > velmax){
    mtrspeed = velmax;
  } 
  
  else if (mtrspeed < -velmax){
    mtrspeed = -velmax;
  }

  return (int) mtrspeed;
}

int drive(double dist, double hold_angle){
  LFDrive.setPosition(0, turns);
  RFDrive.setPosition(0, turns);
  vex::task::sleep(50);
  double curr = 0;
  ptunedrive = 6;
  double t = 1;
  double variance;
  Brain.Screen.clearScreen();
  Brain.Screen.print("move to: ");
  Brain.Screen.print(dist);
  while (fabs(dist-curr) > 4){
    double lrot = LFDrive.position(turns);
    double rrot = RFDrive.position(turns);
    variance = Inertia.rotation(degrees);

    double ldist = lrot*12.57;
    double rdist = rrot*12.57;

    double turn_error = short_error(hold_angle, variance);
    int lspeed = PID(dist, ldist, ptunedrive) + turn_error;
    int rspeed = PID(dist, rdist, ptunedrive) - turn_error;
    
    curr = (ldist+rdist)/2;

    Driveleft.spin(forward, lspeed, pct);
    Driveright.spin(forward, rspeed, pct);

    robot_pos.Calculate(LFDrive.position(turns), RFDrive.position(turns), Inertia.rotation(degrees));
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("x:");
    Brain.Screen.print(robot_pos.GetX());
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("y:");
    Brain.Screen.print(robot_pos.GetY());
    Brain.Screen.setCursor(3,1);
    Brain.Screen.print("facing:");
    Brain.Screen.print(Inertia.rotation());
    vex::task::sleep(10);
  }
  Driveleft.stop(hold);
  Driveright.stop(hold);
  variance = Inertia.rotation(degrees);
  LFDrive.setPosition(0,turns);
  RFDrive.setPosition(0,turns);
  robot_pos.reset();
  return 1; // void function
}

int turn(int turn_d){
  double curr_t = Inertia.rotation(degrees);
  double turn_tune = 4;
  double variance;
  Brain.Screen.clearScreen();
  Brain.Screen.print("turn to: ");
  Brain.Screen.print(turn_d);
    while(fabs(short_error(turn_d, curr_t)) > 1){
      curr_t = Inertia.rotation(degrees);

      int b_speed = Turn_PID(turn_d, curr_t, turn_tune);

      Driveleft.spin(fwd, b_speed, pct);
      Driveright.spin(reverse, b_speed, pct);
    }
  variance = Inertia.rotation(degrees);
  Driveleft.stop(brake);
  Driveright.stop(brake);
  LFDrive.setRotation(0,turns);
  RFDrive.setRotation(0,turns);
  return 1;
}

struct starting_pos {
  int x;
  int y;
};


int start_x = 7;
int start_y = 11;
int prev_angl = 0;

void move_to(double row ,double col){
  //printf("start: %d %d end %.2f %.2f\n", start_x, start_y, row, col);
  struct starting_pos strt = {start_x, start_y};
  // (x,y)

  // starting postion
  double curr_col = strt.y;
  double curr_row = strt.x;

  // theoretical final destination
  double dest_col = col;
  double dest_row = row;

  double dx = dest_row-curr_row;
  double dy = dest_col-curr_col;

  double dist = sqrt(dy*dy + dx*dx);

  double angl = atan2(dy, dx) * 180.0/M_PI;

  double movement = dist*12;

  if (angl - 180 == prev_angl){
    angl = prev_angl;
    movement = -1*movement;
  }
  //printf("dx: %.2f dy: %.2f angle: %.2f row: %.2f col: %.2f\n", dx, dy, angl, dest_row, dest_col);
  //Brain.Screen.print(angl);
  turn(angl);
  drive(movement, angl);

  strt.x = dest_row;
  strt.y = dest_col;
  start_x = dest_row;
  start_y = dest_col;
  prev_angl = angl;
}



void display_position(){
  //controller display
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("x: ", robot_pos.GetX());
  Controller1.Screen.setCursor(2,1);
  Controller1.Screen.print("y: ", robot_pos.GetY());
  Controller1.Screen.setCursor(3,1);
  Controller1.Screen.print("heading: ", Inertia.rotation());

  //Brain display
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("x: ");
  Brain.Screen.print(robot_pos.GetX());
  Brain.Screen.setCursor(2,1);
  Brain.Screen.print("y: ");
  Brain.Screen.print(robot_pos.GetY());
  Brain.Screen.setCursor(3,1);
  Brain.Screen.print("heading: ");
  Brain.Screen.print(Inertia.rotation());
}



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
 Optical2.setLight(ledState::on);
 Optical7.setLightPower(100,pct);
 Optical7.setLight(ledState::on);
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
Inertia.setHeading(0, degrees);
drive(24, 225);
    turn(225);
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
        TRollers.spin(vex::directionType::fwd, RollerSpeedPCT, vex::velocityUnits::pct);
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
    LFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()/2 + Controller1.Axis1.value()/4), vex::velocityUnits::pct);
    RFDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()/2 - Controller1.Axis1.value()/4), vex::velocityUnits::pct);
    LBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()/2 + Controller1.Axis1.value()/4), vex::velocityUnits::pct);
    RBDrive.spin(vex::directionType::fwd, (Controller1.Axis3.value()/2 - Controller1.Axis1.value()/4), vex::velocityUnits::pct);
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
