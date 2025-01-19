#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definições dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

void acionar_buzzer();
void desligar_todos_leds();

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

void acionar_buzzer() {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);

    // Configura o GPIO para função PWM
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);

    // Configura a frequência do PWM (ex.: 2000 Hz)
    uint32_t freq = 2000;
    uint32_t clock_freq = 125000000; // Frequência do clock padrão do Pico
    uint16_t wrap = clock_freq / freq;

    pwm_set_wrap(slice_num, wrap); // Define o período
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(BUZZER), wrap / 2); // Duty cycle de 50%
    pwm_set_enabled(slice_num, true); // Habilita o PWM

    sleep_ms(2000); // Tempo que o buzzer ficará ativo

    pwm_set_enabled(slice_num, false); // Desliga o PWM
    printf("Buzzer acionado por 2 segundos.\n");
}

void desligar_todos_leds() {
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, false);
    printf("Todos os LEDs desligados.\n");
}
