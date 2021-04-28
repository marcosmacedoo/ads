#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char *formataTexto(char texto[]);
int retornaQuantidadePalavras(char texto[]);


int main() {
    char texto[100], *textoFormatado;
    int quantidadePalavras;

    printf("Digite um pequeno texto ou frase: ");
    fgets(texto, 100, stdin);

    //textoFormatado = formataTexto(texto);
    //printf("Texto formatado: %s\n", textoFormatado);
    quantidadePalavras = retornaQuantidadePalavras(texto);
    printf("O texto tem %d palavra(s)\n", quantidadePalavras);

    free(textoFormatado);
    
    return 0;
}


char *formataTexto(char texto[]) {
    char *textoFormatado;
    int i, tamanhoTexto, j;

    tamanhoTexto = strlen(texto);
    textoFormatado = (char*) malloc(sizeof(char)*2);
    j = 0;

    for (i = 0; i < tamanhoTexto-1; i++) {
        if (!isspace(texto[i]) && isspace(texto[i+1])) {
            textoFormatado[j] = texto[i];
            textoFormatado[j+1] = texto[i+1];
            j += 2;
            textoFormatado = (char*) realloc(textoFormatado, j+1 * sizeof(char));
        }
        else if (!isspace(texto[i])) {
            textoFormatado[j] = texto[i];
            j++;
            textoFormatado = (char*) realloc(textoFormatado, j+1 * sizeof(char));
        }
    }

    return textoFormatado;
}


int retornaQuantidadePalavras(char texto[]) {
    int i, quantidadePalavras, tamanhoTexto, j, k;

    tamanhoTexto = strlen(texto);
    quantidadePalavras = 0;
    j = 0;  //contara a quantidade de caracteres de uma palavra

    for (i = 0; i < tamanhoTexto-1; i++) {
        if (isspace(texto[i])) {
            if (j != 0) {
                quantidadePalavras++;
                j = 0;
            }
        }
        else {
            j++;
        }  
    }

    if (j != 0) {
        quantidadePalavras++;
    }

    return quantidadePalavras;
}
