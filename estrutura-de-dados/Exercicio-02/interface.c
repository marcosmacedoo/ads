#include <stdio.h>


void cabecalho(char titulo[]) {
    printf("\n---------------------------------------------------------");
    printf("\n\t\t\t %s", titulo);
    printf("\n---------------------------------------------------------\n");
}


void menuPrincipal() {
    cabecalho("MENU");
    printf(" 1 ========> NOVO FUNCIONARIO\n");
    printf(" 2 ========> LISTAR FUNCIONARIOS\n");
    printf(" 3 ========> EDITAR FUNCIONARIO\n");
    printf(" 4 ========> REMOVER FUNCIONARIO\n");
    printf(" 5 ========> REALIZAR ATENDIMENTO\n");
    printf(" 6 ========> LISTAR ATENDIMENTOS\n");
    printf(" 7 ========> LISTAR USUARIOS\n");
    printf(" 8 ========> EDITAR USUARIO\n");
    printf(" 9 ========> REMOVER USUARIO\n");
    printf(" 10 =======> SAIR\n");
    printf(" OPÇÃO ====> ");
}
