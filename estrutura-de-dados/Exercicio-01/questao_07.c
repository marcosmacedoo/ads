#include <stdio.h>


int recebeTamanhoDoVetor();
void insereElementosNoVetor(int vetor[], int tamanhoDoVetor);
int retornaMenorElemento(int vetor[], int tamanhoDoVetor);
int retornaPosicaoElemento(int vetor[], int tamanhoDoVetor, int elemento);
void ordenaVetor(int vetorOrigem[], int vetorOrdenado[], int vetorReserva[], int tamanhoDoVetor);
void imprimeVetor(int vetor[], char nomeVetor, int tamanhoDoVetor);


int main() {
    int tamanhoDoVetor, menorElemento;
    tamanhoDoVetor = recebeTamanhoDoVetor();
    int vetorOrigem[tamanhoDoVetor], vetorOrdenado[tamanhoDoVetor], vetorReserva[tamanhoDoVetor];

    insereElementosNoVetor(vetorOrigem, tamanhoDoVetor);
    ordenaVetor(vetorOrigem, vetorOrdenado, vetorReserva, tamanhoDoVetor);
    imprimeVetor(vetorOrdenado, 'O', tamanhoDoVetor);

    return 0;
}


int recebeTamanhoDoVetor() {
    int tamanhoDoVetor;

    do {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoDoVetor);
        setbuf(stdin, NULL);
    } while (tamanhoDoVetor < 1);

    return tamanhoDoVetor;
}


void insereElementosNoVetor(int vetor[], int tamanhoDoVetor) {
    int i;

    for (i=0; i<tamanhoDoVetor; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        setbuf(stdin, NULL);
    }
}


int retornaMenorElemento(int vetor[], int tamanhoDoVetor) {
    int menorElemento, i, elementoAtual;

    menorElemento = vetor[0];
    for (i=1; i<tamanhoDoVetor; i++) {
        elementoAtual = vetor[i];
        if (elementoAtual < menorElemento) {
            menorElemento = elementoAtual;
        }
    }

    return menorElemento;
}


int retornaMaiorElemento(int vetor[], int tamanhoDoVetor) {
    int maiorElemento, i, elementoAtual;

    maiorElemento = vetor[0];
    for (i=1; i<tamanhoDoVetor; i++) {
        elementoAtual = vetor[i];
        if (elementoAtual > maiorElemento) {
            maiorElemento = elementoAtual;
        }
    }

    return maiorElemento;
}


int retornaPosicaoElemento(int vetor[], int tamanhoDoVetor, int elemento) {
    int i;

    for (i=0; i<tamanhoDoVetor; i++) {
        if (vetor[i] == elemento) {
            return i;
        }
    }

    return -1;
}


void ordenaVetor(int vetorOrigem[], int vetorOrdenado[], int vetorReserva[], int tamanhoDoVetor) {
    int i, menorElemento, j, posicaoMenorElemento, maiorElemento;

    j=0;
    for (i=0; i<tamanhoDoVetor; i++) {
        maiorElemento = retornaMaiorElemento(vetorOrigem, tamanhoDoVetor);
        menorElemento = retornaMenorElemento(vetorOrigem, tamanhoDoVetor);
        posicaoMenorElemento = retornaPosicaoElemento(vetorOrigem, tamanhoDoVetor, menorElemento);
        imprimeVetor(vetorOrigem, 'R', tamanhoDoVetor);
        imprimeVetor(vetorOrdenado, 'O', tamanhoDoVetor);
        vetorOrdenado[j] = menorElemento; j++;
        vetorOrigem[posicaoMenorElemento] = maiorElemento;
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

