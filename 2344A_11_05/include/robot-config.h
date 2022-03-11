using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFDrive;
extern motor LBDrive;
extern motor RFDrive;
extern motor RBDrive;
extern motor BRollers;
extern motor TRollers;
extern motor LIntake;
extern motor RIntake;
extern inertial Inertial;
extern optical LSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );