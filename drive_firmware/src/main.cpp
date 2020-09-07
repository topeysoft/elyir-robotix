#include "Arduino.h"
#include "MotionManager.h"
#include "Config.h"
#include "ToneManager.h"
#include "PowerManager.h"

void setup()
{
    Serial.begin(9600);
    motion_mgr_setup();
    power_mgr_setup(false);
    tone_mgr_setup();
    // int test[] = {455, 6, 2899, 4};
    // tone_mgr_playMelody(test, 85);
    tone_mgr_playStartup();
    // motion_mgr_testWheels(200);
}

void loop()
{
    motion_mgr_run();
    power_mgr_run();
    
    delay(20);
}
