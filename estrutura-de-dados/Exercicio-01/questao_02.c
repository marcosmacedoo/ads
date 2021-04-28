#include <stdio.h>


int recebeTamanhoDoVetor();
void recebeElementosNoVetor(int vetor[], int tamanhoDoVetor, char nomeVetor);
void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);
int estaContido(int elemento, int vetor[], int tamanhoDoVetor);
void criaConjuntoUniao(int vetorA[], int vetorB[], int conjuntoUniao[], int vetorInterseccao[], int tamanhoDoVetor);
void criaConjuntoInterseccao(int vetorA[], int VetorB[], int vetorInterseccao[], int tamanhoDoVetor);


int main() {
    int tamanhoDoVetor;
    tamanhoDoVetor = recebeTamanhoDoVetor();
    int vetorA[tamanhoDoVetor], vetorB[tamanhoDoVetor], vetorInterseccao[tamanhoDoVetor*2], 
        conjuntoUniao[tamanhoDoVetor*2];

    recebeElementosNoVetor(vetorA, tamanhoDoVetor, 'A');
    recebeElementosNoVetor(vetorB, tamanhoDoVetor, 'B');
    criaConjuntoInterseccao(vetorA, vetorB, vetorInterseccao, tamanhoDoVetor);
    criaConjuntoUniao(vetorA, vetorB, conjuntoUniao, vetorInterseccao, tamanhoDoVetor);
    imprimeVetor(vetorA, 'A', tamanhoDoVetor);
    imprimeVetor(vetorB, 'B', tamanhoDoVetor);
    imprimeVetor(vetorInterseccao, 'I', tamanhoDoVetor*2);
    imprimeVetor(conjuntoUniao, 'U', tamanhoDoVetor*2);


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


void recebeElementosNoVetor(int vetor[], int tamanhoDoVetor, char nomeVetor) {
    int i;

    printf("\n");
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("Vetor %c[%d]: ", nomeVetor, i);
        scanf("%d", &vetor[i]);
        setbuf(stdin, NULL);
    }
}


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor) {
    int i;

    printf("\nVetor %c: ", nomeVetor);
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int estaContido(int elemento, int vetor[], int tamanhoDoVetor) {
    int i;
    
    for (i=0; i<tamanhoDoVetor; i++) {
        if (vetor[i] == elemento) {
            return 1;
        }
    } 

    return -1;
}


void criaConjuntoUniao(int vetorA[], int vetorB[], int conjuntoUniao[], int vetorInterseccao[], int tamanhoDoVetor) {
    int i, j=0;

    for (i=0; i<tamanhoDoVetor; i++) {
        if (estaContido(vetorA[i], vetorInterseccao, tamanhoDoVetor) == -1) {
            conjuntoUniao[j] = vetorA[i];
            j++;
        }
        if (estaContido(vetorB[i], vetorInterseccao, tamanhoDoVetor) == -1) {
            conjuntoUniao[j] = vetorB[i];
            j++;
        }
    }

}


void criaConjuntoInterseccao(int vetorA[], int vetorB[], int vetorInterseccao[], int tamanhoDoVetor) {
    int i, j=0;

    for (i=0; i<tamanhoDoVetor; i++) {
        if (estaContido(vetorA[i], vetorB, tamanhoDoVetor) == 1 && 
            estaContido(vetorA[i], vetorInterseccao, tamanhoDoVetor*2)) {
            vetorInterseccao[j] = vetorA[i];
            j++;
        }
    }

}
