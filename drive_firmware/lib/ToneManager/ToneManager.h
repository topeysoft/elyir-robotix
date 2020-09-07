#ifndef _ELYIR_TONE_MGR_
#define _ELYIR_TONE_MGR_
// #include "Notes.h"
#include "Melody.h"

void tone_mgr_playStartup();
void tone_mgr_playShutdown();
void tone_mgr_playMelody(const int melody[], int size, int tempo);
void tone_mgr_setup();

#endif