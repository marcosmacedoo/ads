#include <stdio.h>
#include <stdlib.h>


void imprimeNotas(double notas[], int tamanho, int inverso);
void imprimeDados(double notas[], double somaNotas, double mediaNotas, 
            int qtdNotasAcimaDeSete, int qtdNotasAbaixoDeSete, int totalNotas);


int main() {
    double *notas, nota, somaNotas, mediaNotas;
    int totalNotas, qtdNotasAcimaDeSete, qtdNotasAbaixoDeSete;

    notas = (double*) malloc(sizeof(double));
    totalNotas = 0;
    qtdNotasAcimaDeSete = 0;


    while (1) {
        printf("Digite um nota[%d](break = -1): ", totalNotas);
        scanf("%lf", &nota);
        setbuf(stdin, NULL);
        if (nota == -1) {
            break;
        }
        else if (nota >= 7.0) {
            qtdNotasAcimaDeSete++;
        }
        notas[totalNotas] = nota;
        somaNotas += nota;
        totalNotas++;
    }

    qtdNotasAbaixoDeSete = totalNotas - qtdNotasAcimaDeSete;
    mediaNotas = somaNotas/totalNotas;

    imprimeDados(notas, somaNotas, mediaNotas, qtdNotasAcimaDeSete, 
                qtdNotasAbaixoDeSete, totalNotas);

    
    return 0;
}


void imprimeNotas(double notas[], int tamanho, int inverso) {
    int i;

    printf("Notas: ");
    if (inverso == 0) {
        for (i = 0; i < tamanho; i++) {
            printf("%.2f ", notas[i]);
        }
    }
    else {
        for (i = tamanho-1; i >= 0; i--) {
            printf("%.2f ", notas[i]);
        }
    }
    printf("\n");

}


void imprimeDados(double notas[], double somaNotas, double mediaNotas, 
                  int qtdNotasAcimaDeSete, int qtdNotasAbaixoDeSete, int totalNotas){
    printf("\n----------------------------------------\n");
    printf("\t\tInformacoes\n");
    printf("----------------------------------------\n");
    printf("Foram coletadas %d notas\n", totalNotas);
    imprimeNotas(notas, totalNotas, 0);
    imprimeNotas(notas, totalNotas, 1);
    printf("Soma das notas = %.2f\n", somaNotas);
    printf("Media da notas = %.2f\n", mediaNotas);
    printf("%d notas ficaram acima de 7 (sete)\n", qtdNotasAcimaDeSete);
    printf("%d notas ficaram abaixo de 7 (sete)\n", qtdNotasAbaixoDeSete);

}
