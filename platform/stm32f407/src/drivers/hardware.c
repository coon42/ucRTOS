#include "stm32f4xx_conf.h"
#include "ucrtos.h"

// Timing

void delayUs(uint32_t us) {
  TIM2->CNT = 0;
  while(TIM2->CNT < us);
}

void delayMs(uint32_t ms) {
  for(int i = 0; i < ms; i++)
    delayUs(1000);
}

// LED

void statusLedOn() {
  GPIO_SetBits(GPIOD, GPIO_Pin_12);
}

void statusLedOff() {
  GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}

void errorLedOn() {
  GPIO_SetBits(GPIOD, GPIO_Pin_13);
}

void errorLedOff() {
  GPIO_ResetBits(GPIOD, GPIO_Pin_13);
}

void errorState() {
  while(1) {
    errorLedOn();
    delayMs(50);
    errorLedOff();
    delayMs(500);
  }
}

// Display

void displaySetPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {

}

void displayClear(uint16_t Color) {

}
