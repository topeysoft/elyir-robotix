
#ifndef _ELYIR_MOTION_MGR_
#define _ELYIR_MOTION_MGR_
void motion_mgr_setup();
void motion_mgr_run();

void motion_mgr_turnLeft();
void motion_mgr_turnRight();
void motion_mgr_moveForward();
void motion_mgr_moveBackward();
void motion_mgr_setSpeed(int speed);
void motion_mgr_stop();
void motion_mgr_testWheels(int speed);

#endif