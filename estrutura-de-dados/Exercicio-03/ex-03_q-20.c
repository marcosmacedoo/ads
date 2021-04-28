#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double baseRetangulo, alturaRetangulo, areaRetangulo;

    printf("Base do retangulo: ");
    scanf("%lf", &baseRetangulo);
    printf("Altura do retagulo: ");
    scanf("%lf", &alturaRetangulo);

    areaRetangulo = calculaAreaRetangulo(baseRetangulo, alturaRetangulo);
    printf("Area do retangulo: %.2f\n", areaRetangulo);

    return 0;
}
