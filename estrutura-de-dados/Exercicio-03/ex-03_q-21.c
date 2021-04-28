#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double raioCircunferencia, comprimentoCircunferencia;

    printf("Raio da circunferencia: ");
    scanf("%lf", &raioCircunferencia);

    comprimentoCircunferencia = calculaComprimentoCircunferencia(raioCircunferencia);
    printf("Comprimento da circunferencia = %.2f\n", comprimentoCircunferencia);

    return 0;
}
