#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define SIZE_LINHA 100
#define SIZE_TAG 15


struct Elemento {
    char tag[SIZE_TAG];
    Elemento *prox;
};


struct Pilha {
    int tamanho;
    Elemento *topo;
};


void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}


bool pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}


bool push(Pilha *pilha, char novaTag[]) {
    Elemento *novoElemento;
    novoElemento = (Elemento*) malloc(sizeof(Elemento)); 

    if (novoElemento == NULL) {
        return false;
    }

    strcpy(novoElemento->tag, novaTag);
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


bool esvaziar(Pilha *pilha) {
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
            printf("\t  %s \n", elemento->tag);
            elemento = elemento->prox;
        }

        printf("\n");
    }
}


bool ehTagDeFechamento(char tag[]) {
    return (tag[0] == '<' && tag[1] == '/');
}


char *nomeDaTag(char tag[]) {
    char *nomeTag;
    int j;

    nomeTag = (char*) malloc(sizeof(char));
    j = 0;

    for (int i = 0; i < strlen(tag); i++) {
        if (tag[i] != '<' && tag[i] != '/' && tag[i] != '>') {
            nomeTag[j] = tag[i];
            j++;
            nomeTag = (char*) realloc(nomeTag, sizeof(char) * (j+1));
        }
    }

    return nomeTag; 
}


void extrairTagsLinha(char linhaArquivoHTML[], Pilha *pilha) {
    char *tag, *nomeTag, *nomeTagTopo;
    int j, i;

    j = 0;
    i = 0;
    tag = (char*) malloc(sizeof(char));

    while (i < strlen(linhaArquivoHTML)) {
        if (linhaArquivoHTML[i] == '<') {
            while (linhaArquivoHTML[i] != '>') {
                tag[j] = linhaArquivoHTML[i];
                j++;
                i++;
                tag = (char*) realloc(tag, sizeof(char) * (j+1));
            }
            tag[j] = linhaArquivoHTML[i];
            nomeTag = nomeDaTag(tag);

            if (pilhaVazia(pilha)) {
                push(pilha, tag);
            } else {
                nomeTagTopo = nomeDaTag(pilha->topo->tag);
                if (strcmp(nomeTagTopo, nomeTag) == 0 && ehTagDeFechamento(tag)) {
                    pop(pilha);
                } else {
                    push(pilha, tag);
                }
            }

            //exibirPilha(pilha);
            j = 0;
        }
        tag = (char*) malloc(sizeof(char));
        i++;
    }

    free(tag);
}


int main() {
    Pilha pilha;
    char linhaArquivoHTML[SIZE_LINHA];

    FILE *arquivoHTML = fopen("index.html", "r");
    inicializaPilha(&pilha);

    if (arquivoHTML == NULL) {
        printf("\n Arquivo indisponível \n");
    } else {
        while (!feof(arquivoHTML)) {
            fgets(linhaArquivoHTML, SIZE_LINHA, arquivoHTML);
            extrairTagsLinha(linhaArquivoHTML, &pilha);
        }
    }

    if (pilha.tamanho == 0) {
        printf(" Arquivo sem erros \n");
    } else {
        printf(" Arquivo contém tag(s) não fechada(s) \n");
    }

    fclose(arquivoHTML);

    return 0;  
}