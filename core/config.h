#pragma once

#define FSM_STACK_SIZE 4
#define RING_BUFFER_SIZE 256
#define MAX_MENU_ITEM_CHARS 32
#define CURSOR_SPEED_ITEMS_PER_SECOND 32
#define CURSOR_DELAY_MS_BEFORE_REPEAT 500
#define INPUT_DEVICE_DEBOUNCE_MS 50 // TODO: Set to about 100 - 50 ms later (should be lower than CURSOR_DELAY_MS_BEFORE_REPEAT)
