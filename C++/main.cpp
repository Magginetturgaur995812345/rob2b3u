/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Mon Mar 25 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// Drive Forward
// This program instructs your robot to move forward at half power for three
// seconds. There is a two second pause at the beginning of the program.
//
// Robot Configuration: 
// [Smart Port]    [Name]        [Type]           [Description]       [Reversed]
// Motor Port 1    LeftMotor     V5 Smart Motor    Left side motor     false
// Motor Port 10   RightMotor    V5 Smart Motor    Right side motor    true
//
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::motor leftMotor   = vex::motor( vex::PORT1 );
vex::motor backleftMotor = vex::motor( vex::PORT2 );
vex::motor rightMotor  = vex::motor( vex::PORT10, true );
vex::motor backrightMotor = vex::motor( vex::PORT7, true);
controller Controller1 = vex::controller();

int main() {
    // Wait 2 seconds or 2000 milliseconds before starting the program.
    vex::task::sleep( 2000 );
    // Print to the screen that the program has started.
    Brain.Screen.print("User Program has Started. yeet");
    
    // Set the velocity of the left and right motors to 50% power. 
    // This command will not make the motor spin.
    leftMotor.setVelocity( 50, vex::velocityUnits::pct );
    rightMotor.setVelocity( 50, vex::velocityUnits::pct );
    backleftMotor.setVelocity( 50, vex::velocityUnits::pct);
    backrightMotor.setVelocity( 50, vex::velocityUnits::pct);
    int xd = 1;
    while(xd) {
      //Drive Control

      //god help me
      backleftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() + Controller1.Axis4.position())/2, vex::velocityUnits::pct);
      leftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() + Controller1.Axis4.position())/2, vex::velocityUnits::pct);
      rightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() - Controller1.Axis4.position())/2, vex::velocityUnits::pct);
      backrightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.position() - Controller1.Axis4.position())/2, vex::velocityUnits::pct);
      vex::task::sleep(20);
      if (Controller1.ButtonX.pressing()){
        xd = 0; //þetta er ógjéðslegasta leið í heimi xd
      }
    }
    
    // Stop all motors.
    backleftMotor.stop();
    leftMotor.stop();
    backrightMotor.stop();
    rightMotor.stop();
    
    // Print to the brain's screen that the program has ended.
    Brain.Screen.newLine();//Move the cursor to a new line on the screen. 
    Brain.Screen.print( "PROGRAM TERMINATED" );
    //this bitch builded on 12.9.2019 at 14:42
}
