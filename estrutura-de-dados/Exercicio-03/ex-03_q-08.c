#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char *retornaUltimoNome(char nomeCompleto[]);
char *retornaIniciaisNome(char nomeCompleto[]); 
char *inverteNome(char ultimoNomeInverso[]);


int main() {
    int i, tamanhoLetrasIniciais;
    char nomeCompleto[60], *ultimoNome, *letrasIniciais;

    printf("Nome completo: ");
    fgets(nomeCompleto, 60, stdin);

    ultimoNome = retornaUltimoNome(nomeCompleto);
    letrasIniciais = retornaIniciaisNome(nomeCompleto);
    tamanhoLetrasIniciais = strlen(letrasIniciais);
    
    printf("%s, ", ultimoNome);
    for (i = 0; i < tamanhoLetrasIniciais-1; i++) {
        printf("%c. ", toupper(letrasIniciais[i]));
    }
    printf("\n");

    free(ultimoNome);
    free(letrasIniciais);

    return 0;
}


char *inverteNome(char ultimoNomeInverso[]) {
    char *ultimoNome;
    int i, tamanhoUltimoNome, j;

    tamanhoUltimoNome = strlen(ultimoNomeInverso);
    ultimoNome = (char*) malloc(sizeof(char));
    j = tamanhoUltimoNome - 1;

    for (i = 0; i < tamanhoUltimoNome; i++) {
        ultimoNome[i] = ultimoNomeInverso[j];
        j--;
        ultimoNome = (char*) realloc(ultimoNome, i+1 * sizeof(char));
    }

    return ultimoNome;
}


char *retornaUltimoNome(char nomeCompleto[]) {
    char *ultimoNome;
    int i, tamanhoNomeCompleto, j;

    tamanhoNomeCompleto = strlen(nomeCompleto);
    ultimoNome = (char*) malloc(sizeof(char));
    j = 0;

    for (i = tamanhoNomeCompleto - 1; i >= 0; i++) {
        if (isspace(nomeCompleto[i])) {
            break;
        }
        else if (isalpha(nomeCompleto[i])) {
            ultimoNome[j] = nomeCompleto[i];
            j++;
            ultimoNome = (char*) realloc(ultimoNome, j+1 * sizeof(char));
        }
    }

    ultimoNome = inverteNome(ultimoNome);

    return ultimoNome;
}


char *retornaIniciaisNome(char nomeCompleto[]) {
    char *iniciaisNome;
    int i, tamanhoNomeCompleto, j, k;

    tamanhoNomeCompleto = strlen(nomeCompleto);
    iniciaisNome = (char*) malloc(sizeof(char));
    j = 0;
    k = 0;

    for (i = 0; i < tamanhoNomeCompleto; i++) {
        if (!isspace(nomeCompleto[i])) {
            if (j == 0) {
                iniciaisNome[k] = nomeCompleto[i];
                j++;
                k++;
                iniciaisNome = (char*) realloc(iniciaisNome, k+1 * sizeof(char));
            }
        }
        else {
            j = 0;
        }
    }

    return iniciaisNome;
}
