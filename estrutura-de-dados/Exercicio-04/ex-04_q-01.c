#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define T 3


typedef struct {
    int topo;
    int elementos[T];
} Pilha;


Pilha pilha01, pilha02, pilha03;


void inicializaPilha(Pilha *pilha);
void inicializaPilha01(Pilha *pilha);
bool pilhaCheia(Pilha *p);
bool pilhaVazia(Pilha *p);
void pushPilha(Pilha *p, int elemento);
void popPilha(Pilha *p);
void imprimePilha(Pilha *p, int numeroPilha);
bool pilhaDesequilibrada(Pilha *p);
bool gameOver(Pilha *p1, Pilha *p2, Pilha *p3);
bool movimentoEhValido(Pilha *po, Pilha *pd);
void torreDeHanoi(Pilha *p1, Pilha *p2, Pilha *p3);


int main() {

    inicializaPilha01(&pilha01);
    inicializaPilha(&pilha02);
    inicializaPilha(&pilha03);
    torreDeHanoi(&pilha01, &pilha02, &pilha03);


    return 0;
}


void inicializaPilha(Pilha *pilha) {
    pilha->topo = -1;
}


bool pilhaCheia(Pilha *p) {
    if (p->topo == T-1) {
        return true;
    }

    return false;
}


bool pilhaVazia(Pilha *p) {
    if (p->topo == -1) {
        return true;
    }

    return false;
}


void pushPilha(Pilha *p, int elemento) {
    if (!pilhaCheia(p)) {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = elemento;
    }
}


void popPilha(Pilha *p) {
    if (!pilhaVazia(p)) {
        p->topo = p->topo - 1;
    }
}


void inicializaPilha01(Pilha *pilha) {
    int i;
    
    inicializaPilha(pilha);
    for (i = 1; i <= T; i++) {
        pushPilha(pilha, i);
    }

}


void imprimePilha(Pilha *p, int numeroPilha) {
    int i;

    printf("\n Pilha %d\n", numeroPilha);

    for (i = 0; i <= p->topo; i++) {
        printf(" %d\n", p->elementos[i]);
    }
}


bool pilhaDesequilibrada(Pilha *p) {
    int i;

    for (i = 0; i < T-1; i++) {
        if (p->elementos[i] > p->elementos[i+1]) {
            return true;
        }
    }

    return false;
}


bool gameOver(Pilha *p1, Pilha *p2, Pilha *p3) {
    int i;
    
    if (pilhaCheia(p2) == true && pilhaDesequilibrada(p2) == false) {
        return true;
    }
    else if (pilhaCheia(p3) == true && pilhaDesequilibrada(p3) == false) {
        return true;
    }

    return false;
}


bool movimentoEhValido(Pilha *po, Pilha *pd) {
    if (pilhaCheia(pd)) {  // Se a pilha de destino já estiver cheia
        return false;
    } 
    else if (pilhaVazia(po)) {  // Se a pilha de Origem não contiver elemento
        return false;
    }
    else if (pd->elementos[pd->topo] > po->elementos[po->topo]) {  // Se o elemento da pilha de Destino for maior que 
        return false;                                              // a pilha de Origem
    }

    return true;
}


void torreDeHanoi(Pilha *p1, Pilha *p2, Pilha *p3) {
    int pinoOrigem, pinoDestino, qtdMovimentos;
    Pilha *po, *pd;  // po -> Pilha de Origem
                     // pd -> Pilha de Destino

    qtdMovimentos = 0;

    do {
        system("clear");
        imprimePilha(p1, 1);
        imprimePilha(p2, 2);
        imprimePilha(p3, 3);
        printf("\n\n Movimentos: %d", qtdMovimentos);
        printf("\n Pino origem: ");
        scanf("%d", &pinoOrigem);
        setbuf(stdin, NULL);
        printf(" Pino destino: ");
        scanf("%d", &pinoDestino);
        setbuf(stdin, NULL);

        if (pinoOrigem == 1) { po = p1; }   // Realizando cópia
        else if (pinoOrigem == 2) { po = p2; }
        else if (pinoOrigem == 3) { po = p3; }

        if (pinoDestino == 1) { pd = p1; }
        else if (pinoDestino == 2) { pd = p2; }
        else if (pinoDestino == 3) { pd = p3; }

        if (movimentoEhValido(po, pd)) {
            pushPilha(pd, po->elementos[po->topo]);  // Executando o movimento
            popPilha(po);
            qtdMovimentos++;
        }

    
    } while (!gameOver(p1, p2, p3));
    
    imprimePilha(p1, 1);
    imprimePilha(p2, 2);
    imprimePilha(p3, 3);
    printf(" Movimentos: %d\n", qtdMovimentos);
    printf(" PARABÉNS! VOCE GANHOU O JOGO!\n");
}
