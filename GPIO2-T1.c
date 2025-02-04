
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define VERMELHO 11     // GPIO para o LED Vermelho
#define AMARELO 12  // GPIO para o LED Amarelo
#define VERDE 13   // GPIO para o LED Verde


volatile int corAtual = VERMELHO; // inicializa a cor do semaforo

bool repeating_timer_callback(struct repeating_timer *t) {
    // muda as cores do semaforo
    switch (corAtual) {
        case VERMELHO: 
            gpio_put(VERMELHO, 1);
            gpio_put(AMARELO, 0);
            gpio_put(VERDE, 0);
            corAtual = AMARELO;
            break;
        case AMARELO: 
            gpio_put(VERMELHO, 0);
            gpio_put(AMARELO, 1);
            gpio_put(VERDE, 0);
            corAtual = VERDE;
            break;
        case VERDE: 
            gpio_put(VERMELHO, 0);
            gpio_put(AMARELO, 0);
            gpio_put(VERDE, 1);
            corAtual = VERMELHO;
            break;
    }
    return true; // Continua repetindo o temporizador
}
void init() {
    stdio_init_all();
    
    // Configuração dos GPIOs
    gpio_init(VERMELHO);
    gpio_init(AMARELO); 
    gpio_init(VERDE);
    gpio_set_dir(VERMELHO, GPIO_OUT);
    gpio_set_dir(AMARELO, GPIO_OUT);
    gpio_set_dir(VERDE, GPIO_OUT);
}
int main() {
    init(); // inicializa os leds 
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // tempo de 3 segundos
    
    while (true) {
        printf("Operando...\n");
        sleep_ms(1000); // mensagem de 1 segundo
    }
    return 0;
}