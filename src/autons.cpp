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

  // push triballs
  // Wings.spin(forward);
  // wait(0.2,seconds);
  // Wings.stop();


  chassis.set_coordinates(19.5, 15.5, 45);
  chassis.drive_to_point(40, 11.5);
  chassis.drive_to_point(106.5, 11.5);
  chassis.turn_to_angle(100);

  chassis.drive_distance(80);
  // chassis.drive_to_point(129, 29);


  // push triballs into goal
  chassis.turn_to_angle(10);
  // Wings.spinFor(reverse, 45, degrees);

  chassis.drive_distance(25);
  chassis.drive_distance(-20);
  chassis.drive_distance(25);
  chassis.drive_distance(-20);
  chassis.drive_distance(25);
  chassis.drive_distance(-20);

  chassis.turn_to_angle(90);
  chassis.drive_to_point(100,38);
  chassis.drive_to_point(80,36);


  Tail.spin(forward);
  wait(0.5, seconds);
  Tail.stop();


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
    // Brain.Screen.clearScreen();
    // Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    // Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    // Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    // Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    // Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
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




void update_odometry_map(){ 
     /*--------------------maping GRAPHICS--------------------*/
    //Coordinates for each section of text
    int textadjustvalue = 55;
    int rowadjust = 39;

    Brain.Screen.clearScreen();

    //Sets graphical things for our display 
    Brain.Screen.setPenWidth( 1 );
    vex::color redtile = vex::color( 210, 31, 60 );
    vex::color bluetile = vex::color( 14, 77, 146 );
    vex::color graytile = vex::color( 49, 51, 53 );
    Brain.Screen.setFillColor(vex::color( 0, 0, 0 ));
    Brain.Screen.setFont(vex::fontType::mono20);
    Brain.Screen.setPenColor( vex::color( 222, 49, 99 ) );

    // Displays all the field tiles, text of odom values, and a dot symbolizing the robot
    Brain.Screen.printAt(40,20 + textadjustvalue, "X-Pos:%f",chassis.get_X_position());
    Brain.Screen.setPenColor( vex::color( 191, 10, 48 ) );
    Brain.Screen.printAt(40,50 + textadjustvalue, "Y-Pos:%f",chassis.get_Y_position());
    Brain.Screen.setPenColor( vex::color( 191, 10, 48 ) );
    Brain.Screen.printAt(40,80 + textadjustvalue, "Theta:%f",chassis.get_absolute_heading());
    Brain.Screen.setPenColor( vex::color( 191, 10, 48 ) );
    Brain.Screen.printAt(40,110 + textadjustvalue, "Angle:%f",chassis.get_absolute_heading()*57.295779513);
    Brain.Screen.setPenColor( vex::color( 150, 10, 48 ) );
    Brain.Screen.setFillColor( graytile );
    Brain.Screen.drawRectangle( 245, 2, 234, 234 );
    Brain.Screen.drawRectangle( 245, 2, 39, 39 );
    Brain.Screen.drawRectangle( 245, 80, 39, 39 );
    Brain.Screen.drawRectangle( 245, 119, 39, 39 );
    Brain.Screen.drawRectangle( 245, 197, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 2, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 80, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 119, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 158, 39, 39 );
    Brain.Screen.drawRectangle( 245+rowadjust, 197, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 2, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 80, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 119, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 158, 39, 39 );
    Brain.Screen.drawRectangle( 245+(2*rowadjust), 197, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 2, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 80, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 119, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 158, 39, 39 );
    Brain.Screen.drawRectangle( 245+(3*rowadjust), 197, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 2, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 80, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 119, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 158, 39, 39 );
    Brain.Screen.drawRectangle( 245+(4*rowadjust), 197, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 2, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 80, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 119, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 197, 39, 39 );
    Brain.Screen.drawRectangle( 245, 158, 39, 39 );
    Brain.Screen.drawRectangle( 245, 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 41, 39, 39 );
    Brain.Screen.drawRectangle( 245+(5*rowadjust), 158, 39, 39 );
    Brain.Screen.setPenColor( vex::color( 255,255,255));
    Brain.Screen.setFillColor( vex::color(0,0,0) );
    Brain.Screen.setPenWidth(2);

    //the blue borders
     Brain.Screen.setPenColor(blue);
    Brain.Screen.drawLine(245,80,245+2*rowadjust,80);
    Brain.Screen.drawLine(245+2*rowadjust,2,245+2*rowadjust,80);

    //the red borders
    Brain.Screen.setPenColor(red);
    Brain.Screen.drawLine(245+4*rowadjust,158,245+6*rowadjust,158);
    Brain.Screen.drawLine(245+4*rowadjust,158,245+4*rowadjust,197+39);

    //the white lines in the middle
    Brain.Screen.setPenWidth(1);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawLine(245+5*rowadjust+33,2,245,197+33);
    Brain.Screen.drawLine(245+5*rowadjust+40,6,245+7,197+35);

    //the red goal
    Brain.Screen.setPenWidth(3);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.setPenColor(red);
    Brain.Screen.drawCircle(245+36,36,15);

    //the blue goal
    Brain.Screen.setPenWidth(3);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.setPenColor(blue);
    Brain.Screen.drawCircle(245+42+4*rowadjust,200,15);
   
    //This draws the robot body for position and arm for angle
    double yfieldvalue = ((-chassis.get_Y_position())*1.66548042705 )+245-10; // 1.66548042705 is scale from inch to pixel
    double xfieldvalue = ((chassis.get_X_position())*1.66548042705 )+245;
    Brain.Screen.drawCircle(xfieldvalue, yfieldvalue, 10 );
    Brain.Screen.setPenWidth( 4 );
    // Line angle calculation:
    // x1 and y1 are the robot's coordinates, which in our case is xfieldvalue and yfieldvalue
    // angle is the angle the robot is facing, which in our case is Theta
    // (x1,y1, x1 + line_length*cos(angle),y1 + line_length*sin(angle)) = (x1,y1,x2,y2)
    Brain.Screen.drawLine(xfieldvalue, yfieldvalue, xfieldvalue+cos(chassis.get_absolute_heading())*15, yfieldvalue+sin(chassis.get_absolute_heading()) *15);
    Brain.Screen.render();
}


int update_screen(){
  while(1){
    update_odometry_map();
    this_thread::sleep_for(500);
  }
  return 0;
}