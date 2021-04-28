#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *limpaSenhaEntrada(char senhaEntrada[]);


int main() {
    char senhaEntrada[50], *senhaLimpa;

    printf("Senha: ");
    fgets(senhaEntrada, 50, stdin);

    senhaLimpa = limpaSenhaEntrada(senhaEntrada);

    if (strcmp(senhaLimpa, "aiaiaiuiuiui") == 0) {
        printf("Acertou miserave\n");
    }
    else {
        printf("Errouuuuuuu\n");
    }

    free(senhaLimpa);

    return 0;
}


char *limpaSenhaEntrada(char senhaEntrada[]) {
    char *senhaLimpa;
    int tamanhoSenha, i;

    tamanhoSenha = strlen(senhaEntrada);
    senhaLimpa = (char*) malloc(sizeof(char));

    for (i = 0; i < tamanhoSenha-1; i++) {
        senhaLimpa[i] = senhaEntrada[i];
        senhaLimpa = (char*) realloc(senhaLimpa, sizeof(char)*i+1);
    }

    return senhaLimpa;
}
