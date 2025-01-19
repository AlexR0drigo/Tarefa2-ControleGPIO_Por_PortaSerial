#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

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
        case 'X': // Reinicia o sistema
            printf("Comando de reinicialização não é suportado no Wokwi.\n");
            break;
        default:
            printf("Comando inválido: %c\n", comando);
            break;
    }
}
