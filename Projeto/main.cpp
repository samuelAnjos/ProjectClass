#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

using namespace std;

typedef struct aluno{ // struck para aluno
    int matricula;
    int idade;
    char nomeAluno[30];
    struct aluno *prox;
    struct aluno *ant;
}tipoAluno;

typedef struct classe{ // struck para classe
    int serie;
    char turma;
    int qtdade;
    char etapa[20];
    char nomeProf[30];
    tipoAluno *apontaAluno;
    struct classe *prox;
}tipoClasse;

typedef struct listaGerenciar{
    tipoClasse *inicio;
    tipoClasse *fim;
    int qtdade;
}tipoGerenciar;

void lista_inicializar(tipoGerenciar *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtdade = 0;
}

// classe feita com lista simplemente encadeada
int lista_inserir_vazia_classe(tipoGerenciar *lista, char nomeProf[30],char turma, int serie, char etapa[20]){
    tipoClasse *novaClasse;
    novaClasse = (tipoClasse *) malloc(sizeof(tipoClasse));

    if(novaClasse == NULL){
        return 0;
    }else{
        novaClasse->serie = serie;
        novaClasse->qtdade = 0;
        novaClasse->turma = turma; // ver se o caractere vai
        strcpy(novaClasse->etapa, etapa);
        strcpy(novaClasse->nomeProf, nomeProf);
        novaClasse->apontaAluno = NULL;
        novaClasse->prox = NULL;
        lista->inicio = novaClasse;
        lista->fim = novaClasse;
        lista->qtdade++;
        return 1;
    }
}

int lista_inserir_Fim_classe(tipoGerenciar *lista, char nomeProf[30],char turma, int serie, char etapa[20]){
    tipoClasse *novaClasse;

    if(lista->inicio == NULL){
        lista_inserir_vazia_classe(lista, nomeProf, turma,  serie, etapa);
    }else{
        novaClasse = (tipoClasse *) malloc(sizeof(tipoClasse));
        if(novaClasse == NULL)
            return 0;
        novaClasse->serie = serie;
        novaClasse->qtdade = 0;
        novaClasse->turma = turma; // ver se o caractere vai
        strcpy(novaClasse->etapa, etapa);
        strcpy(novaClasse->nomeProf, nomeProf);
        novaClasse->apontaAluno = NULL; //
        novaClasse->prox = NULL;
        lista->fim->prox = novaClasse;
        lista->fim = novaClasse;
        lista->qtdade++;
        return 1;
    }
}

void lista_system_limpar(){
    system("pause");
    system("cls");
}

void lista_mostrar(tipoGerenciar *lista){
    tipoClasse *atual;
    atual = lista->inicio;
    printf("\n--As Classe(s) Cadastradas--\n");
    while(atual != NULL){
        printf("Nome do Professor: %s ", atual->nomeProf);
        printf("Turma: %c ", atual->turma);
        printf("Séria: %d ", atual->serie);
        printf("Etapa: %s ", atual->etapa);
        atual = atual->prox;
        printf("\n");
    }
    printf("\n");
}

int main(){

    setlocale(LC_ALL, "portuguese");

    tipoGerenciar lista;
    int op, serie, aux;
    char nome[30], etapa[20], turma;
    lista_inicializar(&lista);

    do{
       printf("|1| Inserir na lista vazia\n");
       printf("|2| Inserir no fim da lista\n");
       printf("|8| Exibir lista de classe(s)\n");
       cout <<"|0| Sair do programa " << endl;
       printf(" Escolha uma opção: ");
       scanf("%d", &op);

       switch(op){
           case 1:
               printf("Digite o nome(a) do professor: ");
               scanf("%s", &nome); // pode trocar pelo gets testar
               printf("Informe a turma (ex: A, B, C...): ");
               scanf("%s", &turma);
               printf("Informe a série: ");
               scanf("%d", &serie);
               printf("Digite a etapa (ex: Fundamental I, Fundamental II e Médio): ");
               scanf("%s", &etapa);
               if(lista_inserir_vazia_classe(&lista, nome, turma, serie, etapa)){
                   printf("Operação realizada com sucesso.\n");
               }else{
                   printf("Operação não realizada!!!\n");
               }
               lista_system_limpar();
           break;

           case 2:
               printf("Digite o nome(a) do professor: ");
               scanf("%s", &nome); // pode trocar pelo gets testar
               printf("Informe a turma (ex: A, B, C...): ");
               scanf("%s", &turma);
               printf("Informe a série: ");
               scanf("%d", &serie);
               printf("Digite a etapa (ex: Fundamental I, Fundamental II e Médio): ");
               scanf("%s", &etapa);
               if(lista_inserir_Fim_classe(&lista, nome, turma, serie, etapa)){
                   printf("Operação realizada com sucesso.\n");
               }else{
                   printf("Operação não realizada!!!\n");
               }
               lista_system_limpar();
           break;

           case 8:
               lista_mostrar(&lista);
           break;

           case 0:
               cout << " Encerrando programa! " << endl;
               //depois por uma destruir
            break;
           default:
               printf("Opção inválida!!!\n");
               lista_system_limpar();
       }
    }while(op != 0);

    //return 0;
}
