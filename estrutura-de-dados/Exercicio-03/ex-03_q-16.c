#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    double cotacaoDoDolar, valorEmDolar, valorEmReal;

    printf("Cotacao do dolar: ");
    scanf("%lf", &cotacaoDoDolar);
    printf("Valor em dolar: ");
    scanf("%lf", &valorEmDolar);

    valorEmReal = converteDolarParaReal(valorEmDolar, cotacaoDoDolar);
    
    printf("R$ %.2f\n", valorEmReal);

    return 0;
}
