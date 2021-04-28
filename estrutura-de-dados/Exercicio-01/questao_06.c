#include <stdio.h>
#define n 5


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);
void insereElementosNoVetor(int vetor[], char nomeVetor, int tamanhoVetor);
int retornaMaiorElemento(int vetor[], int tamanhoVetor);
int retornaMenorElemento(int vetor[], int tamanhoVetor);
int retornaPosicaoElemento(int vetor[], int elemento, int tamanhoVetor);
void imprimeDados(int maiorElemento, int menorElemento, int posicaoMaiorElemento, 
                  int posicaoMenorElemento, int vetor[]);

/*
6. Leia um vetor com N elementos, encontre e escreva o maior e o menor elemento e suas
respectivas posições no vetor.
*/

int main() {
    int vetor[n], maiorElemento, menorElemento, posicaoMaiorElemento, posicaoMenorElemento;

    insereElementosNoVetor(vetor, 'X', n);
    maiorElemento = retornaMaiorElemento(vetor, n);
    menorElemento = retornaMenorElemento(vetor, n);
    posicaoMaiorElemento = retornaPosicaoElemento(vetor, maiorElemento, n);
    posicaoMenorElemento = retornaPosicaoElemento(vetor, menorElemento, n);
    imprimeDados(maiorElemento, menorElemento, posicaoMaiorElemento, posicaoMenorElemento, vetor);

    return 0;
}


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor) {
    int i;

    printf("Vetor %c: ", nomeVetor);
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


void insereElementosNoVetor(int vetor[], char nomeVetor, int tamanhoVetor) {
    int i;

    for (i=0; i<tamanhoVetor; i++) {
        printf("Vetor %c[%d]: ", nomeVetor, i);
        scanf("%d", &vetor[i]);
        setbuf(stdin, NULL);
    }
    printf("\n");
}


int retornaMaiorElemento(int vetor[], int tamanhoVetor) {
    int maiorElemento, i;
    
    maiorElemento = vetor[0];
    for (i=1; i<tamanhoVetor; i++) {
        if (vetor[i] > maiorElemento) {
            maiorElemento = vetor[i];
        }
    }

    return maiorElemento;
}


int retornaMenorElemento(int vetor[], int tamanhoVetor) {
    int menorElemento, i;
    
    menorElemento = vetor[0];
    for (i=1; i<tamanhoVetor; i++) {
        if (vetor[i] < menorElemento) {
            menorElemento = vetor[i];
        }
    }

    return menorElemento;
}


int retornaPosicaoElemento(int vetor[], int elemento, int tamanhoVetor) {
    int i;

    for (i=0; i<tamanhoVetor; i++) {
        if (vetor[i] == elemento) {
            return i;
        }
    }

    return -1;
}


void imprimeDados(int maiorElemento, int menorElemento, int posicaoMaiorElemento, 
                  int posicaoMenorElemento, int vetor[]) {
    printf("-----------------------------------------------\n");
    imprimeVetor(vetor, 'X', n);
    printf("Maior elemento -> %d\tPosicao -> %d\n", maiorElemento, posicaoMaiorElemento);
    printf("Menor elemento -> %d\tPosicao -> %d\n", menorElemento, posicaoMenorElemento);
    printf("-----------------------------------------------\n");
}
