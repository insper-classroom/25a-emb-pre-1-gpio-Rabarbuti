#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 4;
const int BTN_PIN_2 = 6;

const int LED_PIN_R = 28;
const int LED_PIN_A = 26;

bool led_r_state = false;
bool led_a_state = false;

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
    if (gpio_get(BTN_PIN) == 0) {
      if (!led_r_state) {
        gpio_put(LED_PIN_R, 1); // Acende o LED vermelho
        led_r_state = true;
      }
    } else {
      if (led_r_state) {
        gpio_put(LED_PIN_R, 0); // Apaga o LED vermelho
        led_r_state = false;
      }
    }

    if (gpio_get(BTN_PIN_2) == 0) {
      if (!led_a_state) {
        gpio_put(LED_PIN_A, 1); // Acende o LED amarelo
        led_a_state = true;
      }
    } else {
      if (led_a_state) {
        gpio_put(LED_PIN_A, 0); // Apaga o LED amarelo
        led_a_state = false;
      }
    }

    sleep_ms(100); // Adiciona um delay de 100ms para cada ciclo
  }
}
