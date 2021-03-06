#include <math.h>
#include "../lib/AsciiLib/AsciiLib.h"
#include "display.h"
#include "lut.h"

#define DISPLAY_RESOLUTION_X 320
#define DISPLAY_RESOLUTION_Y 240

static uint8_t _pDisplayFrameBuffer[(DISPLAY_RESOLUTION_X * DISPLAY_RESOLUTION_Y) / 2];

void displayInit() {
  hardwareDisplayInit(_pDisplayFrameBuffer, DISPLAY_RESOLUTION_X, DISPLAY_RESOLUTION_Y);
}

// TODO: move to better place:
#define RGB565CONVERT(red, green, blue) (int) (((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3))

void displaySetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  if (x >= DISPLAY_RESOLUTION_X || y >= DISPLAY_RESOLUTION_Y)
    return;

  uint16_t clutIndex = RGB565CONVERT(red, green, blue);
  uint8_t colorIndex = pClut565[clutIndex];

  int idx = y * DISPLAY_RESOLUTION_X + x;
  int subIdx = idx / 2;
  int isMsb = idx % 2 == 0;

  if (!isMsb) {
    _pDisplayFrameBuffer[subIdx] &= 0xF0;
    _pDisplayFrameBuffer[subIdx] |= colorIndex;
  }
  else {
    _pDisplayFrameBuffer[subIdx] &= 0x0F;
    _pDisplayFrameBuffer[subIdx] |= (colorIndex << 4);
  }
}

void displayDraw() {
  hardwareDisplayDraw();
}

void displayClear() {
  for (int y = 0; y < DISPLAY_RESOLUTION_Y; ++y)
    for (int x = 0; x < DISPLAY_RESOLUTION_X; ++x)
      displaySetPixel(x, y, 0, 0, 0);
}

void displayDrawImage(uint16_t xPos, uint16_t yPos, const uint8_t* pImg) {
  uint8_t width = pImg[0];
  uint8_t height = pImg[1];
  pImg += 2;

  for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++) {
      uint8_t red = pImg[3 * (x + y * width) + 0];
      uint8_t green = pImg[3 * (x + y * width) + 1];
      uint8_t blue = pImg[3 * (x + y * width) + 2];

      if (!(red == 255 && green == 0 && blue == 255)) // Is the pixel transparent?
        displaySetPixel(xPos + x, yPos + y, red, green, blue);
    }
}

static void putCharFont(uint16_t x, uint16_t y, uint8_t ASCII, uint8_t txtRed, uint8_t txtGreen,
    uint8_t txtBlue, uint8_t bkRed, uint8_t bkGreen, uint8_t bkBlue, uint16_t FONTx) {

  uint16_t i, j;
  uint8_t buffer[16], tmp_char;
  uint8_t len_x, len_y;

  switch (FONTx) {
  case FONT6x8:
    len_x = 6;
    len_y = 8;
    break;
  case FONT8x8:
    len_x = 8;
    len_y = 8;
    break;
  case MS_GOTHIC_8x16:
  case SYSTEM_8x16:
  default:
    len_x = 8;
    len_y = 16;
    break;
  }

  getASCIICode(buffer, ASCII, FONTx);
  for (i = 0; i < len_y; i++) {
    tmp_char = buffer[i];
    for (j = 0; j<len_x; j++) {
      if (((tmp_char >> (7 - j)) & 0x01) == 0x01)
        displaySetPixel(x + j, y + i, txtRed, txtGreen, txtBlue);
      else
        displaySetPixel(x + j, y + i, bkRed, bkGreen, bkBlue);
    }
  }
}

static void textFont(uint16_t x, uint16_t y, const char* str, uint8_t txtRed, uint8_t txtGreen, uint8_t txtBlue,
    uint8_t bgRed, uint8_t bgGreen, uint8_t bgBlue, uint16_t FONTx) {

  uint8_t TempChar;
  uint8_t delta_x, delta_y;

  switch (FONTx) {
  case FONT6x8:
    delta_x = 6;
    delta_y = 8;
    break;
  case FONT8x8:
    delta_x = 8;
    delta_y = 8;
    break;
  case MS_GOTHIC_8x16:
  case SYSTEM_8x16:
  default:
    delta_x = 8;
    delta_y = 16;
    break;
  }

  x = x == CENTER ? (DISPLAY_RESOLUTION_X - delta_x * (uint16_t)strlen(str)) / 2 : x;
  y = y == CENTER ? (DISPLAY_RESOLUTION_Y - 2 * delta_y) / 2 : y;

  do {
    TempChar = *str++;
    putCharFont(x, y, TempChar, txtRed, txtGreen, txtBlue, bgRed, bgGreen, bgBlue, FONTx);

    if (x < DISPLAY_RESOLUTION_X - delta_x) {
      x += delta_x;
    }
    else if (y < DISPLAY_RESOLUTION_Y - delta_y) {
      x = 0;
      y += delta_y;
    }
    else {
      x = 0;
      y = 0;
    }
  } while (*str != 0);
}

void displayDrawText(uint16_t x, uint16_t y, const char* str, uint8_t txtRed, uint8_t txtGreen, uint8_t txtBlue,
    uint8_t bgRed, uint8_t bgGreen, uint8_t bgBlue) {

  textFont(x, y, str, txtRed, txtGreen, txtBlue, bgRed, bgGreen, bgBlue, SYSTEM_8x16);
}
