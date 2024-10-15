using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor leftMotorD;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor rightMotorD;
extern motor escalator;
extern motor intake;
extern controller Controller1;
extern digital_out pneumatic;
extern inertial Inertial6;
extern motor other;
extern rotation Rotation15;
extern distance Distance1;
extern rotation Rotation18;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );