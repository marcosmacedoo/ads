#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double temperaturaF, temperaturaC;

    printf("Temperatura ºF: ");
    scanf("%lf", &temperaturaF);

    temperaturaC = converteTemperaturaFParaC(temperaturaF);
    printf("%.2f ºC\n", temperaturaC);

    return 0;
}
