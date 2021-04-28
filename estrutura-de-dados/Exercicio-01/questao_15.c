#include <stdio.h>
#include <stdlib.h>


int main() {
    int numeroJogador, i, jogador[23];

    i = 0;
    printf("Enquete: Quem foi o melhor jogador(1 - 23)?\n");
    while (1) {
        printf("Numero do jogador: ");
        scanf("%d", &numeroJogador);
        if (numeroJogador == 0) {
            break;
        }
        else if (numeroJogador < 1 && numeroJogador > 23) {
            printf("Informe um valor entre 1 e 23 ou 0 para sair\n");
        } 
        else {
            jogador[numeroJogador-1] += 1;
        }
        i++;
    }

    return 0;
}


