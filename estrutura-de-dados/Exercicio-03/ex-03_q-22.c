#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double raioEsfera, volumeEsfera;

    printf("Raio da esfera: ");
    scanf("%lf", &raioEsfera);

    volumeEsfera = calculaVolumeEsfera(raioEsfera);
    printf("Volume da esfera = %.2f\n", volumeEsfera);

    return 0;
}
