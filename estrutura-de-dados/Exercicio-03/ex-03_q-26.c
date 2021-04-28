#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int numero, a;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    if (ehNumeroPrimo(numero)) {
        printf("%d eh primo\n", numero);
    }
    else {
        printf("%d nao eh primo\n", numero);
    }

    return 0;
}
