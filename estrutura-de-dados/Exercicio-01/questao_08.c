#include <stdio.h>


int recebeQuantidadeTermos();
void geraFibonacci(int fibonacci[], int quantidadeTermos);
void imprimeVetor(int vetor[], int tamanhoDoVetor);


void main() {
    int quantidadeTermos;
    quantidadeTermos = recebeQuantidadeTermos();
    int fibonacci[quantidadeTermos];

    geraFibonacci(fibonacci, quantidadeTermos);
    imprimeVetor(fibonacci, quantidadeTermos);

}


int recebeQuantidadeTermos() {
    int quantidadeTermos;

    do {
        printf("Digite a quantidade de termos da sequencia: ");
        scanf("%d", &quantidadeTermos);
        setbuf(stdin, NULL);
    } while (quantidadeTermos < 1);

    return quantidadeTermos;
}


void geraFibonacci(int fibonacci[], int quantidadeTermos) {
    int i, primeiroTermo, segundoTermo;

    primeiroTermo = 0;
    segundoTermo = 1;

    if (quantidadeTermos == 1) {
        fibonacci[0] = primeiroTermo;
    }
    else if (quantidadeTermos >= 2) {
        fibonacci[0] = primeiroTermo;
        fibonacci[1] = segundoTermo;
    }
    for (i=2; i<quantidadeTermos; i++) {
        fibonacci[i] = primeiroTermo + segundoTermo;
        primeiroTermo = segundoTermo;
        segundoTermo = fibonacci[i];
    } 

}


void imprimeVetor(int vetor[], int tamanhoDoVetor) {
    int i;

    printf("\nFibonacci: ");
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
