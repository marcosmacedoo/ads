#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10


void imprimeVetor(int vetor[], int tamanhoDoVetor);
void insereDadosDeLancamentos(int lancamentos[], int tamanhoVetor);
int retornaRepeticoesDeElementos(int lancamentos[], int tamanhoDoVetor, int elemento);
double calculaPercentual(int qtd);
void imprimeVetorPercentuais(double percentuais[]);
void inserePercentuaisVetor(int lancamentos[], double percentuais[], int tamanhoVetor);


int main() {
    int lancamentos[N];
    double percentuais[6];

    insereDadosDeLancamentos(lancamentos, N);
    inserePercentuaisVetor(lancamentos, percentuais, N);
    imprimeVetor(lancamentos, N);
    imprimeVetorPercentuais(percentuais);

    return 0;
}


void insereDadosDeLancamentos(int lancamentos[], int tamanhoVetor) {
    int i, jogada;
    
    srand(time(NULL));

    for (i=0; i<tamanhoVetor; i++) {
        jogada = rand() % 7;
        if (jogada != 0) { 
            lancamentos[i] = jogada;
        }
        else {
            while (jogada == 0) {
                jogada = rand() % 7;
            }
            lancamentos[i] = jogada;
        }
    }
    
}


int retornaRepeticoesDeElementos(int lancamentos[], int tamanhoDoVetor, int elemento) {
    int i, count;

    count = 0;
    for (i=0; i<tamanhoDoVetor; i++) {
        if (lancamentos[i] == elemento) {
            count++;
        }
    }

    return count;
}


double calculaPercentual(int qtd) {
    return (qtd*100) / 6.0;
}


void inserePercentuaisVetor(int lancamentos[], double percentuais[], int tamanhoVetor) {
    int qtdUm, qtdDois, qtdTres, qtdQuatro, qtdCinco, qtdSeis;

    qtdUm = 0; qtdDois = 0; qtdTres = 0; qtdQuatro = 0; qtdCinco = 0; qtdSeis = 0;
    qtdUm = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 1);
    qtdDois = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 2);
    qtdTres = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 3);
    qtdQuatro = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 4);
    qtdCinco = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 5);
    qtdSeis = retornaRepeticoesDeElementos(lancamentos, tamanhoVetor, 6);
    percentuais[0] = calculaPercentual(qtdUm);
    percentuais[1] = calculaPercentual(qtdDois);
    percentuais[2] = calculaPercentual(qtdTres);
    percentuais[3] = calculaPercentual(qtdQuatro);
    percentuais[4] = calculaPercentual(qtdCinco);
    percentuais[5] = calculaPercentual(qtdSeis);
}


void imprimeVetorPercentuais(double percentuais[]) {
    int i;

    printf("Percentuais: \n");
    for (i=0; i<6; i++) {
        printf("Alvo %d: %.2f%%\n", i+1, percentuais[i]);
    }

}


void imprimeVetor(int vetor[], int tamanhoDoVetor) {
    int i;

    printf("Lancamentos: ");
    for (i=0; i<tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
