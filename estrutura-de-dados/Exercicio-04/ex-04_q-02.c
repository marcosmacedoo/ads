#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

#define SIZE_ESTACIONAMENTO 5


// ESTRUTURAS
typedef struct estruturaCarro{
    int placa;
    int qtdManobras;
} Carro;

typedef struct estruturaEstacionamento{
    int topo;
    Carro carros[SIZE_ESTACIONAMENTO];
} Estacionamento;


// DECLARACOES DE FUNCOES
void limpaTela();
void cabecalho(char titulo[]);
void menu();
void inicializaEstacionamento(Estacionamento *est);
bool estacionamentoCheio(Estacionamento *est);
bool estacionamentoVazio(Estacionamento *est);
void mostraCarro(int posicao, Estacionamento *est);
void mostraEstacionamento(Estacionamento *est);
void entrarEstacionamento(Estacionamento *est);
void push(Estacionamento *est, Carro c);
void pop(Estacionamento *estacionamento);
void excluirCarro(Estacionamento *est, int placa);
void sairEstacionamento(Estacionamento *est);


// VARIAVEIS GLOBAIS
Estacionamento estacionamento;
char enter;


//FUNCOES
int main() {
    int opcao;

    inicializaEstacionamento(&estacionamento);

    do {
        menu();
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        system("clear");
        switch (opcao) {
            case 1:
                entrarEstacionamento(&estacionamento);
                limpaTela();
                break;
            
            case 2:
                sairEstacionamento(&estacionamento);
                limpaTela();
                break;
            
            case 3:
                mostraEstacionamento(&estacionamento);
                limpaTela();
                break;

            default:
                break;
        }
    } while (opcao != 4);


    return 0;
}


void limpaTela() {
    printf("\n APERTE ENTER PARA VOLTAR...");
    enter = getchar();
    setbuf(stdin, NULL);
    system("clear");
}


void cabecalho(char titulo[]) {
    printf("\n----------------------------------\n");
    printf("\t%s\n", titulo);
    printf("----------------------------------\n");
}


void menu() {
    cabecalho("ESTACIONAMENTO");
    printf("1 ======> ENTRAR\n");
    printf("2 ======> SAIR\n");
    printf("3 ======> EXIBIR\n");
    printf("4 ======> ENCERRAR\n");
    printf("OPCAO ==> ");
}


void inicializaEstacionamento(Estacionamento *est) {
    est->topo = -1;
}


bool estacionamentoCheio(Estacionamento *est) {
    if (est->topo == SIZE_ESTACIONAMENTO-1) {
        return true;
    }

    return false;
}


bool estacionamentoVazio(Estacionamento *est) {
    if (est->topo == -1) {
        return true;
    }

    return false;
}


void push(Estacionamento *est, Carro c) {
    if (!estacionamentoCheio(est)) {
        est->topo = est->topo + 1;
        est->carros[est->topo] = c;
    }
}


void pop(Estacionamento *estacionamento) {
    if (!estacionamentoVazio(estacionamento)) {
        estacionamento->topo = estacionamento->topo - 1;
    }
}


void mostraCarro(int posicao, Estacionamento *est) {
    printf(" PLACA =====> %d\n", est->carros[posicao].placa);
    printf(" MANOBRAS ==> %d\n", est->carros[posicao].qtdManobras);
    printf("----------------------------------\n");
}


void mostraEstacionamento(Estacionamento *est) {
    int i;

    if (estacionamentoVazio(est)) {
        printf(" ESTACIONAMENTO VAZIO!\n");
    }
    else {
        cabecalho("ESTACIONAMENTO");
        for (i = 0; i <= est->topo; i++) {
            mostraCarro(i, est);
        }
    }
}


void entrarEstacionamento(Estacionamento *est) {
    int placa;
    Carro c;

    if (estacionamentoCheio(est)) {
        printf("\n NAO HA VAGAS\n");
    }
    else {
        cabecalho("CARRO");
        printf(" PLACA: ");
        scanf("%d", &placa);
        setbuf(stdin, NULL);
        c.placa = placa;
        c.qtdManobras = 1;
        push(est, c);
    }
}


void excluirCarro(Estacionamento *est, int placa) {
    int i;
    Estacionamento reserva;

    inicializaEstacionamento(&reserva);
    
    for (i = 0; i <= est->topo; i++) {
        est->carros[i].qtdManobras += 1;
        if (est->carros[i].placa != placa) {
            push(&reserva, est->carros[i]);
        }
        else {
            printf("\n MANOBRAS: %d\n", est->carros[i].qtdManobras);
        }
    }

    inicializaEstacionamento(est);

    for (i = 0; i <= reserva.topo; i++) {
        reserva.carros[i].qtdManobras += 1;
        push(est, reserva.carros[i]);
    }

}


void sairEstacionamento(Estacionamento *est) {
    int placa;

    if (estacionamentoVazio(est)) {
        printf("\n ESTACIONAMENTO VAZIO!\n");
    }
    else {
        cabecalho("SAIR");
        printf(" PLACA: ");
        scanf("%d", &placa);
        setbuf(stdin, NULL);
        excluirCarro(est, placa);
    }

}