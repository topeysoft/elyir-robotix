#include <Arduino.h>
#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "Config.h"
#include "MotionManager.h"



ros::NodeHandle nh;
int lowSpeed = 110;
int highSpeed = 220;
int noSpeed = 0;
int currentSpeed = 0;

double w_r = 0, w_l = 0;
//wheel_rad is the wheel radius in radians, wheel_sep is disttance btw wheels in meters
double wheel_rad = 0.0325, wheel_sep = 0.295;

void motion_mgr_setSpeed(int speed){
    currentSpeed = speed;
}
void leftFwd(){
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    digitalWrite(LEFT_MOTOR_DIR_2, LOW);
    analogWrite(LEFT_MOTOR_PWM, currentSpeed);
}
void leftRev(){
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    digitalWrite(LEFT_MOTOR_DIR_2, HIGH);
    analogWrite(LEFT_MOTOR_PWM, currentSpeed);
}
void leftStop(){
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    digitalWrite(LEFT_MOTOR_DIR_2, LOW);
    analogWrite(LEFT_MOTOR_PWM, noSpeed);
}
void rightFwd(){
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);
    digitalWrite(RIGHT_MOTOR_DIR_2, LOW);
    analogWrite(RIGHT_MOTOR_PWM, currentSpeed);
}
void rightRev(){
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    digitalWrite(RIGHT_MOTOR_DIR_2, HIGH);
    analogWrite(RIGHT_MOTOR_PWM, currentSpeed);
}
void rightStop(){
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    digitalWrite(RIGHT_MOTOR_DIR_2, LOW);
    analogWrite(RIGHT_MOTOR_PWM, noSpeed);
}
void motion_mgr_turnLeft(){
    leftRev();   
    rightFwd();   
}
void motion_mgr_turnRight(){
    leftFwd();
    rightRev();
}
void motion_mgr_moveForward(){
    leftFwd();
    rightFwd();
}
void motion_mgr_moveBackward(){
    leftRev();
    rightRev();
}
void motion_mgr_stop(){
    leftStop();
    rightStop();
}

void messageCb(const geometry_msgs::Twist &msg)
{

    double speed_ang = msg.angular.z;
    double speed_lin = msg.linear.x;
    w_r = (speed_lin / wheel_rad) + ((speed_ang * wheel_sep) / (2.0 * wheel_rad));
    w_l = (speed_lin / wheel_rad) - ((speed_ang * wheel_sep) / (2.0 * wheel_rad));
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb);

void motion_mgr_setup()
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

    nh.initNode();
    nh.subscribe(sub);
}
void motion_mgr_run()
{
    nh.spinOnce();
}
void motion_mgr_testWheels(int speed)
{
    motion_mgr_stop();
    delay(1000);

    motion_mgr_setSpeed(speed);

    leftFwd();
    delay(2000);

    leftRev();
    delay(2000);
    leftStop();

    rightFwd();
    delay(2000);

    rightRev();
    delay(2000);
    rightStop();
}