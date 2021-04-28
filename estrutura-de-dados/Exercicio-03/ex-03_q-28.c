#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int primeiroNumero, segundoNumero, mmc;

    printf("Digite um numero: ");
    scanf("%d", &primeiroNumero);
    printf("Digite outro numero: ");
    scanf("%d", &segundoNumero);

    mmc = calculaMmc(primeiroNumero, segundoNumero);
    printf("MMC = %d\n", mmc);

    return 0;
}
