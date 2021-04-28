// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.c"

// CONSTANTES
#define SIZE_CPF 16
#define SIZE_NOME 60
#define SIZE_DATA 12
#define SIZE_DESCRICAO 100
#define SIZE_HORARIO 9


//ESTRUTURAS
typedef struct tabelaFuncionario {
    long idFuncionario;
    char cpf[SIZE_CPF];
    char nome[SIZE_NOME];
    char dataNascimento[SIZE_DATA];
    char endereco[SIZE_DESCRICAO];
    double salario;
    char sexo;
} Funcionario;

typedef struct tabelaCarteirinha {
    long idCarteirinha;
    int tipo;
    int qtdPasses;
} Carteirinha;

typedef struct tabelaUsuario {
    long idUsuario;
    char cpf[SIZE_CPF];
    char nome[SIZE_NOME];
    char dataNascimento[SIZE_DATA];
    char endereco[SIZE_DESCRICAO];
    char sexo;
    long fkIdCarteirinha;
} Usuario;

typedef struct tabelaAtendimento {
    long idAtendimento;
    long fkIdFuncionario;
    long fkIdUsuario;
    char finalidadeAtendimento[SIZE_DESCRICAO];
    char data[SIZE_DATA];
    char horario[SIZE_HORARIO];
} Atendimento;


// DECLARACOES DE FUNCOES
int retornaPosicaoFuncionario(long idBusca);
void adicionaFuncionario(int posicao);
void listarFuncionarios(int tamanho);
void editarFuncionario();
void removerFuncionario();
void deletaFuncionario(int posicaoFuncionario);
void realizaAtendimento(int posicao);
void listaUsuarios(int tamanho);
Atendimento criaAtendimento();
int posicaoFuncionarioCpf(char cpf[]);
char removerEnterString(char string[]);
int posicaoUsuarioCpf(char cpf[]);
int retornaPosicaoUsuario(int id);
Carteirinha criaCarteirinha();
Usuario criaUsuario();
void listarAtendimentos();
void removerUsuario();
void editarUsuario();
void imprimeCarteirinha(int posicao);


// VARIAVEIS GLOBAIS
Funcionario *funcionarios;
Carteirinha *carteirinhas;
Usuario *usuarios;
Atendimento *atendimentos; 
long iFuncionario = 1000, iUsuarios = 1000, iCarteirinhas = 1000000, iAtendimento = 1;  // controla os ids
int tFuncionarios = 1, tUsuarios = 1;     // controla o tamanho do vetor 


int main() {
    
    int opcaoMenuPrincipal;

    funcionarios = (Funcionario*) malloc(sizeof(Funcionario)); 
    usuarios = (Usuario*) malloc(sizeof(Usuario));
    carteirinhas = (Carteirinha*) malloc(sizeof(Carteirinha));
    atendimentos = (Atendimento*) malloc(sizeof(Atendimento));

    do {
        menuPrincipal();
        setbuf(stdin, NULL);
        scanf("%d", &opcaoMenuPrincipal);
        system("clear");

        switch (opcaoMenuPrincipal) {
            case 1:  // NOVO FUNCIONARIO
                //system("clear");
                adicionaFuncionario(tFuncionarios-1);
                break;

            case 2:  // LISTAR FUNCIONARIO
                //system("clear");    
                if (tFuncionarios == 1) printf("\n NENHUM FUNCIONARIO CADASTRADO \n");
                else listarFuncionarios(tFuncionarios-1);
                break;

            case 3:  // EDITAR FUNCIONARIO
                //system("clear");
                if (tFuncionarios == 1) printf("\n NENHUM FUNCIONARIO CADASTRADO\n");
                else editarFuncionario();
                break;

            case 4:  // REMOVER FUNCIONARIO
                //system("clear");
                if (tFuncionarios == 1) printf("\n NENHUM FUNCIONARIO CADASTRADO\n");
                else removerFuncionario();
                break;

            case 5:  // REALIZAR ATENDIMENTO
                if (tFuncionarios == 1) printf("\n NENHUM FUNCIONARIO CADASTRADO\n");
                else realizaAtendimento(tUsuarios-1);
                break;
            
            case 6:  // LISTAR ATENDIMENTOS
                if (iAtendimento-1 == 0) printf("\n NENHUM ATENDIMENTO CADASTRADO \n");
                else listarAtendimentos();
                break;

            case 7:  // LISTAR USUARIOS
                if (tUsuarios == 1) printf("\nNENHUM USUARIO CADASTRADO\n");
                else listaUsuarios(tUsuarios-1);
                break;

            case 8:  // EDITAR USUARIO
                if (tUsuarios == 1) printf("\nNENHUM USUARIO CADASTRADO\n");
                else editarUsuario();
                break;

            case 9:  // REMOVER USUARIO
                if (tUsuarios == 1) printf("\nNENHUM USUARIO CADASTRADO\n");
                else removerUsuario();
                break;
            
            case 10: // SAIR
                break;

            default:
                printf("\n ERRO: Opção invalida! \n");
                break;
        }

    } while(opcaoMenuPrincipal != 10);

    free(funcionarios);
    free(atendimentos);
    free(usuarios);
    free(carteirinhas);
    
    
    return 0;
}


char removerEnterString(char string[]) {
    int i, tamanho;
    
    tamanho = strlen(string);
    string[tamanho-1] = '\0';
}


int retornaPosicaoFuncionario(long idBusca) {
    int i;

    for (i = 0; i < tFuncionarios; i++) {
        if (funcionarios[i].idFuncionario == idBusca) {
            return i;
        }
    }

    return -1;
}


void deletaFuncionario(int posicaoFuncionario) {
    int i;
    Funcionario *newFuncionarios;

    tFuncionarios--;
    newFuncionarios = (Funcionario*) malloc(sizeof(Funcionario) * tFuncionarios-1);

    for (i = posicaoFuncionario; i < tFuncionarios; i++) {  // Excluindo elemento do vetor Funcionarios
        funcionarios[i] = funcionarios[i+1];
    }

    for (i = 0; i < tFuncionarios-1; i++) {  //
        newFuncionarios[i] = funcionarios[i];
    }

    funcionarios = (Funcionario*) malloc(sizeof(Funcionario) * tFuncionarios-1);
    funcionarios = newFuncionarios;
}


int posicaoFuncionarioCpf(char cpf[]) {
    int i;

    for (i = 0; i < tFuncionarios; i++) {
        if (strcasecmp(funcionarios[i].cpf, cpf) == 0) {
            return i;
        }
    }

    return -1;
}


// Verifica se o funcionario já estiver cadastrado
void adicionaFuncionario(int posicao) {
    //system("clear");
    char cpfFuncionario[SIZE_CPF], nomeFuncionario[SIZE_NOME], 
        dataNascimentoFuncionario[SIZE_DATA], enderecoFuncionario[SIZE_DESCRICAO];
    int j = 0;
    funcionarios = (Funcionario*) realloc(funcionarios, tFuncionarios * sizeof(Funcionario));

    cabecalho("CADASTRO"); 
    do {
        if (j > 0) printf(" ERRO: CPF já cadastrado\n");
        printf(" CPF: ");  
        setbuf(stdin, NULL);
        fgets(cpfFuncionario, SIZE_CPF, stdin);
        j++;
    } while (posicaoFuncionarioCpf(cpfFuncionario) != -1);
    printf(" NOME: ");
    setbuf(stdin, NULL);
    fgets(nomeFuncionario, SIZE_NOME, stdin);
    printf(" DATA NASCIMENTO: ");
    setbuf(stdin, NULL);
    fgets(dataNascimentoFuncionario, SIZE_DATA, stdin);
    printf(" ENDERECO: ");
    setbuf(stdin, NULL);
    fgets(enderecoFuncionario, SIZE_DESCRICAO, stdin);
    printf(" SALARIO: ");
    setbuf(stdin, NULL);
    scanf("%lf", &funcionarios[posicao].salario);
    printf(" SEXO: ");
    setbuf(stdin, NULL);
    scanf("%c", &funcionarios[posicao].sexo);

    removerEnterString(cpfFuncionario);
    removerEnterString(nomeFuncionario);
    removerEnterString(dataNascimentoFuncionario);
    removerEnterString(enderecoFuncionario);
    funcionarios[posicao].idFuncionario = iFuncionario;
    strcpy(funcionarios[posicao].cpf, cpfFuncionario);
    strcpy(funcionarios[posicao].nome, nomeFuncionario);
    strcpy(funcionarios[posicao].dataNascimento, dataNascimentoFuncionario);
    strcpy(funcionarios[posicao].endereco, enderecoFuncionario);

    iFuncionario++;
    tFuncionarios++;

    printf("\n %s foi cadastrado(a) com sucesso!\n\n", funcionarios[posicao].nome);
}


void listarFuncionarios(int tamanho) {
    int i;

    cabecalho("LISTAGEM");
    for (i = 0; i < tamanho; i++) {
        //printf("\n--------------------------------------------\n");
        printf(" ID ======> %li \t\t CPF ===> %s\n", funcionarios[i].idFuncionario, funcionarios[i].cpf);
        printf(" NOME ====> %s\n", funcionarios[i].nome);
        printf(" SALARIO => R$ %.2f\n", funcionarios[i].salario);
        printf("---------------------------------------------------------\n");
    }
    //printf("--------------------------------------------\n");
}


void editarFuncionario() {
    int idBusca, posicaoFuncionario;

    cabecalho("EDITAR");
    printf("Digite o ID do funcionario: ");
    setbuf(stdin, NULL);
    scanf("%d", &idBusca);
    posicaoFuncionario = retornaPosicaoFuncionario(idBusca);
    
    if (posicaoFuncionario == -1) {
        printf("\n Funcionario nao cadastrado\n");
    }
    else {
        adicionaFuncionario(posicaoFuncionario);
        tFuncionarios--;
    }

}


void removerFuncionario() {
    int idBusca, posicaoFuncionario;

    cabecalho("REMOCAO");
    printf("Digite o ID do funcionario: ");
    setbuf(stdin, NULL);
    scanf("%d", &idBusca);
    posicaoFuncionario = retornaPosicaoFuncionario(idBusca);
    
    if (posicaoFuncionario == -1) {
        printf("\n Funcionario nao cadastrado\n");
    }
    else {
        deletaFuncionario(posicaoFuncionario);
    }

}


//-------------------------------------USUARIO/CARTEIRINHA/ATENDIMENTO-----------------------------------//


int posicaoUsuarioCpf(char cpf[]) {
    int i;

    for (i = 0; i < tUsuarios; i++) {
        if (strcasecmp(usuarios[i].cpf, cpf) == 0) {
            return i;
        }
    }

    return -1;
}


int retornaPosicaoUsuario(int id) {
    int i;

    for (i = 0; i < tUsuarios; i++) {
        if (usuarios[i].idUsuario == id) {
            return i;
        }
    }

    return -1;
}


void imprimeCarteirinha(int posicao) {
    printf("\n ID ========> %ld \t\t TIPO ===> %c\n", 
            carteirinhas[posicao].idCarteirinha, carteirinhas[posicao].tipo);
    printf(" QTD PASSES ==> %d \n", carteirinhas[posicao].qtdPasses);
    printf("---------------------------------------------------------\n");
}


void listaUsuarios(int tamanho) {
    int i;

    cabecalho("USUARIOS");
    for (i = 0; i < tamanho; i++) {
        printf(" ID USUARIO =====> %ld \t\t CPF ====> %s\n", usuarios[i].idUsuario, usuarios[i].cpf);
        printf(" NOME ===========> %s", usuarios[i].nome);
        imprimeCarteirinha(i);
    }
    printf("\n");
}


Atendimento criaAtendimento() {
    char data[SIZE_DATA], horario[SIZE_HORARIO], finalidade[SIZE_DESCRICAO];
    long idFuncionario;
    int j = 0;
    Atendimento atendimento;

    cabecalho("ATENDIMENTO");
    do {
        if (j > 0) printf("\nERRO: id inexistente");
        printf("\n ID DO FUNCIONARIO: ");
        setbuf(stdin, NULL);
        scanf("%ld", &idFuncionario);
        j++;
    } while (retornaPosicaoFuncionario(idFuncionario) == -1); 
    printf(" DATA: ");
    setbuf(stdin, NULL);
    fgets(data, SIZE_DATA, stdin);
    printf(" HORARIO: ");
    setbuf(stdin, NULL);
    fgets(horario, SIZE_HORARIO, stdin);
    printf(" FINALIDADE: ");
    setbuf(stdin, NULL);
    fgets(finalidade, SIZE_DESCRICAO, stdin);

    removerEnterString(data);
    removerEnterString(horario);
    removerEnterString(finalidade);
    strcpy(atendimento.data, data);
    strcpy(atendimento.horario, horario);
    strcpy(atendimento.finalidadeAtendimento, finalidade);
    atendimento.fkIdFuncionario = idFuncionario;

    return atendimento;
}


Usuario criaUsuario() {
    Usuario usuario;
    int j = 0;

    cabecalho("USUARIO");
    do {    
        if (j > 0) printf("\n ERRO: CPF existente");
        printf(" CPF: ");
        setbuf(stdin, NULL);
        fgets(usuario.cpf, SIZE_CPF, stdin);    
        removerEnterString(usuario.cpf);
        j++;
    } while (posicaoUsuarioCpf(usuario.cpf) != -1);
    printf(" NOME: ");
    setbuf(stdin, NULL);
    fgets(usuario.nome, SIZE_NOME, stdin);
    removerEnterString(usuario.nome);
    printf(" DATA DE NASCIMETO: ");
    setbuf(stdin, NULL);
    fgets(usuario.dataNascimento, SIZE_DATA, stdin);
    removerEnterString(usuario.dataNascimento);
    printf(" ENDERECO: ");
    setbuf(stdin, NULL);
    fgets(usuario.endereco, SIZE_DESCRICAO, stdin);
    removerEnterString(usuario.endereco);
    printf(" SEXO: ");
    setbuf(stdin, NULL);
    usuario.sexo = getchar();
    setbuf(stdin, NULL);
    usuario.idUsuario = iUsuarios;

    return usuario;
}


Carteirinha criaCarteirinha() {
    Carteirinha carteirinha;
    int qtdPasses, tipo;

    carteirinha.idCarteirinha = iCarteirinhas;
    cabecalho("CARTEIRINHA");
    printf(" CATEGORIA\n");
    printf(" E - ESTUDANTE\n");
    printf(" I - IDOSO\n");
    printf(" D - DEFICIENTE\n");
    printf(" C - COMUM\n");
    printf(" ESCOLHA: ");
    setbuf(stdin, NULL);
    scanf("%d", &tipo);
    carteirinha.tipo = tipo;

    if (tipo == 1 && tipo == 4) {
        printf(" QUANTIDADE DE PASSES: ");
        setbuf(stdin, NULL);
        scanf("%d", &qtdPasses);
    }
    else {
        qtdPasses = 100;
    }
    carteirinha.qtdPasses = qtdPasses;

    return carteirinha;
}


void realizaAtendimento(int posicao) {
    double valorTotal = 0;
    int idFuncionario;
    Atendimento atendimento;
    Usuario usuario;
    Carteirinha carteirinha;

    usuarios = (Usuario*) realloc(usuarios, tUsuarios * sizeof(Usuario));
    carteirinhas = (Carteirinha*) realloc(carteirinhas, tUsuarios * sizeof(Carteirinha));
    atendimentos = (Atendimento*) realloc(atendimentos, iAtendimento+1 * sizeof(Atendimento));
    
    atendimento = criaAtendimento();
    usuario = criaUsuario();
    carteirinha = criaCarteirinha();
    imprimeCarteirinha(tUsuarios);
    usuarios[posicao] = usuario;
    carteirinhas[posicao] = carteirinha;
    atendimento.idAtendimento = iAtendimento;
    atendimento.fkIdUsuario = usuario.idUsuario;
    atendimentos[iAtendimento-1] = atendimento;

    iAtendimento++;
    iUsuarios++;
    tUsuarios++;
    iCarteirinhas++;
}


void listarAtendimentos() {
    int i, posicaoUsuario, posicaoFuncionario;

    cabecalho("ATENDIMENTOS");
    for (i = 0; i < iAtendimento-1; i++) {
        posicaoFuncionario = retornaPosicaoFuncionario(atendimentos[i].fkIdFuncionario);
        posicaoUsuario = retornaPosicaoUsuario(atendimentos[i].fkIdUsuario);
        printf(" ID ==============> %ld\n", atendimentos[i].idAtendimento);
        printf(" FUNCIONARIO =====> %s \n", funcionarios[posicaoFuncionario].nome);
        printf(" USUARIO =========> %s \n", usuarios[posicaoUsuario].nome);
        printf(" DATA/HORARIO =====> %s - %s \n", atendimentos[i].data, atendimentos[i].horario);
        printf("---------------------------------------------------------\n");
    }
}


void editarUsuario() {
    Usuario usuario;
    int id, posicao, j;
    char cpf[SIZE_CPF], nome[SIZE_NOME];

    cabecalho("EDITAR");
    printf(" ID DO USUARIO: ");
    setbuf(stdin, NULL);
    scanf("%d", &id);
    posicao = retornaPosicaoUsuario(id);
    j = 0;

    if (posicao == -1) {
        printf("\n ID NAO ENCONTRADO\n");
    }
    else {
        usuario = criaUsuario();
        usuarios[posicao] = usuario;
    }

}


void deletaUsuario(int posicao) {
    int i;
    Usuario *newUser;
    Carteirinha *novaCarteirinha;

    tUsuarios--;
    newUser = (Usuario*) malloc(sizeof(Usuario) * tUsuarios-1);
    novaCarteirinha = (Carteirinha*) malloc(sizeof(Carteirinha) * tUsuarios-1);

    for (i = posicao; i < tUsuarios; i++) {
        usuarios[i] = usuarios[i+1];
        carteirinhas[i] = carteirinhas[i+1];
    }

    for (i = 0; i < tUsuarios-1; i++) {
        newUser[i] = usuarios[i];
        novaCarteirinha[i] = carteirinhas[i];
    }

    usuarios = (Usuario*) malloc(sizeof(Usuario) * tUsuarios-1);
    carteirinhas = (Carteirinha*) malloc(sizeof(Carteirinha) * tUsuarios-1);
    usuarios = newUser;
    carteirinhas = novaCarteirinha;
}


void removerUsuario() {
    int id, posicao;

    cabecalho("REMOCAO");
    printf("ID DO USUARIO: ");
    setbuf(stdin, NULL);
    scanf("%d", &id);
    posicao = retornaPosicaoUsuario(id);

    if (posicao == -1) {
        printf("\n ID NAO ENCONTRADO\n");
    }
    else {
        deletaUsuario(posicao);
    }

    
}
/*
void deletaFuncionario(int posicaoFuncionario) {
    int i;
    Funcionario *newFuncionarios;

    tFuncionarios--;
    newFuncionarios = (Funcionario*) malloc(sizeof(Funcionario) * tFuncionarios-1);

    for (i = posicaoFuncionario; i < tFuncionarios; i++) {  // Excluindo elemento do vetor Funcionarios
        funcionarios[i] = funcionarios[i+1];
    }

    for (i = 0; i < tFuncionarios-1; i++) {  //
        newFuncionarios[i] = funcionarios[i];
    }

    funcionarios = (Funcionario*) malloc(sizeof(Funcionario) * tFuncionarios-1);
    funcionarios = newFuncionarios;
}
*/