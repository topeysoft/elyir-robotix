#ifndef _ELYIR_POWER_MGR_
#define _ELYIR_POWER_MGR_

void power_mgr_getBatteryVoltage();
void power_mgr_getChargerVoltage();
void power_mgr_setup(int logLevel);
void power_mgr_run();

#endif