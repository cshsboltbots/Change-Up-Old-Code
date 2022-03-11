#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

vex::motor LFDrive(vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor RFDrive(vex::PORT12, vex::gearSetting::ratio18_1,true);
vex::motor LBDrive(vex::PORT15, vex::gearSetting::ratio18_1,false);
vex::motor RBDrive(vex::PORT14, vex::gearSetting::ratio18_1,true);
vex::motor RIntake(vex::PORT1, vex::gearSetting::ratio18_1,true);
vex::motor LIntake(vex::PORT5, vex::gearSetting::ratio18_1,false);
vex::motor BRollers(vex::PORT3, vex::gearSetting::ratio18_1,false);
vex::motor TRollers(vex::PORT4, vex::gearSetting::ratio18_1,false);
vex::inertial Inertia(PORT10);
vex::controller Controller1= controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}