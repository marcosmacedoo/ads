#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *inverteFrase(char frase[]);
int estaDentro(char elemento, char vetor[]);
void substituiConsoantes(char frase[], char vogais[], char elemento);


int main() {
    const int n = 50;
    char frase[n], *fraseInvertida;
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    printf("Digite uma frase: ");
    fgets(frase, 50, stdin);
    printf("%s", frase);
    fraseInvertida = inverteFrase(frase);
    printf("%s", fraseInvertida);
    substituiConsoantes(fraseInvertida, vogais, '#');
    printf("%s\n", fraseInvertida);

    free(fraseInvertida);
 
    return 0;
}


char *inverteFrase(char frase[]) {
    int i, j, tamanhoDaFrase;
    char *fraseInvertida;

    tamanhoDaFrase = strlen(frase);
    j = 1;
    fraseInvertida = (char*) malloc(sizeof(char));

    for (i = 0; i < tamanhoDaFrase; i++) {
        fraseInvertida[i] = frase[tamanhoDaFrase - j];
        j++;
        fraseInvertida = (char*) realloc(fraseInvertida, j*sizeof(char));
    }
    
    return fraseInvertida;
}


int estaDentro(char elemento, char vetor[]) {
    int i, tamanho;

    tamanho = strlen(vetor);

    for (i = 0; i < tamanho; i++) {
        if (elemento == vetor[i]) {
            return 1;
        }
    }
    
    return 0;
}


void substituiConsoantes(char frase[], char vogais[], char elemento) {
    int i, tamanhoFrase;
    char caractereAtual;

    tamanhoFrase = strlen(frase);

    for (i = 0; i < tamanhoFrase; i++) {
        caractereAtual = frase[i];
        if (!estaDentro(caractereAtual, vogais) && !isspace(caractereAtual)) { 
            frase[i] = '#';
        }
    }
}
