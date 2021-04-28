#include <stdio.h>


int recebeTamanhoDoVetor();


int main() {
    int tamanhoDoVetor, soma=0, i; 
    tamanhoDoVetor = recebeTamanhoDoVetor();
    int vetor[tamanhoDoVetor];
    double media;

    for (i=0; i<tamanhoDoVetor; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
        setbuf(stdin, NULL);
    }

    media = soma/tamanhoDoVetor;
    printf("Soma = %d\n", soma);
    printf("Media = %.2f\n", media);

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
