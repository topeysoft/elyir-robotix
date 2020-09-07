#ifndef _ELYIR_CONFIG_MGR_
#define _ELYIR_CONFIG_MGR_

// #define LEFT_MOTOR_DIR 38
// #define LEFT_MOTOR_PWM 3
// #define RIGHT_MOTOR_DIR 30
// #define RIGHT_MOTOR_PWM 2

const int LEFT_MOTOR_DIR = 8;
const int LEFT_MOTOR_DIR_2 = 9;
const int LEFT_MOTOR_PWM = 10;
const int RIGHT_MOTOR_DIR = 13;
const int RIGHT_MOTOR_DIR_2 = 12;
const int RIGHT_MOTOR_PWM = 11;

const int BUZZER = 5;

const int CHARGER_SENSOR = A0;
const int BATTERY_SENSOR = A1;

const float CHARGER_SENSOR_R1 = 47.0;
const float CHARGER_SENSOR_R2 = 6.612;
// const float CHARGER_SENSOR_R2 = 6.8;
const float CHARDER_MIN_VOLTAGE = 8.4;
const float CHARDER_DISCONNECTED_VOLTAGE = 2.5;

const float BATTERY_SENSOR_R1 = 10.0;
const float BATTERY_SENSOR_R2 = 3.023;
// const float BATTERY_SENSOR_R2 = 2.139;
// const float BATTERY_SENSOR_R2 = 6.8;
const int BATTERY_VMAX = 8.4;
const int BATTERY_VMIN = 7.4;



template <typename T, int sz>
int size(T (&)[sz])
{
    return sz;
}

#define SINGLE_DIR_DRIVER false

#endif