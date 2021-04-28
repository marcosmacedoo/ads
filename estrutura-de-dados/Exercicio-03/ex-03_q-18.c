#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double baseTriangulo, alturaTriangulo, areaTriangulo;

    printf("Base do triangulo: ");
    scanf("%lf", &baseTriangulo);
    printf("Altura do triangulo: ");
    scanf("%lf", &alturaTriangulo);

    areaTriangulo = calculaAreaTriangulo(baseTriangulo, alturaTriangulo);

    printf("Area do triangulo: %.2f\n", areaTriangulo);

    return 0;
}
