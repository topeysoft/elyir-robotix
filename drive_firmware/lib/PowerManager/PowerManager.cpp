#include <Arduino.h>
#include "Config.h"
#include "PowerManager.h"
#include "Logger.h"
#include <std_msgs/String.h>

// ros::NodeHandle nh;

// std_msgs::String str_msg;

// ros::Publisher status("/status/battery", &str_msg);


// template <typename T>
//  void log(T data)
// {
//     if(doLog){
//         Serial.print(data);
//     }
// }

// template <typename T>
//  void logln(T data)
// {
//     if (doLog)
//     {
//         Serial.println(data);
//     }
// }
// void log()
// {
//     log("");
// }

// void logln()
// {
//     logln("");
// }

Logger _logger;
float readAvg(int pin){
    float v = 0;
    int sample_size = 10;
    int i = 0;
    while (i < sample_size)
    {
        v += analogRead(pin);
        i++;
    }
    return ((v / sample_size) * 5.015) / 1024.0;
}

float getActualVoltage(float R1, float R2, float Vout)
{
    // Vin = (Vout * (R1+R2)) / R2
     return (Vout * (R1+R2)) / R2;

}


void power_mgr_getBatteryVoltage(){
    float vA = getActualVoltage(BATTERY_SENSOR_R1, BATTERY_SENSOR_R2, readAvg(BATTERY_SENSOR));
    if (vA < BATTERY_VMIN)
    {
        _logger.debug("Battery low: ");
        _logger.appendln(vA);
        _logger.appendln("");
    }
    if (vA >= BATTERY_VMAX)
    {
        _logger.debug("Battery Full: ");
        _logger.appendln(vA);
    }
}
void power_mgr_getChargerVoltage()
{
    float vA = getActualVoltage(CHARGER_SENSOR_R1, CHARGER_SENSOR_R2, readAvg(CHARGER_SENSOR));
    if (vA< CHARDER_DISCONNECTED_VOLTAGE)
    {
        _logger.debug("Charger Disconnected: ");
        _logger.append(vA);
        _logger.appendln("");
    }
}

void monitor_battery(){
    power_mgr_getBatteryVoltage();
}
void monitor_charger(){
    power_mgr_getChargerVoltage();
}

void power_mgr_setup(int logLevel = LOG_LEVEL_DEBUG)
{
    pinMode(CHARGER_SENSOR, INPUT);
    pinMode(BATTERY_SENSOR, INPUT);
    _logger.setTag("power_mgr");
    _logger.setLevel(logLevel);
    // nh.initNode();
    // nh.advertise(status);
}
void power_mgr_run()
{
    monitor_battery();
    monitor_charger();
    // str_msg.data = hello;
    // status.publish(&str_msg);
    // nh.spinOnce();
}
