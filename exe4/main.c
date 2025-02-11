#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;


const int LED_PIN_R = 5;
const int LED_PIN_ROXO = 8;
const int LED_PIN_Azul = 11;
const int LED_PIN_A = 15;

bool led_r_state = false;
bool led_a_state = false;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_A);
  gpio_init(LED_PIN_R);
  gpio_init(BTN_PIN);
  gpio_init(LED_PIN_ROXO);
  gpio_init(LED_PIN_Azul);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(LED_PIN_Azul,GPIO_OUT);
  gpio_set_dir(LED_PIN_ROXO,GPIO_OUT);

  gpio_pull_up(BTN_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_PIN_R, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_ROXO, 0);
      gpio_put(LED_PIN_Azul, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Azul, 0);
      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_A, 0);
      while (!gpio_get(BTN_PIN)) {
        sleep_ms(10);
      }
    }else{
      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_ROXO, 0);
      gpio_put(LED_PIN_Azul, 0);
      gpio_put(LED_PIN_A, 0);
    }
  }
}