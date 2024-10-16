using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftMotorA;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorC;
extern motor escalator;
extern controller Controller1;
extern digital_out pneumatic;
extern inertial Inertial9;
extern motor rightMotorB;
extern motor leftMotorB;
extern motor intake;
extern rotation Rotation6;
extern distance Distance3;
extern motor escalator2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );