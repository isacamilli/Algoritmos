#include <stdio.h>

struct Contato{
    char nome[50];
    char numero[15];
};

struct Contato* criar_contato(char nome[], char numero[]) {
    struct Contato* contato = (struct Contato*)
    malloc(sizeof(struct Contato));

    strcpy(contato-> nome, nome);
    strcpy(contato-> numero, numero);
    
    return contato;
};


int main() {
    char numero, nome;

    printf("Informe o nome do contato que deseja adicionar: ");
    scanf("%s", nome);

    printf("Informe o número do contato que deseja adicionar: ");
    scanf("%s", numero);

    struct Contato* contato1 = criar_contato(nome,numero);


    return 0;
}