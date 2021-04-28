#include <stdio.h>
#include <ctype.h>


void imprimeDados(double media, double saltos[], char nomeDoAtleta[]);


int main() {
    char nomeDoAtleta[50];
    int i;
    double saltos[5], media, soma;

    while (1) {
        printf("\nDigite o nome do atleta: ");
        fgets(nomeDoAtleta, 50, stdin);
        if (isspace(nomeDoAtleta[0])) { break; }
        for (i=0; i<5; i++) {
            printf("%dº salto: ", i+1);
            scanf("%lf", &saltos[i]);
            setbuf(stdin, NULL);
            soma += saltos[i];
        }
        media = soma/5;
        imprimeDados(media, saltos, nomeDoAtleta);
        soma = 0;
    }

    return 0;
}


void imprimeDados(double media, double saltos[], char nomeDoAtleta[]) {
    int j;
    
    printf("\nResultado final:\n");
    printf("Atleta: %s", nomeDoAtleta);
    printf("Saltos: ");
    for (j=0; j<4; j++) {
        printf("%.1f - ", saltos[j]);
    }
    printf("%.1f\n", saltos[4]);
    printf("Media dos saltos: %.1f m\n", media);
}
