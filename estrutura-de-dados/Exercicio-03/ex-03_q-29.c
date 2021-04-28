#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int primeiroNumero, segundoNumero, mdc;

    printf("Digite um numero: ");
    scanf("%d", &primeiroNumero);
    printf("Digite outro numero: ");
    scanf("%d", &segundoNumero);

    mdc = calculaMdc(primeiroNumero, segundoNumero);
    printf("MDC = %d\n", mdc);
    
    return 0;
}
