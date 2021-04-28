#include <stdio.h>


int recebeTamanhoDoVetor();
void insereElementosNoVetor(int vetor[], char nomeVetor, int tamanhoVetor);
void insereElementosDeDoisVetores(int vetorA[], int vetorB[], int vetorC[], int tamanhoDoVetor);
void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);


int main() {
    int tamanhoVetor;
    tamanhoVetor = recebeTamanhoDoVetor();
    int vetorA[tamanhoVetor], vetorB[tamanhoVetor], vetorC[tamanhoVetor*2];

    insereElementosNoVetor(vetorA, 'A', tamanhoVetor);
    insereElementosNoVetor(vetorB, 'B', tamanhoVetor);
    insereElementosDeDoisVetores(vetorA, vetorB, vetorC, tamanhoVetor);
    imprimeVetor(vetorA, 'A', tamanhoVetor);
    imprimeVetor(vetorB, 'B', tamanhoVetor);
    imprimeVetor(vetorC, 'C', tamanhoVetor*2);

    return 0;
}


void insereElementosDeDoisVetores(int vetorA[], int vetorB[], int vetorC[], int tamanhoDoVetor) {
    int i, j=0;

    for (i=0; i<tamanhoDoVetor*2; i++) {
        if (i < (tamanhoDoVetor*2)/2){
            vetorC[i] = vetorA[i];    
        }
        else {
            vetorC[i] = vetorB[j];    
            j++;
        }
    }
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


void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor) {
    int i;

    printf("Vetor %c: ", nomeVetor);
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
