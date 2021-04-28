#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double ladoQuadrado, areaQuadrado;

    printf("Lado do quadrado: ");
    scanf("%lf", &ladoQuadrado);

    areaQuadrado = calculaAreaQuadrado(ladoQuadrado);
    
    printf("Area do quadrado: %.2f\n", areaQuadrado);

    return 0;
}
