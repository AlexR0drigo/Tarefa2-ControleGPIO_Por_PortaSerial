#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definições dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

int main() {
    // Inicializa UART
    stdio_init_all();

    // Configura os GPIOs como saída
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, false);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, false);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, false);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, false);

    printf("Sistema iniciado. Aguardando comandos via UART...\n");

}
