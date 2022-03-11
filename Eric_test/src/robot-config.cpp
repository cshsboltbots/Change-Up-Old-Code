#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFD = motor(PORT19, ratio18_1, false);
motor LBD = motor(PORT18, ratio18_1, false);
motor RFD = motor(PORT20, ratio18_1, true);
motor RBD = motor(PORT17, ratio18_1, true);
motor roller1 = motor(PORT11, ratio6_1, false);
motor roller2 = motor(PORT12, ratio6_1, false);
motor leftintake = motor(PORT2, ratio18_1, false);
motor rightintake = motor(PORT9, ratio18_1, true);

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