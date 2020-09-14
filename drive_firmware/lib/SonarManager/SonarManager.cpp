#include <Arduino.h>
#include "Config.h"
#include "SonarManager.h"
#include "Logger.h"
#include <NewPing.h>
#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

NewPing centerSonar(CENTER_SONAR, CENTER_SONAR, SONAR_MAX_DISTANCE);

Logger logger;

ros::NodeHandle sonar_nh;
sensor_msgs::Range range_msg;
ros::Publisher pub_range("roboix/range_data", &range_msg);
char frameid[] = "/sonar_ranger";

int res_center = 0;
unsigned int pingSpeed = 50; 
unsigned long pingTimer; 

void echoCheck()
{
    if (centerSonar.check_timer())
    {
        res_center = centerSonar.ping_result / US_ROUNDTRIP_CM;
        logger.info("distance = ");
        logger.append(res_center);
        logger.appendln("cm");

        range_msg.range = res_center;
        range_msg.header.stamp = sonar_nh.now();
        pub_range.publish(&range_msg);
    }
}

void sonar_mgr_setup(int updateFrequency, int logLevel = LOG_LEVEL_INFO)
{
    logger.setLevel(logLevel);
    logger.setTag("sonar_mgr");
    // freq = updateFrequency;
    pingSpeed = updateFrequency;
    pingTimer = millis();

    sonar_nh.advertise(pub_range);

    range_msg.radiation_type = sensor_msgs::Range::INFRARED;
    range_msg.header.frame_id = frameid;
    range_msg.field_of_view = 0.261799;
    range_msg.min_range = 0.02; 
    range_msg.max_range = 5;
}
void sonar_mgr_run()
{
    if (millis() >= pingTimer){
        pingTimer += pingSpeed;
        centerSonar.ping_timer(echoCheck);
    }
}
