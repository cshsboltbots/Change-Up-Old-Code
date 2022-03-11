using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern optical opti;
extern inertial inert;
extern motor rfdrive;
extern motor rbdrive;
extern motor lbdrive;
extern motor lfdrive;
extern motor rintake;
extern motor lintake;
extern motor elevator;
extern motor roller;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );