#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nData 11


void preencheDadosInteirosData(char dataEntrada[], int dataInteiro[]);
void buscaMesPorExtenso(int mesInteiro, char mesPorExtenso[]);


int main() {
    char dataEntrada[nData], mesPorExtenso[15];
    int dataInteiro[3], diaInteiro, mesInteiro, anoInteiro;

    printf("Data(DD/MM/AAAA): ");
    fgets(dataEntrada, nData, stdin);

    preencheDadosInteirosData(dataEntrada, dataInteiro);
    diaInteiro = dataInteiro[0];
    mesInteiro = dataInteiro[1];
    anoInteiro = dataInteiro[2];
    buscaMesPorExtenso(mesInteiro, mesPorExtenso);

    printf("%d de %s de %d\n", diaInteiro, mesPorExtenso, anoInteiro);

    return 0;
}


void preencheDadosInteirosData(char dataEntrada[], int dataInteiro[]) {
    int i, j, k, dia, mes, ano;
    char substring[5];

    j = 0; // variavel que diferencia se é mes ou dia, pois '/' irá aparecer duas vezes
    k = 0; // contadora da String substring

    for (i = 0; i < nData; i++) {
        if (dataEntrada[i] == '/') {
            if (j == 0) { //DIA
                dia = atoi(substring);
            }
            else { //MES
                mes = atoi(substring);
            }
            j = 1;
            k = 0;
        }
        else {
            substring[k] = dataEntrada[i];
            k++;
        }
    }

    ano = atoi(substring);

    dataInteiro[0] = dia;
    dataInteiro[1] = mes;
    dataInteiro[2] = ano;
    
}


void buscaMesPorExtenso(int mesInteiro, char mesPorExtenso[]) {
    if (mesInteiro == 1) strcpy(mesPorExtenso, "Janeiro");
    else if (mesInteiro == 2) strcpy(mesPorExtenso, "Fevereiro");
    else if (mesInteiro == 3) strcpy(mesPorExtenso, "Marco");
    else if (mesInteiro == 4) strcpy(mesPorExtenso, "Abril");
    else if (mesInteiro == 5) strcpy(mesPorExtenso, "Maio");
    else if (mesInteiro == 6) strcpy(mesPorExtenso, "Junho");
    else if (mesInteiro == 7) strcpy(mesPorExtenso, "Julho");
    else if (mesInteiro == 8) strcpy(mesPorExtenso, "Agosto");
    else if (mesInteiro == 9) strcpy(mesPorExtenso, "Setembro");
    else if (mesInteiro == 10) strcpy(mesPorExtenso, "Outubro");
    else if (mesInteiro == 11) strcpy(mesPorExtenso, "Novembro");
    else if (mesInteiro == 12) strcpy(mesPorExtenso, "Dezembro");
}
