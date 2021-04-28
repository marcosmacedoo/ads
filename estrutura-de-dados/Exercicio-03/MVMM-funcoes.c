#include <math.h>
#include <string.h>
#include <stdlib.h>
#define pi 3.14


// Q 14
double converteVelocidadeMsParaKm(double velocidadeMs) {
    double velocidadeKmh;
    velocidadeKmh = velocidadeMs * 3.6;

    return velocidadeKmh;
}


// Q 15
int converteHoraEmMinutos(int hora, int minuto) {
    int minutosTotal;
    minutosTotal = (hora * 60) + minuto;

    return minutosTotal;
}


// Q 16
double converteDolarParaReal(double valorEmDolar, double cotacaoDoDolar) {
    double valorEmReal;
    valorEmReal = valorEmDolar * cotacaoDoDolar;

    return valorEmReal;
}


// Q 17
double converteVelocidadeKmParaMs(double velocidadeKmh) {
    double velocidadeMs;
    velocidadeMs = velocidadeKmh / 3.6;

    return velocidadeMs;
}


// Q 18
double calculaAreaTriangulo(double baseTriangulo, double alturaTriangulo) {
    double areaTriangulo;
    areaTriangulo = (baseTriangulo * alturaTriangulo) / 2;

    return areaTriangulo;
}


// Q 19
double calculaAreaQuadrado(double ladoQuadrado) {
    double areaQuadrado;
    areaQuadrado = ladoQuadrado * ladoQuadrado;

    return areaQuadrado;
}


// Q 20
double calculaAreaRetangulo(double baseRetangulo, double alturaRetangulo) {
    double areaRetangulo;
    areaRetangulo = baseRetangulo * alturaRetangulo;

    return areaRetangulo;
}


// Q 21
double calculaComprimentoCircunferencia(double raioCircunferencia) {
    double comprimentoCircunferencia;
    comprimentoCircunferencia = 2 * pi * raioCircunferencia;

    return comprimentoCircunferencia;
}


// Q 22
double calculaVolumeEsfera(double raioEsfera) {
    double volumeEsfera;
    volumeEsfera = (4.0 * pi * pow(raioEsfera, 3)) / 3.0;

    return volumeEsfera;
}


// Q 23
double converteTemperaturaCParaF(double temperaturaC) {
    double temperaturaF;
    temperaturaF = (9.0 * temperaturaC + 160.0) / 5.0;

    return temperaturaF;
}


// Q 24
double converteTemperaturaFParaC(double temperaturaF) {
    double temperaturaC;
    temperaturaC = (5.0 * temperaturaF - 160) / 9.0;

    return temperaturaC;
}


// Q 25

int calculaFatorial(int numero) {
    if (numero == 1) {
        return numero;
    }
    numero = numero * calculaFatorial(numero - 1);
}


// Q 26
int ehNumeroPrimo(int numero) {
    int i;

    if (numero == 1) return -1;
    i = numero - 1; 

    while (i > 1) {
        if (numero % i == 0) {
            return 0;
        }
        i--;
    }

    return 1;
}


// Q 27
void quebraDataString(char dataString[], int dataInteiro[]) {
    int tamanhoDataString, i, j, k, dia, mes, ano;
    char substring[5];

    tamanhoDataString = strlen(dataString);
    j = 0;
    k = 0;

    for (i = 0; i < tamanhoDataString; i++) {
        if (dataString[i] == '/') {
            if (j == 0) {
                dia = atoi(substring);
            }
            else {
                mes = atoi(substring);
            }
            k = 0;
            j = 1;
        }
        else {
            substring[k] = dataString[i];
            k++;
        }
    }

    ano = atoi(substring);
    dataInteiro[0] = dia;
    dataInteiro[1] = mes;
    dataInteiro[2] = ano;

}


int dataEhValida(int dia, int mes, int ano) {
    if (dia >= 1 && dia <= 30 && mes >= 1 && mes <= 12 && ano >= 1) {
        return 1;
    }

    return 0;
}



// Q 28
int calculaMmc(int primeiroNumero, int segundoNumero) {
    int mmc;

    if (primeiroNumero > segundoNumero) mmc = primeiroNumero;
    else mmc = segundoNumero;

    while (!(mmc % primeiroNumero == 0 && mmc % segundoNumero == 0)) {
        mmc++;
    }

    return mmc;
}


// Q 29
int calculaMdc(int primeiroNumero, int segundoNumero) {
    int mdc;

    if (primeiroNumero < segundoNumero) mdc = primeiroNumero;
    else mdc = segundoNumero;

    while (!(primeiroNumero % mdc == 0 && segundoNumero % mdc == 0)) {
        mdc--;
    }

    return mdc;
}


// Q 30
int ehAnoBissexto(int ano) {
    return ano % 4 == 0;
}
