#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

vex::motor LFDrive(vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor RFDrive(vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor LBDrive(vex::PORT15, vex::gearSetting::ratio18_1,true);
vex::motor RBDrive(vex::PORT14, vex::gearSetting::ratio18_1,true);
vex::motor RIntake(vex::PORT1, vex::gearSetting::ratio18_1,false);
vex::motor LIntake(vex::PORT5, vex::gearSetting::ratio18_1,false);
vex::motor BRoller(vex::PORT3, vex::gearSetting::ratio18_1,false);
vex::motor TRoller(vex::PORT4, vex::gearSetting::ratio18_1,false);
vex::inertial Inertia(PORT10);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}