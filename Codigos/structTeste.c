#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contato{
    char nome[50];
    char numero[15];
};

struct Contato* criar_contato(char nome[], char numero[]) {
    struct Contato* contato = (struct Contato*)
    // malloc(sizeof(struct Contato));

    strcpy(contato-> nome, nome);
    strcpy(contato-> numero, numero);
    
    return contato;
};

void mostrar_contatos(struct Contato *lista){
    if(lista == NULL){
        printf("Nenhum contato cadastrado");
    }
    else{
        while (lista != NULL){
            printf("Nome: %s; Número: %s\n", lista->nome, lista->numero);
        }
        
    }
}

int main() {
    char numero[15], nome[100];
    int escolha = 100;


    while (escolha != 0){

        printf("Qual opção deseja escolher:\n");
        printf("1 - Adicionar contato; 2 - Atualizar contato; 3 - Mostrar contatos; 0 - Sair\n");
        scanf("%d", &escolha);

        if (escolha == 1){ 
            printf("Informe o nome do contato que deseja adicionar: ");
            scanf("%s", nome);

            printf("Informe o número do contato que deseja adicionar: ");
            scanf("%s", numero);

            struct Contato* contato1 = criar_contato(nome,numero);

            // printf("%")

        }
    }

    return 0;
}