#include <stdio.h>
#include <string.h>
#define n 30


int ehPalindroma(char palavra[]);


int main() {
    char palavra[n];

    printf("Palavra: ");
    fgets(palavra, n, stdin);

    if (ehPalindroma(palavra) == 0) {
        printf("Eh palindroma!\n");
    }
    else {
        printf("Nao eh palindroma!\n");
    }

    return 0;
}


int ehPalindroma(char palavra[]) {
    int i, j, k, tamanhoPalavra;

    tamanhoPalavra = strlen(palavra);
    j = tamanhoPalavra - 2;
    k = 0;

    for (i = 0; i < tamanhoPalavra - 1; i++) {
        if (palavra[i] == palavra[j]) {
            k++;    // Conta a quantidade de caractere iguais
        }
        j--;
    }

    if (k == tamanhoPalavra-1) {
        return 0;
    }

    return 1;
}