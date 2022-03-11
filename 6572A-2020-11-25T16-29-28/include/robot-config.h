using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFDrive;
extern motor RFDrive;
extern motor LBDrive;
extern motor RBDrive;
extern motor RIntake;
extern motor LIntake;
extern motor BRollers;
extern motor TRollers;
extern inertial Inertia;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );