
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#define L_BASE 0
#define L_LOWER 8
#define L_RAISE 16
#define L_ADJUST 65536
#define L_ADJUST_TRI 65560

char layer_state_str[24];

/* const char *read_layer_state(void) { */
const char *read_layer_state(char base_layer) {
  switch (layer_state)
  {
  case L_BASE:
    if(base_layer == 'Q') {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    } else {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Dvorak");
    }
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
