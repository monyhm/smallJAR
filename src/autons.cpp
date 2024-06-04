#include "vex.h"
void auton(){
  Inertial6.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inertial6.isCalibrating()) {
	wait(100, msec);
  }
  Tail.setPosition(0,degrees);
  Wings.setPosition(0,degrees);
  Tail.setVelocity(100,percent);
  Wings.setVelocity(50,percent);
  Wings.setBrake(hold);
  /*
  for(int i=0; i<=10; i++)
  {
    Tail.spinToPosition(140, degrees);
    Tail.spinToPosition(0, degrees);
    wait(1, sec);
  }
  */
  Wings.spinToPosition(90, degrees);
  Wings.setBrake(hold);
  chassis.set_coordinates(19.5, 15.5, -45);
  chassis.drive_to_point(11.5, 40);
  chassis.drive_to_point(11.5, 106.5);
  chassis.drive_to_point(29, 129);
  //chassis.turn_to_angle(-35);
  //chassis.drive_to_point(0, 127);
  //chassis.turn_to_angle(-90);
  /*
  for(int i=0; i<=4; i++){
    chassis.drive_distance(20);
    chassis.drive_to_point(0, 127);
    chassis.turn_to_angle(-90);
  }
  */
  /*
  chassis.set_coordinates(19, 16, 45);
  Tail.setVelocity(100,percent);
  Wings.setVelocity(50,percent);
  Tail.setPosition(0,degrees);
  Wings.setPosition(0,degrees);
  Wings.setBrake(hold);
  
  // load triballs
  for (int i = 0; i<10; i++){
    Tail.spin(forward);
    wait(0.5, seconds);
    Tail.spinFor(reverse,155,degrees);
    wait(0.8, seconds);
  }
  Tail.spin(reverse);
  wait(0.1, seconds);
  Tail.stop();



  chassis.drive_to_point(33, 11);
  chassis.drive_to_point(99, 11);
  Wings.spinFor(forward,50,degrees);
  chassis.drive_distance(70, 110);
  Wings.spinFor(reverse,50,degrees);

  chassis.drive_to_point(130, 35);
  chassis.drive_distance(5);
  chassis.drive_distance(-5);
  chassis.drive_distance(5);
  chassis.drive_distance(-5);




  chassis.drive_to_point(100, 30);
  chassis.turn_to_angle(-45);
  chassis.drive_to_point(77, 66);
  chassis.turn_to_angle(90);
  chassis.drive_to_point(115, 66);
  chassis.drive_to_point(100, 66);
  chassis.drive_to_point(115, 66);




*/
}

void default_constants(){
  chassis.set_drive_constants(12, 1, 0.0001, 2, 0);
  chassis.set_heading_constants(12, .4, 0.001, 1, 0);
  chassis.set_turn_constants(12, 0.19, .01, 0.5, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(5, 500, 3000);
  chassis.set_turn_exit_conditions(5, 300, 2000);
  chassis.set_swing_exit_conditions(1, 300, 2000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 5;
}

void drive_test(){
  chassis.drive_distance(20);
  chassis.drive_distance(-20);
  //chassis.drive_distance(10);
  //chassis.drive_distance(12);
  //chassis.drive_distance(18);
  //chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(20, 20);
  chassis.drive_to_point(20,20);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}