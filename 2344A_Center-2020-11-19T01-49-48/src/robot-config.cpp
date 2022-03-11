#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFDrive = motor(PORT12, ratio18_1, true);
motor LBDrive = motor(PORT15, ratio18_1, false);
motor RFDrive = motor(PORT11, ratio18_1, false);
motor RBDrive = motor(PORT14, ratio18_1, true);
motor BRollers = motor(PORT3, ratio6_1, false);
motor TRollers = motor(PORT4, ratio6_1, false);
motor LIntake = motor(PORT5, ratio18_1, false);
motor RIntake = motor(PORT1, ratio18_1, true);
inertial Inertial = inertial(PORT20);
optical LSensor = optical(PORT19);

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