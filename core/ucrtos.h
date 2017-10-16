#ifndef UCRTOS_H__
#define UCRTOS_H__

#include <stdint.h>

// Timing
uint32_t hal_clock();
void delayUs(uint32_t us);
void delayMs(uint32_t ms);

// LEDs:
void statusLedOn();
void statusLedOff();
void errorLedOn();
void errorLedOff();

// FSM
#include "StackBasedFsm.h"
#include "SlotBasedMenu.h"

// Display:
#include "display.h"
#include "images.h"

// Input device:
#include "InputDevice.h"

// Debug:
void PrintCharUsr(char c);
void errorState();

#endif // UCRTOS_H__
