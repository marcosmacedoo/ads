#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int numero, fatorial;

    printf("Digite um numero (inteiro): ");
    scanf("%d", &numero);
    
    fatorial = calculaFatorial(numero);
    printf("Fatorial de %d eh %d\n", numero, fatorial);

    return 0;
}
