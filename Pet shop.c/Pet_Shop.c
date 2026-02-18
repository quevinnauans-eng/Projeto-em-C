#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define clear "cls"
#define MAX 10
#define TAM 20

void cadastrarAnimal(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]);
void registrarAdocao(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]);
void pesquisarAnimal(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]);
void imprimirAdocao(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]);
void imprimirDisponiveis(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]);
void limparBuffer();
/*
    Função main exibe 6 escolhas para o usuario que vai de 1 atÃ© 6
    Armazena a escolha na variavel escolha
    Depois entramos em um switch case que depende do valor da escolha
    Valores de 1 a 5 chamam uma Função diferente
    Valor 6 fecha o programa
    Qualquer outro valor o programa avisa que é um valor invalido e volta ao começo
*/
int main(){
    setlocale(LC_ALL,"Portuguese");

    int escolha = 0, escolhaErrada = 0, idAnimal[MAX], idadeAnimal[MAX], statusAdocao[MAX], quantidadeAnimal = 0;
    char especieAnimal[MAX][TAM], corAnimal[MAX][TAM];
    while(escolha != 6){
        system(clear);
        printf("   _____     _      _____ _                 \n");
        printf("  |  __ \\   | |    / ____| |                \n");
        printf("  | |__) |__| |_  | (___ | |__   ___  _ __  \n");
        printf("  |  ___/ _ \\ __|  \\___ \\| '_ \\ / _ \\| '_ \\ \n");
        printf("  | |  |  __/ |_   ____) | | | | (_) | |_) |\n");
        printf("  |_|   \\___|\\__| |_____/|_| |_|\\___/| .__/ \n");
        printf("                                   | |    \n");
        printf("                                   |_|    \n\n");
        printf("  1. Cadastrar Animal\n");
        printf("  2. Registrar adoção\n");
        printf("  3. Pesquisar animal\n");
        printf("  4. Imprimir relatório de adoções\n");
        printf("  5. Imprimir relatório de animais disponíveis\n");
        printf("  6. Sair\n\n");
        (escolhaErrada == 1) ? (printf("  Valor invalido\n\n"), escolhaErrada = 0) : 0;
        printf("  Escolha uma opção:  ");
        scanf("%d", &escolha);
        limparBuffer();
        
        switch(escolha){
            case 1:
                cadastrarAnimal(especieAnimal, &quantidadeAnimal, corAnimal, idadeAnimal, idAnimal, statusAdocao);
                break;
            case 2:
                registrarAdocao(especieAnimal, &quantidadeAnimal, corAnimal, idadeAnimal, idAnimal, statusAdocao);
                break;
            case 3:
                pesquisarAnimal( especieAnimal,  &quantidadeAnimal,  corAnimal,  idadeAnimal,  idAnimal,  statusAdocao);
                break;
            case 4:
                imprimirAdocao(especieAnimal, &quantidadeAnimal, corAnimal, idadeAnimal, idAnimal, statusAdocao);
                break;
            case 5:
                imprimirDisponiveis(especieAnimal, &quantidadeAnimal, corAnimal, idadeAnimal, idAnimal, statusAdocao);
                break;
            case 6:
                break;
            default:
                escolhaErrada = 1;
        }
    }
    system(clear);
}

void cadastrarAnimal(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]){
    system(clear);
    if(*quantidadeAnimal == MAX){
            printf("\nLimite de animais atingido!\n");
		while(getchar() != '\n');
    	printf("\nPressione ENTER para continuar ...");
    	getchar();
            return;
        }
            printf("\n===== CADASTRAR ANIMAL =====\n");

        printf("\nInforme a Espécie: ");
        fgets(especieAnimal[*quantidadeAnimal], TAM, stdin);
        especieAnimal[*quantidadeAnimal][strcspn(especieAnimal[*quantidadeAnimal], "\n")] = '\0';

        printf("Informe a Cor: ");
        fgets(corAnimal[*quantidadeAnimal], TAM, stdin);
        corAnimal[*quantidadeAnimal][strcspn(corAnimal[*quantidadeAnimal], "\n")] = '\0';

        printf("Informe a Idade: ");
        scanf("%d", &idadeAnimal[*quantidadeAnimal]);
        limparBuffer();

        idAnimal[*quantidadeAnimal] = *quantidadeAnimal + 1;

        printf("Animal com código: %d\n", *quantidadeAnimal + 1);

        statusAdocao[*quantidadeAnimal] = 0;
        (*quantidadeAnimal)++;

        printf("\nAnimal cadastrado com sucesso! \n");
        printf("Pressione ENTER para continuar...");
        getchar();

}

void registrarAdocao(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]){
	system(clear);
	int codigo_busca;
	int encontrado = 0;
	if(*quantidadeAnimal == 0){
		printf("\n===== NÃO HÁ ANIMAIS DISPONÍVEIS PARA ADOÇÃO =====\n");
	}else{
		printf("\n===== REGISTRAR ADOÇÃO =====\n");
		printf("Digite o código do animal para adoção: ");
		scanf(" %d", &codigo_busca);
        limparBuffer();
        
		for(int i = 0; i < *quantidadeAnimal; i++){
		       if(idAnimal[i] == codigo_busca){
		       	if(statusAdocao[i] == 1){
		       		printf("\nAnimal não disponi­vel para adoção!\n\n");
					encontrado = 1;	
				}else{
		            printf("\nAnimal Registrado com Sucesso!\n\n");
		            //printf("código: %d\n", idAnimal[i]);
		            //printf("Espécie: %s\n", especieAnimal[i]);
			        //printf("Idade: %d\n", idadeAnimal[i]);
			        //printf("Cor: %s\n", corAnimal[i]);
			        statusAdocao[i] = 1;
			            
			
		            encontrado = 1;
		            break;
				}			
	           }
	       }
	       if(encontrado == 0){
	           printf("\nAnimal com código %d não encontrado.\n", codigo_busca);
	    }
	}
	//system("pause");
    printf("Pressione ENTER para continuar...");
    getchar();
    system(clear);
}

void pesquisarAnimal(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]){
    system(clear);
    int codigo_busca;
    int encontrado = 0;

    if(*quantidadeAnimal == 0){
        printf("\n===== NENHUM ANIMAL CADASTRADO =====\n");
    } else {

    printf("\n==== PESQUISAR ANIMAL ====\n");
    printf("Informe o código do animal: ");
    scanf("%d", &codigo_busca);
    limparBuffer();

        for(int i = 0; i < *quantidadeAnimal; i++){
            if(idAnimal[i] == codigo_busca){

            printf("\nAnimal encontrado!\n\n");
            printf("Código: %d\n", idAnimal[i]);
            printf("Espécie: %s\n", especieAnimal[i]);
            printf("Idade: %d\n", idadeAnimal[i]);
            printf("Cor: %s\n", corAnimal[i]);
            printf("Status: %s\n", statusAdocao[i] == 0 ? "Disponi­vel" : "Adotado");
            

            encontrado = 1;
            break;
            }
        }
        if(encontrado == 0){
            printf("\nAnimal com código %d não encontrado.\n", codigo_busca);
        }
    }
    printf("\n\nAPERTE ENTER PARA CONTINUAR...\n");
    getchar();
}

void imprimirAdocao(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]){
	system(clear);

    int i,aniadot=0;
    for(i=0;i<*quantidadeAnimal;i++){
    	if(statusAdocao[i]==1){
    		aniadot++;
		}
	}
	if(aniadot==0){
		printf("\n===== NENHUM ANIMAL FOI ADOTADO AINDA =====\n");	
	}else{
	printf("\n===== ANIMAIS ADOTADOS =====\n");
    printf("+--------+-------------+-------+------------+\n");
    printf("| %-6s | %-11s  | %-5s | %-10s |\n", "Código", "Espécie", "Idade", "Cor");
    printf("+--------+-------------+-------+------------+\n");
		for(i=0;i<*quantidadeAnimal;i++){
			if(statusAdocao[i]==1){

                printf("| %-6.4d | %-11.11s | %-5.2d | %-10.10s |\n", idAnimal[i], especieAnimal[i], idadeAnimal[i], corAnimal[i]);

				/*printf("Especie: ");
				puts(especieAnimal[i]);	
				printf("Idade: %d\n",idadeAnimal[i]);
				printf("cor: ");
				puts(corAnimal[i]);	
				printf("Codigo: %d\n",idAnimal[i]);		
				printf("\n");	*/
			}
		}
	}
    printf("+--------+-------------+-------+------------+\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
    system(clear);
}

void imprimirDisponiveis(char especieAnimal[][TAM], int *quantidadeAnimal, char corAnimal[][TAM], int idadeAnimal[], int idAnimal[], int statusAdocao[]){
	system(clear);
    int i,anidisp=0;
    for(i=0;i<*quantidadeAnimal;i++){
    	if(statusAdocao[i]==0){
    		anidisp++;
		}
	}
	if(anidisp==0){
		printf("\n===== NÃO TEMOS ANIMAIS DISPONIVEIS PARA ADOÇÃO =====\n");	
	}else{
		printf("\n===== ANIMAIS DISPONIVEIS =====\n");
        printf("+--------+-------------+-------+------------+\n");
        printf("| %-6s | %-11s  | %-5s | %-10s |\n", "Código", "Espécie", "Idade", "Cor");
        printf("+--------+-------------+-------+------------+\n");
		for(i=0;i<*quantidadeAnimal;i++){
			if(statusAdocao[i]==0){

                printf("| %-6.4d | %-11.11s | %-5.2d | %-10.10s |\n", idAnimal[i], especieAnimal[i], idadeAnimal[i], corAnimal[i]);

				/*printf("Especie: ");
				puts(especieAnimal[i]);	
				printf("Idade: %d\n",idadeAnimal[i]);
				printf("cor: ");
				puts(corAnimal[i]);	
				printf("Codigo: %d\n",idAnimal[i]);		
				printf("\n");	*/
			}
		}
	}
    printf("+--------+-------------+-------+------------+\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
    system(clear);
}


void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
