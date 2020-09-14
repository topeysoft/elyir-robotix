#ifndef _ELYIR_CONFIG_MGR_
#define _ELYIR_CONFIG_MGR_

// #define LEFT_MOTOR_DIR 38
// #define LEFT_MOTOR_PWM 3
// #define RIGHT_MOTOR_DIR 30
// #define RIGHT_MOTOR_PWM 2

const uint8_t LEFT_MOTOR_DIR = 8;
const uint8_t LEFT_MOTOR_DIR_2 = 9;
const uint8_t LEFT_MOTOR_PWM = 10;
const uint8_t RIGHT_MOTOR_DIR = 13;
const uint8_t RIGHT_MOTOR_DIR_2 = 12;
const uint8_t RIGHT_MOTOR_PWM = 11;

const uint8_t BUZZER = 5;
const uint8_t CENTER_SONAR = 6;

const uint8_t CHARGER_SENSOR = A0;
const uint8_t BATTERY_SENSOR = A1;

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

const int SONAR_MAX_DISTANCE = 300;
const int SONAR_DEFAULT_DISTANCE = 1000;
const int SONAR_PING_FREQUENCY = 50;

template <typename T, int sz>
int size(T (&)[sz])
{
    return sz;
}

#define SINGLE_DIR_DRIVER false

#endif