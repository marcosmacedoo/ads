#include <stdio.h>
#include <math.h>
#define N 8


void recebeValores(int numeroBinario[], int tamanhoDoVetor);
int converteDeBinarioParaDecimal(int numeroBinario[], int tamanhoDoVetor);
void imprimeNumeroBinario(int numeroBinario[], int tamanhoDoVetor);


int main() {
    int numeroBinario[N], numeroDecimal;

    recebeValores(numeroBinario, N);
    numeroDecimal = converteDeBinarioParaDecimal(numeroBinario, N);
    imprimeNumeroBinario(numeroBinario, N);
    printf("Numero decimal: %d\n", numeroDecimal);

    return 0;
}


void recebeValores(int numeroBinario[], int tamanhoDoVetor) {
    int i;

    for (i=0; i<tamanhoDoVetor; i++) {
        printf("V[%d]: ", i);
        scanf("%d", &numeroBinario[i]);
        setbuf(stdin, NULL);
    }

}


int converteDeBinarioParaDecimal(int numeroBinario[], int tamanhoDoVetor) {
    int numeroDecimal, i;
    
    numeroDecimal = 0;
    for (i=0; i<tamanhoDoVetor; i++) {
        if (numeroBinario[i] == 1) {
            numeroDecimal += pow(2, (tamanhoDoVetor-1)-i);
        }
    }

    return numeroDecimal;
}


void imprimeNumeroBinario(int numeroBinario[], int tamanhoDoVetor) {
    int i;

    printf("\nNumero binario: ");
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", numeroBinario[i]);
    }
    printf("\n");
}
