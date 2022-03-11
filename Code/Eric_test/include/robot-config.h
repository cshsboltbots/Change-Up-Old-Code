using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFD;
extern motor LBD;
extern motor RFD;
extern motor RBD;
extern motor roller1;
extern motor roller2;
extern motor leftintake;
extern motor rightintake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );