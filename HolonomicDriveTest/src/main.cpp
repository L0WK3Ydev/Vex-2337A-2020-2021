
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftBack             motor         1               
// RightBack            motor         10              
// LeftFront            motor         2               
// RightFront           motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  // Loop the Driver-control code so it runs forever until the script is killed.
  while (true) {
    
    // Get the velocity percentage for all of the motors for each movement made by the robot.
    int LeftFrontSpeed = Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value();
    int LeftBackSpeed = Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value();
    int RightFrontSpeed = Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value();
    int RightBackSpeed = Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value();

    // Robot Holonomic Setup

    // If the value of the deadband is greater than the value of the controller joystick values, then set the velocity of the motor to zero.
    if (abs(LeftFrontSpeed) < deadband) {

     // Set the velocity of the LeftFront motor to zero if the condition above is true.
     LeftFront.setVelocity(0, percent);


     // If the value of the deadband is greater than the value of the controller joystick values, then set the velocity of the motor to zero.
    } else if (abs(LeftBackSpeed) < deadband) {

     // Set the velocity of the LeftBack motor to zero if the condition above is true.
     LeftBack.setVelocity(0, percent);


     // If the value of the deadband is greater than the value of the controller joystick values, then set the velocity of the motor to zero. 
    } else if (abs(RightFrontSpeed) < deadband) {

     // Set the velocity of the RightFront motor to zero if the condition above is true.
     RightFront.setVelocity(0, percent);


     // If the value of the deadband is greater than the value of the controller joystick values, then set the velocity of the motor to zero.
    } else if (abs(RightBackSpeed) < deadband) {

      // Set the velocity of the RightBack motor to zero if the condition above is true.
      RightBack.setVelocity(0, percent);

      
     // If the value of the joysick values is greater than the deadband, set the velocity of the motors to what the value of the joysticks are.
    } else {

     // Set the speed of all the motors to move in the direction that the driver choooses.
     // Move the left joystick forward, robot moves forward. Move the right joystick to the right, robot turns to the right in a clockwise motion.  
     LeftFront.setVelocity(LeftFrontSpeed, percent);
     LeftBack.setVelocity(LeftBackSpeed, percent);
     RightFront.setVelocity(RightFrontSpeed, percent);
     RightBack.setVelocity(RightBackSpeed, percent); 

    }
    
    /* Robot Holonomic Setup
    LeftFront.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value()), velocityUnits::pct);
    LeftBack.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value()), velocityUnits::pct);
    RightFront.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value()), velocityUnits::pct);
    RightBack.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value()), velocityUnits::pct);*/

    

    // Spin all four motors in the forward direction.
    LeftFront.spin(forward);
    LeftBack.spin(forward);
    RightFront.spin(forward);
    RightBack.spin(forward);

    wait(25, msec);
  }
}
