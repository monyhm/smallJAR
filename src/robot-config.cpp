#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFront = motor(PORT11, ratio18_1, true);
motor LeftBack = motor(PORT19, ratio18_1, true);
motor RightFront = motor(PORT2, ratio18_1, false);
motor RightBack = motor(PORT9, ratio18_1, false);
motor Wings = motor(PORT12, ratio18_1, false);
motor Tail = motor(PORT1, ratio36_1, false);
encoder EncoderG = encoder(Brain.ThreeWirePort.G);
encoder EncoderA = encoder(Brain.ThreeWirePort.A);
inertial Inertial6 = inertial(PORT20);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}