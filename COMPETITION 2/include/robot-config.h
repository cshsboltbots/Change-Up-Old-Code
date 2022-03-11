using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lfdrive;
extern motor rfdrive;
extern motor lbdrive;
extern motor rbdrive;
extern motor RIntake;
extern motor LIntake;
extern motor BRollers;
extern motor TRollers;
extern inertial inert;
extern optical Optical2;
extern optical Optical8;
extern optical Optical7;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );