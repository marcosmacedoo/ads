#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int horas, minutos, minutosTotal;

    printf("Hora: ");
    scanf("%d", &horas);
    printf("Minutos: ");
    scanf("%d", &minutos);

    minutosTotal = converteHoraEmMinutos(horas, minutos);

    printf("%d minutos\n", minutosTotal);

    return 0;
}
