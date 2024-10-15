#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT11, ratio18_1, false);
motor leftMotorC = motor(PORT13, ratio18_1, false);
motor rightMotorA = motor(PORT1, ratio18_1, true);
motor rightMotorC = motor(PORT3, ratio18_1, false);
motor escalator = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out pneumatic = digital_out(Brain.ThreeWirePort.A);
inertial Inertial10 = inertial(PORT10);
motor rightMotorB = motor(PORT2, ratio18_1, true);
motor leftMotorB = motor(PORT12, ratio18_1, true);
motor intake = motor(PORT5, ratio18_1, false);
rotation Rotation20 = rotation(PORT20, false);
distance Distance6 = distance(PORT6);

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