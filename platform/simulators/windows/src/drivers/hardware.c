#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "../../core/ucrtos.h"

void statusLedOn() {
  if (GetKeyState(VK_SCROLL) == 1)
    return;

  keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
  keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void statusLedOff() {
  if (GetKeyState(VK_SCROLL) == 0)
    return;

  keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
  keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void PrintCharUsr(char c) {
  putchar(c);
}

// Display:

void mainCreateWxLcdSimulator();
void mainLcdSetPixel(int x, int y, int red, int green, int blue);
void mainLcdDraw();
void mainLcdClear();

void hardwareDisplayInit() {
  mainCreateWxLcdSimulator();
}

void hardwareDisplaySetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  mainLcdSetPixel(x, y, red, green, blue);
}

void hardwareDisplayDraw() {
  mainLcdDraw();
}

void hardwareDisplayClear() {
  mainLcdClear();
}

// Colored print:

static void _printColored(const char* text, uint16_t colorAttributes) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;

  GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Save current font color
  saved_attributes = consoleInfo.wAttributes;
  SetConsoleTextAttribute(hConsole, colorAttributes); // Change font color
  printf(text);
  SetConsoleTextAttribute(hConsole, saved_attributes); // Restore original font color
  printf("\n\r");
}

void hal_printf(char* format, ...) {
  char formattedText[512];

  va_list args;
  va_start(args, format);
  vsnprintf_s(formattedText, sizeof(formattedText), sizeof(formattedText), format, args);
  _printColored(formattedText, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  va_end(args);
}

void hal_printfError(const char* format, ...) {
  char formattedText[512];

  va_list args;
  va_start(args, format);
  vsnprintf_s(formattedText, sizeof(formattedText), sizeof(formattedText), format, args);
  _printColored(formattedText, FOREGROUND_RED | FOREGROUND_INTENSITY);
  va_end(args);
}

void hal_printfWarning(char* format, ...) {
  char formattedText[512];

  va_list args;
  va_start(args, format);
  vsnprintf_s(formattedText, sizeof(formattedText), sizeof(formattedText), format, args);
  _printColored(formattedText, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY); // Yellow
  va_end(args);
}

void hal_printfSuccess(char* format, ...) {
  char formattedText[512];

  va_list args;
  va_start(args, format);
  vsnprintf_s(formattedText, sizeof(formattedText), sizeof(formattedText), format, args);
  _printColored(formattedText, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  va_end(args);
}

void hal_printfInfo(char* format, ...) {
  char formattedText[512];

  va_list args;
  va_start(args, format);
  vsnprintf_s(formattedText, sizeof(formattedText), sizeof(formattedText), format, args);
  _printColored(formattedText, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  va_end(args);
}

void hal_strcpy_s(char* dst, int maxSize, const char* src) {
  for (int i = 0; i < maxSize - 1; i++) {
    dst[i] = src[i];

    if (i == maxSize - 1)
      dst[i] = 0;
  }
}

// Input device:

#define KEY_ACTION  VK_RETURN
#define KEY_BACK    VK_BACK
#define KEY_NORTH   'W'
#define KEY_WEST    'A'
#define KEY_SOUTH   'S'
#define KEY_EAST    'D'
#define KEY_START   VK_SPACE
#define KEY_SELECT 'X'
#define KEY_SIMULATE_DISCONNECTED VK_TAB

uint8_t getButtonStateEmu(int virtualKeyCode) {
  return (GetAsyncKeyState(virtualKeyCode) & 32768) >> 15;

  // if (GetForegroundWindow() == g_hEmuWnd)
  //   return (GetAsyncKeyState(virtualKeyCode) & 32768) >> 15;
  // else
  //   return 0;
}

InputDeviceStates_t getInputDeviceState() {
  InputDeviceStates_t states;

  states.Connected = !getButtonStateEmu(KEY_SIMULATE_DISCONNECTED);
  states.Action    = getButtonStateEmu(KEY_ACTION);
  states.Back      = getButtonStateEmu(KEY_BACK);
  states.North     = getButtonStateEmu(KEY_NORTH) || getButtonStateEmu(VK_UP);
  states.West      = getButtonStateEmu(KEY_WEST)  || getButtonStateEmu(VK_LEFT);
  states.South     = getButtonStateEmu(KEY_SOUTH) || getButtonStateEmu(VK_DOWN);
  states.East      = getButtonStateEmu(KEY_EAST)  || getButtonStateEmu(VK_RIGHT);
  states.Start     = getButtonStateEmu(KEY_START);
  states.Select    = getButtonStateEmu(KEY_SELECT);

  return states;
}

uint32_t hal_clock() {
  return clock();
}
