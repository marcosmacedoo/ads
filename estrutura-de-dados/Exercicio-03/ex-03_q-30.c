#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int ano;

    printf("Ano: ");
    scanf("%d", &ano);

    if (ehAnoBissexto(ano)) {
        printf("Eh ano bissexto\n");
    }
    else {
        printf("Nao eh ano bissexto\n");
    }

    return 0;
}
