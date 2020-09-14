#include <Arduino.h>
#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "Config.h"
#include "MotionManager.h"
#include "RosNodeManager.h"
#include "Logger.h"

// The min amount of PWM the motors need to move. Depends on the battery, motors and controller.
// The max amount is defined by PWMRANGE in Arduino.h
#define PWMRANGE 1024
#define PWM_MIN 300

int lowSpeed = 110;
int highSpeed = 220;
int noSpeed = 0;
int currentSpeed = 0;

Logger motion_mgr_logger;

double w_r = 0, w_l = 0;
//wheel_rad is the wheel radius in radians, wheel_sep is disttance btw wheels in meters
double wheel_rad = 0.0325, wheel_sep = 0.295;

// Map x value from [0 .. 1] to [out_min .. out_max]
float mapPwm(float x, float out_min, float out_max)
{
    return x * (out_max - out_min) + out_min;
}

void motion_mgr_setSpeed(int speed){
    currentSpeed = speed;
}
void leftFwd(int speed){
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    digitalWrite(LEFT_MOTOR_DIR_2, LOW);
    analogWrite(LEFT_MOTOR_PWM, speed);
}
void leftRev(int speed)
{
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    digitalWrite(LEFT_MOTOR_DIR_2, HIGH);
    analogWrite(LEFT_MOTOR_PWM, speed);
}
void leftStop(){
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    digitalWrite(LEFT_MOTOR_DIR_2, LOW);
    analogWrite(LEFT_MOTOR_PWM, noSpeed);
}
void rightFwd(int speed)
{
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);
    digitalWrite(RIGHT_MOTOR_DIR_2, LOW);
    analogWrite(RIGHT_MOTOR_PWM, speed);
}
void rightRev(int speed)
{
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    digitalWrite(RIGHT_MOTOR_DIR_2, HIGH);
    analogWrite(RIGHT_MOTOR_PWM, speed);
}
void rightStop(){
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    digitalWrite(RIGHT_MOTOR_DIR_2, LOW);
    analogWrite(RIGHT_MOTOR_PWM, noSpeed);
}
void motion_mgr_turnLeft(){
    leftRev(currentSpeed);
    rightFwd(currentSpeed);
}
void motion_mgr_turnRight(){
    leftFwd(currentSpeed);
    rightRev(currentSpeed);
}
void motion_mgr_moveForward(){
    leftFwd(currentSpeed);
    rightFwd(currentSpeed);
}
void motion_mgr_moveBackward(){
    leftRev(currentSpeed);
    rightRev(currentSpeed);
}
void motion_mgr_stop(){
    leftStop();
    rightStop();
}

void messageCb(const geometry_msgs::Twist &msg)
{

    // double speed_ang = msg.angular.z;
    // double speed_lin = msg.linear.x;
    // w_r = (speed_lin / wheel_rad) + ((speed_ang * wheel_sep) / (2.0 * wheel_rad));
    // w_l = (speed_lin / wheel_rad) - ((speed_ang * wheel_sep) / (2.0 * wheel_rad));

    // Cap values at [-1 .. 1]
    float x = max(min(msg.linear.x, 1.0f), -1.0f);
    float z = max(min(msg.angular.z, 1.0f), -1.0f);

    // Calculate the intensity of left and right wheels. Simple version.
    // Taken from https://hackernoon.com/unicycle-to-differential-drive-courseras-control-of-mobile-robots-with-ros-and-rosbots-part-2-6d27d15f2010#1e59
    float l = (msg.linear.x - msg.angular.z) / 2;
    float r = (msg.linear.x + msg.angular.z) / 2;

    // Then map those values to PWM intensities. PWMRANGE = full speed, while PWM_MIN = the minimal amount of power at which the motors begin moving.
    uint16_t lPwm = mapPwm(fabs(l), PWM_MIN, PWMRANGE);
    uint16_t rPwm = mapPwm(fabs(r), PWM_MIN, PWMRANGE);
    if (l > 0) {
        leftFwd(lPwm);
    } else {
        leftRev(lPwm);
    }
    if (r > 0) {
        rightFwd(rPwm);
    } else {
        rightRev(rPwm);
    }
}

void motion_mgr_setup(uint8_t logLevel)
{
    //initialization of motors
    pinMode(LEFT_MOTOR_DIR, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR, OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
    if(!SINGLE_DIR_DRIVER){
        pinMode(LEFT_MOTOR_PWM, OUTPUT);
        pinMode(RIGHT_MOTOR_PWM, OUTPUT);

        digitalWrite(LEFT_MOTOR_DIR, LOW);
        digitalWrite(RIGHT_MOTOR_DIR, LOW);
        digitalWrite(LEFT_MOTOR_DIR_2, LOW);
        digitalWrite(RIGHT_MOTOR_DIR_2, LOW);
    }

    analogWrite(LEFT_MOTOR_PWM, noSpeed);
    analogWrite(RIGHT_MOTOR_PWM, noSpeed);

    motion_mgr_logger.setTag("power_mgr");
    motion_mgr_logger.setLevel(logLevel);
    ros::Subscriber<geometry_msgs::Twist> sub("robotix/cmd_vel", &messageCb);
    ros_node_mgr_get_handle().subscribe(sub);
}
void motion_mgr_run()
{
    if (!ros_node_mgr_connected())
        motion_mgr_stop();
}
void motion_mgr_testWheels(int speed)
{
    motion_mgr_stop();
    delay(1000);

    motion_mgr_setSpeed(speed);

    leftFwd(speed);
    delay(2000);

    leftRev(speed);
    delay(2000);
    leftStop();

    rightFwd(speed);
    delay(2000);

    rightRev(speed);
    delay(2000);
    rightStop();
}



rostopic pub /robotix/cmd_vel geometry_msgs/Twist "linear:
  x: 0.5
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0" -r 3