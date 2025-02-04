#include <stdio.h>                 
#include "pico/stdlib.h"           
#include "hardware/timer.h"         // Biblioteca necessária para o temporizador

// Definição dos pinos dos LEDs 
const uint RED_LED_PIN = 13;       // Pino do LED vermelho
const uint YELLOW_LED_PIN = 12;    // Pino do LED amarelo (na BitDogLab esse GPIO o led é AZUL)
const uint GREEN_LED_PIN = 11;     // Pino do LED verde

// Variáveis globais para controlar o estado do semáforo e a mensagem exibida
volatile uint8_t state = 0;        // Estado do semáforo (0 - vermelho, 1 - amarelo, 2 - verde)
volatile const char* led_message = "Semáforo ligado"; // Mensagem inicial exibida antes dos LEDs mudarem

// Função de callback para o temporizador, chamada a cada 3 segundos para mudar o estado do semáforo
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ligar o próximo LED
    gpio_put(RED_LED_PIN, 0);        // Desliga o LED vermelho
    gpio_put(YELLOW_LED_PIN, 0);     // Desliga o LED amarelo
    gpio_put(GREEN_LED_PIN, 0);      // Desliga o LED verde

    // Altera o LED e a mensagem conforme o estado atual do semáforo
    switch (state) {
        case 0:
            gpio_put(RED_LED_PIN, 1);          // Liga o LED vermelho
            led_message = "Led Vermelho ligado";  // Atualiza a mensagem
            break;
        case 1:
            gpio_put(YELLOW_LED_PIN, 1);       // Liga o LED amarelo
            led_message = "Led Amarelo ligado"; // Atualiza a mensagem
            break;
        case 2:
            gpio_put(GREEN_LED_PIN, 1);        // Liga o LED verde
            led_message = "Led Verde ligado";   // Atualiza a mensagem
            break;
    }

    // Atualiza o estado para a próxima cor
    state = (state + 1) % 3;  // Vai de 0 -> 1 -> 2 (vermelho -> amarelo -> verde), e depois volta a 0

    return true; // Retorna true para manter o temporizador ativo
}

int main() {
    // Inicializa a comunicação serial, necessário para usar printf no Raspberry Pi Pico
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saídas
    gpio_init(RED_LED_PIN);            // Inicializa o pino do LED vermelho
    gpio_set_dir(RED_LED_PIN, GPIO_OUT); // Define o pino como saída
    gpio_init(YELLOW_LED_PIN);         // Inicializa o pino do LED amarelo
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT); // Define o pino como saída
    gpio_init(GREEN_LED_PIN);          // Inicializa o pino do LED verde
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT); // Define o pino como saída

    // Configuração do temporizador periódico para chamar a função de callback a cada 3000 ms (3 segundos)
    struct repeating_timer timer;      // Declara a estrutura do temporizador
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);  // Define o temporizador para chamar a função de callback

    // Loop principal do programa, que exibe a mensagem a cada 1 segundo
    while (true) {
        printf("Semáforo operando... %s\n", led_message);  // Exibe a mensagem atual (estado do semáforo)
        sleep_ms(1000);  // Aguarda 1 segundo antes de exibir a próxima mensagem
    }

    return 0; // Código nunca chega aqui, pois o loop é infinito
}
