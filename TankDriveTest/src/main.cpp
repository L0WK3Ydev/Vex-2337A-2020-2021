/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftBack             motor         1               
// RightBack            motor         10              
// ClawMotor            motor         3               
// ArmMotor             motor         8               
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
    // Get the velocity percentage of the left motors. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motors. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();

    // Set the speed of the left motors. If the value is less than the deadband, set the speed of the motors to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed of the LeftFront and LeftBack motors to zero.
      LeftBack.setVelocity(0, percent);
      LeftFront.setVelocity(0,percent);
    } else {
      // Set the speed of the left motors to leftMotorSpeed.
      LeftBack.setVelocity(leftMotorSpeed, percent);
      LeftFront.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motors. If the value is less than the deadband, set the speed of the motors to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed of the RightFront and RightBack motors to zero.
      RightBack.setVelocity(0, percent);
      RightFront.setVelocity(0, percent);
    } else {
      // Set the speed of the right motors to rightMotorSpeed.
      RightBack.setVelocity(rightMotorSpeed, percent);
      RightFront.setVelocity(rightMotorSpeed, percent);
    }

    // Spin all four motors in the forward direction.
    LeftFront.spin(forward);
    LeftBack.spin(forward);
    RightFront.spin(forward);
    RightBack.spin(forward);

    wait(25, msec);
  }
}
