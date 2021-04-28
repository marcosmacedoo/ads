#include <stdio.h>
#include <stdlib.h>
#include "interface.c"


long iFuncionario = 1000;


void adicionaFuncionario(int posicao) {
    cabecalho("CADASTRO");
    
    funcionarios[posicao].idFuncionario = iFuncionario;

    printf(" CPF: ");
    setbuf(stdin, NULL);
    fgets(funcionarios[posicao].cpf, SIZE_CPF, stdin);

    printf(" NOME: ");
    setbuf(stdin, NULL);
    fgets(funcionarios[posicao].nome, SIZE_NOME, stdin);

    printf(" DATA NASCIMENTO: ");
    setbuf(stdin, NULL);
    fgets(funcionarios[posicao].dataNascimento, SIZE_DATA, stdin);

    printf(" ENDERECO: ");
    setbuf(stdin, NULL);
    fgets(funcionarios[posicao].endereco, SIZE_DESCRICAO, stdin);

    printf(" SALARIO: ");
    setbuf(stdin, NULL);
    scanf("%lf", &funcionarios[posicao].salario);

    printf(" SEXO: ");
    setbuf(stdin, NULL);
    scanf("%c", &funcionarios[posicao].sexo);

    iFuncionario++;
}


void listarFuncionarios(int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("\n--------------------------------------------\n");
        printf("ID ===> %li\n", funcionarios[i].idFuncionario);
        printf("NOME ===> %s", funcionarios[i].nome);
        printf("SALARIO ===> %.2f\n", funcionarios[i].salario);
    }
    printf("--------------------------------------------\n");
}


void mFuncionarios() {
    int opcaoMenuFuncionarios, tFuncionarios = 1;
    
    funcionarios = (Funcionario*) malloc(sizeof(Funcionario)); 

    menuFuncionarios();
    setbuf(stdin, NULL);
    scanf("%d", &opcaoMenuFuncionarios);

    switch (opcaoMenuFuncionarios) {
        case 1:
            adicionaFuncionario(0);
            //system("clear");
            break;
        
        case 2:
            listarFuncionarios(tFuncionarios);
            break;

        default:
            printf("\nERRO: Opcao invalida\n");
            break;
    }

}