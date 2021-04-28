#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double velocidadeMs, velocidadeKmh;

    printf("Velocidade (m/s): ");
    scanf("%lf", &velocidadeMs);

    velocidadeKmh = converteVelocidadeMsParaKm(velocidadeMs);

    printf("Velocidade (km/h): %.2f\n", velocidadeKmh);

    return 0;
}
