// Processa o comando recebido via UART
// 


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

