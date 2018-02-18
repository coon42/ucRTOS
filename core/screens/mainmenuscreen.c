#include "../../lib/colorprint/colorprint.h"
#include "../display.h"
#include "../SlotBasedMenu.h"

#include "aboutscreen.h"
#include "_examplescreen.h"
#include "mainmenuscreen.h"

// TODO: Rename state to screen?

//--------------------------------------------------------------------------------------------------------------
// Example state implementation
// ============================
//
// This example shows, how to implement a state.
//
// - A state has always its own file, which consists of a collection of callbacks.
// - The onEnter() callback must be set. All other callbacks are optional.
// - At the end of the file there is always an initialization function, which activates the state by setting
//   the callbacks.
// - The context struct can be used to store local variables. If this state gets called multiple times in a
//   state chain, an array of contexts can be used, to get an own context for each state.
//--------------------------------------------------------------------------------------------------------------

static struct {
  SlotBasedMenu_t menu;

} _context;

static void draw() {
  displayClear(0x00, 0x00, 0x00);
  displayDrawText(CENTER, 0 + 0, "Welcome to ucRTOS", 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00);
  displayDrawText(CENTER, 0 + 18, "This is a test screen", 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00);

  menuDraw(&_context.menu);
  displayDraw();
}

static void onEnter(StackBasedFsm_t* pFsm, void* pParams) {
  hal_printf("mainMenuScreen::onEnter()");

  userMenuInit(&_context.menu, pFsm, 3, 45);
  menuAddSlot(&_context.menu, "Button Test", 0);
  menuAddSlot(&_context.menu, "Example", exampleScreen);
  menuAddSlot(&_context.menu, "About", aboutScreen);

  draw();
}

static void onActionPress(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onActionPress()");

  userMenuTransitToSelectedSlot(&_context.menu, 0);
}

static void onBackPress(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onBackPress()");

  userMenuTransitBack(&_context.menu);
}

static void onStartPress(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onStartPress()");

  // This function is called, when the player presses the Start button on the Gamepad.
}

static void onSelectPress(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onSelectPress()");

  // This function is called, when the player presses the Select button on the Gamepad.
}

static void onDirectionPress(StackBasedFsm_t* pFsm, bool south, bool north, bool west, bool east) {
  hal_printf("mainMenuScreen::onDirectionPress()");

  if (south)
    menuMoveCursorDown(&_context.menu);

  if (north)
    menuMoveCursorUp(&_context.menu);

  draw();
}

static void onActionRelease(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onActionRelease()");

  // This function is called, when the player releases the action button on the game pad.
  // On the NES game pad this is the 'A' button.
}

static void onBackRelease(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onBackRelease()");

  // This function is called, when the player releases the back button on the Gamepad.
  // On the NES game pad this is the 'B' button.
}

static void onStartRelease(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onStartRelease()");

  // This function is called, when the player releases the Start button on the Gamepad.
}

static void onSelectRelease(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onSelectRelease()");

  // This function is called, when the player releases the Select button on the Gamepad.
}

static void onReenter(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onReenter()");

  draw();
}

static void onLeaveState(StackBasedFsm_t* pFsm) {
  hal_printf("mainMenuScreen::onLeaveState()");

  // This function is called, when the user leaves the current state. Either by going to a next state or by
  // going back to the previous state.
}

static void onTick(StackBasedFsm_t* pFsm) {
  // hal_printf("mainMenuScreen::onTick()");

  // This function is called frequently as fast as possible, as long as this state is active. This state can be
  // used for time critical applications like animations, audio playback or advanced user interaction.
}

// Always implement this as last function of your state file:

void mainMenuScreen(StackBasedFsm_t* pFsm, FsmState* pState) {
  // This callback MUST be set:
  pState->onEnterState    = onEnter;

  // The following callbacks are all optional:

  // Button press callbacks:
  pState->onActionPress    = onActionPress;
  pState->onBackPress      = onBackPress;
  pState->onStartPress     = onStartPress;
  pState->onSelectPress    = onSelectPress;
  pState->onDirectionPress = onDirectionPress; // TODO: implement onDirectionRelease()

  // Button release callbacks
  pState->onActionRelease = onActionRelease;
  pState->onBackRelease   = onBackRelease;
  pState->onStartRelease  = onStartRelease;
  pState->onSelectRelease = onSelectRelease;

  // State callbacks:
  pState->onReenterState  = onReenter;
  pState->onLeaveState    = onLeaveState;
  pState->onTick          = onTick;
}