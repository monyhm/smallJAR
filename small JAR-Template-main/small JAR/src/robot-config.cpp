#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT2, ratio18_1, false);
motor leftMotorC = motor(PORT5, ratio18_1, false);
motor rightMotorA = motor(PORT11, ratio18_1, true);
motor rightMotorC = motor(PORT1, ratio18_1, true);
motor escalator = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out pneumatic = digital_out(Brain.ThreeWirePort.A);
inertial Inertial9 = inertial(PORT9);
motor rightMotorB = motor(PORT12, ratio18_1, false);
motor leftMotorB = motor(PORT4, ratio18_1, true);
motor intake = motor(PORT14, ratio18_1, false);
rotation Rotation6 = rotation(PORT6, false);
distance Distance3 = distance(PORT3);
motor escalator2 = motor(PORT10, ratio18_1, true);

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