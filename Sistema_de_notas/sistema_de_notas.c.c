#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 10
#define MAX_NOME 30
#define NOTAS 4

int cadastrarAlunos(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd);
int nomeValido(char nome[]);
void limparTela();
void pausar();
float calcularMedia(float notas[]);
void mostrarMenu();

void listarTodos(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd);
void listarAprovados(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd);
void listarFinal(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd);
void listarReprovados(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd);

int main(){
    setlocale(LC_ALL,"Portuguese");

    char nomes[MAX_ALUNOS][MAX_NOME];
    float notas[MAX_ALUNOS][NOTAS];

    int qtd = 0;
    int opcao, id;
    int resultado;
    float media;

    do {
        limparTela();
        mostrarMenu();
        scanf("%d", &opcao);
        limparTela();

        switch (opcao)
        {
        case 1:
           qtd = cadastrarAlunos(nomes, notas, qtd);
           pausar();
           break;
        case 2:
            if(qtd == 0){
                printf("\n==== NENHUM ALUNO(A) CADASTRADO ====\n");
                pausar();
            }
            else {
        do {
            printf("\nDigite o ID do aluno(a) (1 a %d): ", qtd);

        resultado = scanf("%d", &id);

            while(getchar() != '\n');

            if(resultado != 1){
            printf("\nDigite um número válido!\n");
         }
            else if(id < 1 || id > qtd){
            printf("Aluno(a) com ID %d não encontrado!\n", id);
         }

    } while(resultado != 1 || id < 1 || id > qtd);

        media = calcularMedia(notas[id - 1]);

            printf("Média: %.2f\n", media);
            pausar();
        }
            break;
        case 3:
            listarTodos(nomes, notas, qtd);
            pausar();
            break;
        case 4:
            listarAprovados(nomes, notas, qtd);
            pausar();
            break;
        case 5:
            listarFinal(nomes, notas, qtd);
            pausar();
            break;
        case 6:
            listarReprovados(nomes, notas, qtd);
            pausar();
            break;
        case 7:
            printf("Saindo do sistema ...\n");
            break;
        default:
            printf("Opção inválida!\n");
            pausar();
            break;
        }

    } while (opcao != 7);

    system("pause");
    return 0;
}   

int cadastrarAlunos(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd){

    int resultado;

    if(qtd >= MAX_ALUNOS){
        printf("Limite de alunos atingindo! \n");
        return qtd;
    }
    else {

    printf("\n====== CADASTRO ====== \n");

    getchar();

    do{

        printf("Nome do aluno: ");
        fgets(nomes[qtd], MAX_NOME, stdin);

        nomes[qtd][strcspn(nomes[qtd], "\n")] = '\0';

        if(!nomeValido(nomes[qtd])){
            printf("Nome inválido! Use apenas letras.\n\n");
        }

    } while(!nomeValido(nomes[qtd]));

    for(int i = 0; i < NOTAS; i++){
        
    do{
       
    printf("Nota %d (0 a 10): ", i + 1);

    resultado = scanf("%f", &notas[qtd][i]);

    while(getchar() != '\n');

    if(resultado != 1){
        printf("\nDigite um número válido!\n");
    }
    else if(notas[qtd][i] < 0 || notas[qtd][i] > 10){
        printf("\nNota deve ser entre 0 e 10!\n");
    }

} while(resultado != 1 || notas[qtd][i] < 0 || notas[qtd][i] > 10);
    }

        printf("ID do aluno(a): %d\n\n", qtd + 1);

        printf("\nAluno(a) cadastrado com sucesso!\n");

    return qtd + 1;
    }
}

int nomeValido(char nome[]) {
    for(int i = 0; nome[i] != '\0'; i++){

        if(nome[i] == '\n'){
            continue;
        }
        if(nome[i] == ' '){
            continue;
        }
        if(!isalpha(nome[i]) ){
            return 0;
        }
    }
    return 1;
}

float calcularMedia(float notas[]){
    float soma = 0;

    for(int i = 0; i < NOTAS; i++){
        soma += notas[i];
    }
    return soma / NOTAS;
}

void mostrarMenu(){
        printf("\n=============== MENU ===============\n");
        printf(" ____________________________________\n");
        printf("|    1 - Cadastrar aluno(a)          |\n");
        printf("|____________________________________|\n");
        printf("|    2 - Calcular Média do aluno(a)  |\n");
        printf("|____________________________________|\n");
        printf("|    3 - Listar alunos e Médias      |\n");
        printf("|____________________________________|\n");
        printf("|    4 - Listar alunos aprovados     |\n");
        printf("|____________________________________|\n");
        printf("|    5 - Listar alunos em final      |\n");
        printf("|____________________________________|\n");
        printf("|    6 - Listar alunos reprovados    |\n");
        printf("|____________________________________|\n");
        printf("|    7 - Sair                        |\n");
        printf("|____________________________________|\n");
        printf("\nEscolha ---->  ");
}

void listarTodos(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd){
    float media;

    if(qtd == 0){
        printf("\n==== NENHUM ALUNO(A) CADASTRADO ====\n");
    }
    else {
        printf("\n ==== ALUNOS(A) ====\n");

    for(int i = 0; i < qtd; i++){
        media = calcularMedia(notas[i]);
            printf("%s | Média: %.2f\n", nomes[i], media);
    }
}
}
void listarAprovados(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd){
    float media;
    int encontrou = 0;

    if(qtd == 0){
        printf("\n==== NENHUM(A) ALUNO(A) CADASTRADO ====\n");
    }
    else {
        printf("\n====== ALUNOS(A) APROVADOS ======\n");

    for(int i = 0; i < qtd; i++){
        media = calcularMedia(notas[i]);

        if(media >= 7){
            printf("%s\n", nomes[i]);
            encontrou = 1;
        }
    }
        if(!encontrou){
            printf("\n NENHUM(A) ALUNO(A) APROVADO!\n");
        }
    }
}

void listarFinal(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd){
    float media;
    int encontrou = 0;

    if(qtd == 0){
        printf("\n==== NENHUM(A) ALUNO(A) CADASTRADO ====\n");
    }
    else {
        printf("\n====== ALUNOS EM FINAL ======\n");

    for(int i = 0; i < qtd; i++){
        media = calcularMedia(notas[i]);

        if(media >= 5 && media < 7){
            printf("%s\n", nomes[i]);
            encontrou = 1;
        }
    }
        if(!encontrou){
            printf("\nNENHUM(A) ALUNO(A) DE FINAL!\n");
     }
}
}

void listarReprovados(char nomes[][MAX_NOME], float notas[][NOTAS], int qtd){
    float media;
    int encontrou = 0;

    if(qtd == 0){
        printf("\n==== NENHUM(A) ALUNO(A) CADASTRADO ====\n");
    }
    else {
        printf("\n====== ALUNOS REPROVADOS ======\n");

    for(int i = 0; i < qtd; i++){
        media = calcularMedia(notas[i]);

        if(media < 5){
            printf("%s\n", nomes[i]);
            encontrou = 1;
        }
    }
        if(!encontrou){
            printf("\nNENHUM(A) ALUNO(A) DE REPROVADOS!\n");
        }
    }
}

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar(){
    while(getchar() != '\n');
    printf("\nPressione ENTER para continuar ...");
    getchar();
}
