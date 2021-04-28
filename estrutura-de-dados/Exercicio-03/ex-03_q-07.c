#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char *retornaPrimeiroNome(char nomeCompleto[]);
char *retornaUltimoNome(char nomeCompleto[]);


int main() {
    char nomeCompleto[60], *ultimoNome, *primeiroNome;

    printf("Nome completo: ");
    fgets(nomeCompleto, 60, stdin);

    primeiroNome = retornaPrimeiroNome(nomeCompleto);
    ultimoNome = retornaUltimoNome(nomeCompleto);

    printf("%s/%s\n", ultimoNome, primeiroNome);

    free(primeiroNome);
    free(ultimoNome);

    return 0;
}


char *retornaPrimeiroNome(char nomeCompleto[]) {
    char *primeiroNome;
    int i, tamanhoNomeCompleto, j, k;

    tamanhoNomeCompleto = strlen(nomeCompleto);
    primeiroNome = (char*) malloc(sizeof(char));
    k = 0;

    for (i = 0; i < tamanhoNomeCompleto; i++) {
        if (isspace(nomeCompleto[i])) {
            if (j != 0) {
                break;
            }
        }
        else if (isalpha(nomeCompleto[i])) {
            j++;
            primeiroNome[k] = nomeCompleto[i];
            k++;
            primeiroNome = (char*) realloc(primeiroNome, k+1 * sizeof(char));
        }
    }

    return primeiroNome;
}


char *retornaUltimoNome(char nomeCompleto[]) {
    char *ultimoNome;
    int i, tamanhoNomeCompleto, j;

    tamanhoNomeCompleto = strlen(nomeCompleto);
    ultimoNome = (char*) malloc(sizeof(char));
    j = 0;

    for (i = 0; i < tamanhoNomeCompleto; i++) {
        if (isspace(nomeCompleto[i])) {
            j = 0;
        }
        else if (isalpha(nomeCompleto[i])) {
            ultimoNome[j] = nomeCompleto[i];
            j++;
            ultimoNome = (char*) realloc(ultimoNome, j+1 * sizeof(char));
        }
    }

    return ultimoNome;
}
