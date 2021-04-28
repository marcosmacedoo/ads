#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Elemento {
    int item;
    Elemento *prox;
};


struct Pilha {
    int tamanho;
    Elemento *topo;
};


void inicializarPilha(Pilha *pilha) {
    pilha->tamanho = 0;
    pilha->topo = NULL;
}


bool pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}


bool push(Pilha *pilha, char novoItem) {
    Elemento *novoElemento;

    novoElemento = (Elemento*) malloc(sizeof(Elemento));

    if (novoElemento == NULL) {
        return false;
    }

    novoElemento->item = novoItem;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
    pilha->tamanho++;
    return true;
}   


bool pop(Pilha *pilha) {
    Elemento *temp;

    if (pilhaVazia(pilha)) {
        return false;
    }

    temp = pilha->topo;
    pilha->topo = temp->prox;
    pilha->tamanho--;
    free(temp);
    temp = NULL;

    return true;
}


bool esvaziarPilha(Pilha *pilha) {
    Elemento *temp;

    if (pilhaVazia(pilha)) {
        return false;
    }

    while (pilha->topo != NULL) {
        temp = pilha->topo;
        pilha->topo = temp->prox;
        temp = NULL;
        free(temp);
    }

    pilha->tamanho = 0;
    return true;
}


void exibirPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("\n Pilha Vazia \n");
    } else {
        Elemento *elemento;
        elemento = pilha->topo;

        printf(" Pilha: \n");

        while (elemento != NULL) {
            printf("\t  %d \n", elemento->item);
            elemento = elemento->prox;
        }

        printf("\n");
    }
}


int main() {
    Pilha pilha;

    inicializarPilha(&pilha);

    // Q1
    push(&pilha, 1);
    push(&pilha, 2);
    exibirPilha(&pilha);

    //Q2
    esvaziarPilha(&pilha);
    push(&pilha, -1);
    exibirPilha(&pilha);

    //Q3
    push(&pilha, 4);
    push(&pilha, 5);
    exibirPilha(&pilha);

    //Q4
    pop(&pilha);
    pop(&pilha);
    exibirPilha(&pilha);

    //Q5
    push(&pilha, 9);
    exibirPilha(&pilha);

    //Q6
    esvaziarPilha(&pilha);
    push(&pilha, -9);


    return 0;
}