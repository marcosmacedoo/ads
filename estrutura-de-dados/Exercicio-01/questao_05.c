#include <stdio.h>


int recebeTamanhoDoVetor();
void insereElementosNoVetor(int vetor[], char nomeVetor, int tamanhoVetor);
void insereElementosNoVetorB(int vetorA[], int vetorB[], int tamanhoDoVetor);
void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);

/*
5. Leia um vetor A com N elementos e escreva um vetor B com N elementos, conforme a seguinte
condição: se índice de A[índice] é par então B[índice] = 0, caso contrário B[índice] = 1.
*/

int main() {
    int tamanhoDoVetor;
    tamanhoDoVetor = recebeTamanhoDoVetor();
    int vetorA[tamanhoDoVetor], vetorB[tamanhoDoVetor];

    insereElementosNoVetor(vetorA, 'A', tamanhoDoVetor);
    insereElementosNoVetorB(vetorA, vetorB, tamanhoDoVetor);
    imprimeVetor(vetorA, 'A', tamanhoDoVetor);
    imprimeVetor(vetorB, 'B', tamanhoDoVetor);

    return 0;
}


int recebeTamanhoDoVetor() {
    int tamanhoDoVetor;

    do {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoDoVetor);
    } while (tamanhoDoVetor < 1);
    
    return tamanhoDoVetor;
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


void insereElementosNoVetorB(int vetorA[], int vetorB[], int tamanhoDoVetor) {
    int i;

    for (i=0; i<tamanhoDoVetor; i++) {
        if (vetorA[i]%2 == 0) {
            vetorB[i] = 0;
        }
        else {
            vetorB[i] = 1;
        }
    }
}


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor) {
    int i;

    printf("Vetor %c: ", nomeVetor);
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
