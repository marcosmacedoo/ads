/*
O programa deve receber valores do tipo inteiro e armazená-los em um vetor
Para encerrar o programa o usuário deve atribuir um valor igual a -1
*/


#include <stdio.h>
#include <stdlib.h>


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);
int *criaVetor(int tamanhoAtual);
int *adicionaElementoNoVetor(int *vetor, int tamanho, int elemento);
//void passaValoresEntreDoisVetores(int *vetorOrigem, int *vetorReserva, int tamanhoVetor);


int main() {
    int numero, *vetorOrigem, i, soma, tamanhoVetor;
    float media;

    numero = 0;
    i = 0;
    soma = 0;

    while (1) {
        printf("Digite um numero[%d](flag = -1): ", i);
        scanf("%d", &numero);
        setbuf(stdin, NULL);
        if (numero == -1) break; 
        tamanhoVetor = i + 1;
        if (i == 0) {
            vetorOrigem = criaVetor(tamanhoVetor);
            vetorOrigem[0] = numero;
        }
        else {
            vetorOrigem = adicionaElementoNoVetor(vetorOrigem, tamanhoVetor, numero);
        }
        imprimeVetor(vetorOrigem, 'V', i);
        soma += numero;
        i++;
    }

    media = soma/i;
    
    imprimeVetor(vetorOrigem, 'V', i);
    printf("Soma = %d\n", soma);
    printf("Media = %.2f\n", media);
    free(vetorOrigem);  //Libera a memória utilizada (malloc) durante o programa

    return 0;
}


int *criaVetor(int tamanhoAtual) {
    int *vetor;

    //vetor = (int*) malloc(tamanhoAtual * sizeof(int));
    vetor = (int*) calloc(tamanhoAtual, sizeof(int));

    return vetor;
}


int *adicionaElementoNoVetor(int *vetor, int tamanho, int elemento) {
    /*
    int *novoVetor;

    novoVetor = criaVetor(tamanho);
    passaValoresEntreDoisVetores(vetor, novoVetor, tamanho);
    novoVetor[tamanho-1] = elemento;
    */
    vetor = (int*) realloc(vetor, tamanho * sizeof(int));
    vetor[tamanho-1] = elemento;


    return vetor;
}


/*
void passaValoresEntreDoisVetores(int *vetorOrigem, int *vetorReserva, int tamanhoVetor) {
    int i;

    for (i = 0; i < tamanhoVetor; i++) {
        vetorReserva[i] = vetorOrigem[i];
    }
}
*/


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor) {
    int i;

    printf("\nVetor %c: ", nomeVetor);
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

