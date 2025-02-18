#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

// Definições dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Protótipos das funções
void ligar_led(uint gpio);
void desligar_todos_leds();
void acionar_buzzer();
void processar_comando(char comando);

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

    while (true) {
        int ch = getchar_timeout_us(1000000); // Aguarda entrada por 1 segundo
        if (ch != PICO_ERROR_TIMEOUT) {
            processar_comando((char)ch);
        }
    }
    return 0;
}

// Processa o comando recebido via UART
void processar_comando(char comando) {
    switch (comando) {
        case 'G': // Liga o LED verde
            ligar_led(LED_GREEN);
            break;
        case 'B': // Liga o LED azul
            ligar_led(LED_BLUE);
            break;
        case 'R': // Liga o LED vermelho
            ligar_led(LED_RED);
            break;
        case 'W': // Liga todos os LEDs (luz branca)
            gpio_put(LED_GREEN, true);
            gpio_put(LED_BLUE, true);
            gpio_put(LED_RED, true);
            printf("Todos os LEDs ligados.\n");
            break;
        case 'O': // Desliga todos os LEDs
            desligar_todos_leds();
            break;
        case 'Z': // Aciona o buzzer
            acionar_buzzer();
            break;
        default:
            printf("Comando inválido: %c\n", comando);
            break;
    }
}

// Liga um LED específico e desliga os demais
void ligar_led(uint gpio) {
    desligar_todos_leds();
    gpio_put(gpio, true);
    printf("LED ligado no GPIO %d\n", gpio);
}

// Desliga todos os LEDs
void desligar_todos_leds() {
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, false);
    printf("Todos os LEDs desligados.\n");
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