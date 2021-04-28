#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double velocidadeKmh, velocidadeMs;

    printf("Velocidade (km/h): ");
    scanf("%lf", &velocidadeKmh);

    velocidadeMs = converteVelocidadeKmParaMs(velocidadeKmh);
    
    printf("%.2f m/s\n", velocidadeMs);

    return 0;
}
