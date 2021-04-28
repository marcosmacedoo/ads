#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>


#define TAM 5


typedef struct {
    int elementos[TAM];
    int primeiro, ultimo;
} Lista;


void inicializarLista(Lista *lista) {
    lista->primeiro = 0;
    lista->ultimo = 0;
}


bool listaEstaVazia(Lista *lista) {
    return lista->ultimo == lista->primeiro;
}


bool listaEstaCheia(Lista *lista) {
    return lista->ultimo == (TAM - 1);
}


int tamanhoLista(Lista *lista) {
    return lista->ultimo;
}


void exibirLista(Lista *lista) {
    if (!listaEstaVazia(lista)) {
        printf(" Lista:");
        for (int i = 0; i < lista->ultimo; i++) {
            printf(" %d |", lista->elementos[i]);
        }
    } else {
        printf(" Ops, lista vazia");
    }
    printf("\n");
}


int buscaSequencial(Lista *lista, int elemento) {
    int pos = -1;
    for (int i = 0; i < lista->ultimo; i++) {
        if (lista->elementos[i] == elemento) {
            pos = i;
            break;
        }
    }

    return pos;
}


int primeiroElemento(Lista *lista) {
    return lista->elementos[lista->primeiro];
}


int ultimoElemento(Lista *lista) {
    return lista->elementos[lista->ultimo-1];
}


bool posicaoEhValida(Lista *lista, int posicao) {
    return (posicao >= lista->primeiro) && (posicao <= lista->ultimo);
}


bool inserirElemento(Lista *lista, int elemento, int posicao) {
    if (!listaEstaCheia(lista) && posicaoEhValida(lista, posicao)) {
        for (int i = lista->ultimo; i > posicao; i--) {
            lista->elementos[i] = lista->elementos[i-1];
        }
        lista->elementos[posicao] = elemento;
        lista->ultimo++;
        
        return true;
    }

    return false;
}


bool removerElemento(Lista *lista, int elemento) {
    int posicaoElemento = buscaSequencial(lista, elemento);    
    if (posicaoElemento != -1) {
        for (int i = posicaoElemento; i < lista->ultimo; i++) {
            lista->elementos[i] = lista->elementos[i+1];
        }
        lista->ultimo--;

        return true;
    }
    
    return false;
}


void destruicaoLista(Lista *lista) {
    inicializarLista(lista);
}   


void menu(Lista *lista) {
    exibirLista(lista);
    printf(" 1 -> Inserir elemento\n");
    printf(" 2 -> Remover elemento\n");
    printf(" 3 -> Consultar elemento\n");
    printf(" 4 -> Primeiro elemento\n");
    printf(" 5 -> Último elemento\n");
    printf(" 6 -> Tamanho da lista\n");
    printf(" 7 -> Sair\n");
    printf(" Opção: ");

}


void opcao1(Lista *lista) {
    int elemento, posicao;

    printf("\n Elemento: ");
    scanf("%d", &elemento);
    setbuf(stdin, NULL);

    printf(" Posição: ");
    scanf("%d", &posicao);
    setbuf(stdin, NULL);

    if (!inserirElemento(lista, elemento, posicao)) {
        printf(" Não foi possível realizar a inserção\n");
    } else {
        printf(" Inserção realizada\n");
    }
}


void limparTela() {
    char c;

    printf("\n Aperter qualquer tecla para continuar");
    scanf("%c", &c);
    setbuf(stdin, NULL);
    system("clear");
}


void opcao2(Lista *lista) {
    int elemento;

    printf("\n Elemento: ");
    scanf("%d", &elemento);
    setbuf(stdin, NULL);
    
    if (!removerElemento(lista, elemento)) {
        printf("\n Não foi possível remover o elemento");
    } else {
        printf("\n Elemento removido");
    }
}


void opcao3(Lista *lista) {
    int elemento, pos;

    printf("\n Elemento: ");
    scanf("%d", &elemento);
    setbuf(stdin, NULL);

    pos = buscaSequencial(lista, elemento);

    if (pos == -1) {
        printf("\n Elemento não encontrado");
    } else {
        printf("\n Elemento na posição %d", pos);
    }
}


void opcao4(Lista *lista) {
    int elemento;

    elemento = primeiroElemento(lista);
    printf("\n Primeiro elemento -> %d", elemento);
}


void opcao5(Lista *lista) {
    int elemento;

    elemento = ultimoElemento(lista);
    printf(" Ultimo elemento -> %d", elemento);
}


void opcao6(Lista *lista) {
    int tamanho;

    tamanho = tamanhoLista(lista);
    printf("\n Tamanho da lista -> %d", tamanho);
}


int main() {
    Lista lista;
    int opcao;

    inicializarLista(&lista);
    
    do {
        menu(&lista);
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1:
                opcao1(&lista);
                break;
            
            case 2:
                opcao2(&lista);
                break;

            case 3:
                opcao3(&lista);
                break;

            case 4:
                opcao4(&lista);
                break;

            case 5:
                opcao5(&lista);
                break;

            case 6:
                opcao6(&lista);
                break;

            default:
                break;
        }

        limparTela();

    } while (opcao != 7);

    return 0;
}
