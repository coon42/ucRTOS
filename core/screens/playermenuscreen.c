#include "../StackBasedFsm.h"
#include "../../lib/colorprint/colorprint.h"
#include "../display.h"

#include "playermenucreen.h"

static void draw() {
  displayClear();

  displayDrawText(CENTER, 0 + 0 * 18, "Select a song and press 'A'", 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00);
  displayDrawText(CENTER, 0 + 1 * 18, "Press 'Back' button to exit", 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00);

  displayDrawText(CENTER, 0 + 3 * 18, "TODO: add menu entries", 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00);

  displayDraw();
}

static void onEnter(StackBasedFsm_t* pFsm, void* pParams) {
  hal_printf("playerMenuScreen::onEnter()");

  draw();
}

static void onActionPress(StackBasedFsm_t* pFsm) {
  hal_printf("playerMenuScreen::onActionPress()");

  // TODO: play MIDI
}

static void onBackPress(StackBasedFsm_t* pFsm) {
  hal_printf("playerMenuScreen::onBackPress()");

  leaveState(pFsm);
}

static void onStartPress(StackBasedFsm_t* pFsm) {
  hal_printf("playerMenuScreen::onStartPress()");

  // TODO: play MIDI
}

static void onDirectionPress(StackBasedFsm_t* pFsm, bool south, bool north, bool west, bool east) {
  hal_printf("playerMenuScreen::onDirectionPress()");

  // This function is called, if the user presses one of the direction buttons on the game pad.
}

static void onReenter(StackBasedFsm_t* pFsm) {
  hal_printf("playerMenuScreen::onReenter()");

}

// Always implement this as last function of your state file:

void playerMenuScreen(StackBasedFsm_t* pFsm, FsmState* pState) {
  pState->onEnterState    = onEnter;

  // Button press callbacks:
  pState->onActionPress    = onActionPress;
  pState->onBackPress      = onBackPress;
  pState->onStartPress     = onStartPress;
  pState->onDirectionPress = onDirectionPress;

  // State callbacks:
  pState->onReenterState  = onReenter;
}