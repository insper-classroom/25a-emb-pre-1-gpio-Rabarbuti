#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_A = 6;

const int BTN_PIN = 28;
const int BTN_PIN_2 = 26;


int main() {
  stdio_init_all();

  gpio_init(LED_PIN_A);
  gpio_init(LED_PIN_R);
  gpio_init(BTN_PIN);
  gpio_init(BTN_PIN_2);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(BTN_PIN_2, GPIO_IN);

  gpio_pull_up(BTN_PIN);
  gpio_pull_up(BTN_PIN_2);


  while (true) {
    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_PIN_R, !gpio_get(LED_PIN_R));
      while (!gpio_get(BTN_PIN)) {
      }
    }
    if (!gpio_get(BTN_PIN_2)) {
      gpio_put(LED_PIN_A, !gpio_get(LED_PIN_A));
      while (!gpio_get(BTN_PIN_2)) {
      }
    }
  }
}
