#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double temperaturaC, temperaturaF;

    printf("Temperatura em ºC: ");
    scanf("%lf", &temperaturaC);

    temperaturaF = converteTemperaturaCParaF(temperaturaC);
    printf("%.2f ºF\n", temperaturaF);

    return 0;
}
