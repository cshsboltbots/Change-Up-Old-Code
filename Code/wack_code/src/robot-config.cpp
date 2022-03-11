#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
optical opti = optical(PORT15);
inertial inert = inertial(PORT16);
motor rfdrive = motor(PORT20, ratio18_1, true);
motor rbdrive = motor(PORT17, ratio18_1, true);
motor lbdrive = motor(PORT4, ratio18_1, false);
motor lfdrive = motor(PORT5, ratio18_1, false);
motor rintake = motor(PORT18, ratio18_1, false);
motor lintake = motor(PORT19, ratio18_1, true);
motor elevator = motor(PORT10, ratio18_1, false);
motor roller = motor(PORT9, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}