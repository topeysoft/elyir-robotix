#include "Arduino.h"
#include "MotionManager.h"
#include "Config.h"
#include "ToneManager.h"
#include "Logger.h"
#include "SonarManager.h"
#include "PowerManager.h"
#include "RosNodeManager.h"

void send(String data){
    if (Serial.available() > 0)
    {
        String data = Serial.readStringUntil('\n');
        Serial.print("You sent me: ");
        Serial.println(data);
    }
}
void onReceive(String data)
{
    if (Serial.available() > 0)
    {
        String data = Serial.readStringUntil('\n');
        Serial.print("You sent me: ");
        Serial.println(data);
    }
}

void setup()
{
    Serial.begin(9600);
    // ros_node_mgr_setup(LOG_LEVEL_ALL);
    motion_mgr_setup(LOG_LEVEL_ALL);
    power_mgr_setup(LOG_LEVEL_NONE);
    sonar_mgr_setup(30, LOG_LEVEL_NONE);
    tone_mgr_setup();
    // int test[] = {455, 6, 2899, 4};
    // tone_mgr_playMelody(test, 85);
    // tone_mgr_playStartup();
    // motion_mgr_testWheels(120);
    // motion_mgr_setSpeed(400);
    // motion_mgr_moveForward();
}

void loop()
{
    motion_mgr_run();
    power_mgr_run();
    sonar_mgr_run();
    // ros_node_mgr_run();
    Serial.println(data);
    delay(20);
}


