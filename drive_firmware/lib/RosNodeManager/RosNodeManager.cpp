#include <Arduino.h>
#include "Config.h"
#include "RosNodeManager.h"
#include "Logger.h"
#include <NewPing.h>
#include <ros.h>

// #define LED_BUILTIN 2      // Remapping the built-in LED since the NodeMcu apparently uses a different one.
// #define LED_BUILTIN_RED 16 // If using a NodeMcu v1, then there's another red onboard led.

Logger node_logger;
bool _connected  = false;

ros::NodeHandle nh;

void ros_node_mgr_setup(int logLevel = LOG_LEVEL_INFO)
{
    node_logger.setLevel(logLevel);
    node_logger.setTag("ros_node_mgr");
    nh.initNode();
}
void ros_node_mgr_run()
{
    nh.spinOnce();
}

void ros_node_mgr_advertise(ros::Publisher publisher)
{
    nh.advertise(publisher);
}

ros::NodeHandle ros_node_mgr_get_handle()
{
    return nh;
}

bool ros_node_mgr_connected()
{
    // If value changes, notify via LED and console.
    bool connected = nh.connected();
    if (_connected != connected)
    {
        _connected = connected;
        digitalWrite(LED_BUILTIN, !connected); // false -> on, true -> off
        node_logger.infoln(connected ? "ROS connected" : "ROS disconnected");
    }
    return connected;
}

