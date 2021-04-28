#include <stdio.h>
#include <math.h>


void insereValoresNoVetor(int vetor[], int tamanhoVetor);
int calculaS(int vetor[], int tamanhoDoVetor);


int main() {
    int tamanhoDoVetor, s;
    tamanhoDoVetor = 20;
    int vetor[tamanhoDoVetor];

    insereValoresNoVetor(vetor, tamanhoDoVetor);
    s = calculaS(vetor, tamanhoDoVetor);

    printf("\nS = %d\n", s);

    return 0;
}


void insereValoresNoVetor(int vetor[], int tamanhoVetor) {
    int i;

    printf("\n");
    for (i=0; i<tamanhoVetor; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        setbuf(stdin, NULL);
    }
}


int calculaS(int vetor[], int tamanhoDoVetor) {
    int s, i, j=tamanhoDoVetor;

    for (i=0; i<tamanhoDoVetor; i++) {
        s += pow((vetor[i] - vetor[j]), 2);
        j--;
    }
    
    return s;
}
