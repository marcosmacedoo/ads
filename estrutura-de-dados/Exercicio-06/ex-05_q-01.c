#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <string.h>


#define SIZE_FILA 5
#define SIZE_GUICHES 3


// Estruturas
typedef struct estruturaCliente {
    int senha, tempoEspera[3], horarioChegada[3], horarioSaida[3];
} Cliente;


typedef struct estruturaGuiche{
    Cliente cliente;
    int topo;
} Guiche;


typedef struct estruturaFila{
    Cliente clientes[SIZE_FILA];
    int inicio, fim;
} Fila;


// Variaveis globais
Guiche guiches[SIZE_GUICHES];
Fila fila;
int senha = 1000;


// Funções
void inicializarGuiche(Guiche *guiche) {
    guiche->cliente.senha = 0;
    guiche->topo = -1;
}


void inicializarGuiches(Guiche guiches[]) {
    for (int i = 0; i < SIZE_GUICHES; i++) {
        inicializarGuiche(&guiches[i]);
    }
}


bool guicheCheio(Guiche *guiche) {
    return guiche->topo == 0;
}


bool guicheVazio(Guiche *guiche) {
    return guiche->topo == -1;
}


bool pushGuiche(Guiche *guiche, Cliente cliente) {
    if (!guicheCheio(guiche)) {
        guiche->topo++;
        guiche->cliente = cliente;
        return true;
    }
    return false;
}


int temGuicheVazio() {
    for (int i = 0; i < SIZE_GUICHES; i++) {
        if (guicheVazio(&guiches[i])) {
            return i;
        }
    }
    return -1;
}


void adicionaClienteEmGuiche(Cliente cliente) {
    int posicaoGuiche;

    posicaoGuiche = temGuicheVazio();

    if (posicaoGuiche == -1) {
        inicializarGuiches(guiches);
        pushGuiche(&guiches[0], cliente);
    } else {
        pushGuiche(&guiches[posicaoGuiche], cliente);
    }
}


void imprimirGuiche(int numeroGuiche) {
    printf("\n GUICHÊ 0%d: ", numeroGuiche+1);
    printf("%d ", guiches[numeroGuiche].cliente.senha);
    printf("\n-------------------");
}


void imprimirGuiches() {
    imprimirGuiche(0);
    imprimirGuiche(1);
    imprimirGuiche(2);
}


void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
}


bool filaVazia(Fila *fila) {
    return fila->inicio > fila->fim;
}


bool filaCheia(Fila *fila) {
    return fila->fim == SIZE_FILA-1;
}


bool entrarFila(Fila *fila, Cliente novoCliente) {
    if (!filaCheia(fila)) {
        fila->fim++;
        fila->clientes[fila->fim] = novoCliente;
        return true;
    }
    return false;
}


Cliente primeiroFila(Fila *fila) {
    return fila->clientes[fila->inicio];
}


void imprimirRelatorioFinal(Cliente cliente, int numeroGuiche) {
    printf("\n CLIENTE %d FOI ATENDIDO NO GUICHÊ 0%d\n", cliente.senha, numeroGuiche);
    printf(" HORÁRIO DE CHEGADA: %d:%d:%d \n", cliente.horarioChegada[0], cliente.horarioChegada[1], cliente.horarioChegada[2]);
    printf(" HORÁRIO DE SAÍDA: %d:%d:%d \n", cliente.horarioSaida[0], cliente.horarioSaida[1], cliente.horarioSaida[2]);
    printf(" TEMPO DE ESPERA: %d:%d:%d \n", cliente.tempoEspera[0], cliente.tempoEspera[1], cliente.tempoEspera[2]);
}


void capturaHorarioAtual(int horario[]) {
    struct tm *dataHoraAtual;
    time_t segundos;
    
    time(&segundos);
    dataHoraAtual = localtime(&segundos);

    horario[0] = dataHoraAtual->tm_hour;
    horario[1] = dataHoraAtual->tm_min;
    horario[2] = dataHoraAtual->tm_sec;
}


void calculaTempoDeEspera(Cliente cliente) {
    int segundosChegada, segundosSaida, segundosDuracao;

    segundosChegada = (cliente.horarioChegada[0] * 3600) + (cliente.horarioChegada[1] * 60) + cliente.horarioChegada[2];
    segundosSaida = (cliente.horarioSaida[0] * 3600) + (cliente.horarioSaida[1] * 60) + cliente.horarioSaida[2];
    segundosDuracao = segundosSaida - segundosChegada;
    cliente.tempoEspera[0] = segundosDuracao / 3600;
    cliente.tempoEspera[1] = (segundosDuracao % 3600) / 60;
    cliente.tempoEspera[2] = (segundosDuracao % 3600) % 60;
}


bool sairFila(Fila *fila) {
    Cliente primeiroCliente;
    int numeroGuiche;

    if (!filaVazia(fila)) {
        primeiroCliente = primeiroFila(fila);
        numeroGuiche = temGuicheVazio() + 1;
        capturaHorarioAtual(primeiroCliente.horarioSaida);

        int segundosChegada, segundosSaida, segundosDuracao;
        segundosChegada = (primeiroCliente.horarioChegada[0] * 3600) + (primeiroCliente.horarioChegada[1] * 60) + primeiroCliente.horarioChegada[2];
        segundosSaida = (primeiroCliente.horarioSaida[0] * 3600) + (primeiroCliente.horarioSaida[1] * 60) + primeiroCliente.horarioSaida[2];
        segundosDuracao = segundosSaida - segundosChegada;
        primeiroCliente.tempoEspera[0] = segundosDuracao / 3600;
        primeiroCliente.tempoEspera[1] = (segundosDuracao % 3600) / 60;
        primeiroCliente.tempoEspera[2] = (segundosDuracao % 3600) % 60;

        adicionaClienteEmGuiche(primeiroCliente);
        imprimirRelatorioFinal(primeiroCliente, numeroGuiche);
        fila->inicio++;

        return true;
    }
    return false;
}


int tamanhoFila(Fila *fila) {
    return (fila->fim - fila->inicio) + 1;
}


void imprimirFila(Fila *fila) {
    printf("\n FILA: ");

    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("%d ", fila->clientes[i].senha);
    }

    int tamanho = tamanhoFila(fila);
    printf("\n TAMANHO: %d\n", tamanho);
    printf("--------------------------------------------\n");
}


void gerarNovaSenha() {
    senha++;
}


void cabecalho(char titulo[]) {
    printf("\n--------------------------------------------\n");
    printf("\t\t %s \n", titulo);
    printf("--------------------------------------------\n");
}


void menu() {
    cabecalho("SISTEMA");
    printf(" 1 - ENTRAR NA FILA \n");
    printf(" 2 - ATENDIMENTO \n");
    printf(" 3 - VISUALIZAR FILA \n");
    printf(" 4 - VISUALIZAR GUICHÊS \n");
    printf(" 5 - ENCERRAR \n");
    printf(" OPÇÃO: ");
}


void limparTela() {
    char c;

    printf("\n APERTE ENTER PARA VOLTAR...\n");
    scanf("%c", &c);
    setbuf(stdin, NULL);
    system("clear");
}


void criaCliente(Cliente novoCliente) {
    novoCliente.senha = senha;
    capturaHorarioAtual(novoCliente.horarioChegada);
    gerarNovaSenha();
}


void imprimirRelatorioChegada(Cliente novoCliente) {
    cabecalho("CHEGADA");
    printf(" SENHA: %d\n", novoCliente.senha);
    printf(" HORARIO DE CHEGADA: %d:%d:%d\n", novoCliente.horarioChegada[0], 
            novoCliente.horarioChegada[1], novoCliente.horarioChegada[2]);
}


void main() {
    int opcaoMenu;
    Cliente novoCliente;

    inicializarFila(&fila);
    inicializarGuiches(guiches);

    do {
        menu();
        scanf("%d", &opcaoMenu);
        setbuf(stdin, NULL);
        system("clear");

        switch (opcaoMenu) {
            case 1:
                novoCliente.senha = senha;
                capturaHorarioAtual(novoCliente.horarioChegada);
                if (!entrarFila(&fila, novoCliente)) {
                    printf("\n NÃO HÁ VAGAS \n");
                }
                else {
                    imprimirRelatorioChegada(novoCliente);
                    gerarNovaSenha();
                }
                break;
            
            case 2:
                if (!sairFila(&fila)) {
                    printf("\n FILA VAZIA \n");
                } 
                break;
            
            case 3:
                imprimirFila(&fila);
                break;

            case 4:
                imprimirGuiches();
                break;
            
            case 5:
                break;
            
            default:
                printf("\n OPÇÃO INVÁLIDA \n");
                break;
        }

        limparTela();
    } while(opcaoMenu != 5);
}