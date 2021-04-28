#include <stdio.h>
#include "MVMM-funcoes.c"


int main() {
    int dataInteiro[3], dia, mes, ano;
    char dataString[11];

    printf("Data (dd/mm/aaaa): ");
    fgets(dataString, 11, stdin);
    
    quebraDataString(dataString, dataInteiro);
    dia = dataInteiro[0];
    mes = dataInteiro[1];
    ano = dataInteiro[2];
    if (dataEhValida(dia, mes, ano)) {
        printf("Data eh valida!\n");
    }
    else {
        printf("Data nao eh valida!\n");
    }


    return 0;
}
