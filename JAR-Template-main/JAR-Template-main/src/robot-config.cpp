#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT11, ratio18_1, true);
motor leftMotorB = motor(PORT12, ratio18_1, false);
motor leftMotorC = motor(PORT13, ratio18_1, true);
motor leftMotorD = motor(PORT14, ratio18_1, false);
motor rightMotorA = motor(PORT5, ratio18_1, false);
motor rightMotorB = motor(PORT4, ratio18_1, true);
motor rightMotorC = motor(PORT3, ratio18_1, false);
motor rightMotorD = motor(PORT2, ratio18_1, true);
motor escalator = motor(PORT7, ratio18_1, false);
motor intake = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out pneumatic = digital_out(Brain.ThreeWirePort.A);
inertial Inertial6 = inertial(PORT6);
motor other = motor(PORT8, ratio18_1, false);
rotation Rotation15 = rotation(PORT15, false);
distance Distance1 = distance(PORT1);
rotation Rotation18 = rotation(PORT18, false);

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