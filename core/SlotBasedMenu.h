#ifndef __SLOT_BASED_FSM_H
#define __SLOT_BASED_FSM_H

#include <stdint.h>
#include "StackBasedFsm.h"
#include "config.h"

#define MENU_MAX_SLOTS 12

typedef enum {
  INVALID_SLOT;
  TRANSIT_SLOT;
} SlotType_t;

typedef struct {
  char pLabel[MAX_MENU_ITEM_CHARS];
  TransitionFunc pNextStateTransitionFunc;
} MenuSlot_t;

typedef void (*BrowseNewPageCallback)(int currentPage, int totalPages);

// settings menu callbacks
typedef void(*SettingsMenuSaveCallback)();
typedef void(*SettingsMenuCancelCallback)();

typedef struct {
  uint16_t xPos;
  uint16_t yPos;
  uint8_t numSlots;
  uint8_t cursorPos;
  StackBasedFsm_t* pFsm;
  MenuSlot_t slot[MENU_MAX_SLOTS];
} SlotBasedMenu_t;

// general menu functions
void userMenuInit(SlotBasedMenu_t* pSbm, StackBasedFsm_t* pFsm, int16_t xPos, int16_t yPos);
void menuTick(SlotBasedMenu_t* sbm);
void menuAddSlot(SlotBasedMenu_t* pSbm, const char* label, TransitionFunc pFunc);
void menuDraw(SlotBasedMenu_t* sbm);
void menuMoveCursorUp(SlotBasedMenu_t* sbm);
void menuMoveCursorDown(SlotBasedMenu_t* sbm);

// user menu specific functions
void userMenuTransitToSelectedSlot(SlotBasedMenu_t* pMenu, void* pArgs);
void userMenuTransitBack(SlotBasedMenu_t* pMenu);

#endif // __SLOT_BASED_FSM_H
