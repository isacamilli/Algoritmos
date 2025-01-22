#include <stdio.h>
#include <stdlib.h>

struct Lista {
    struct Lista *proximo;
    int nome_paciente;
    int tipo_paciente;
};

struct Lista *inicio = NULL;

void adicionar_paciente(){
    struct Lista *novo_paciente = (struct Lista *)malloc(sizeof(struct Lista));
    int nome_paciente, tipo_paciente;
    printf("Nome do paciente: ");
    scanf("%d", &nome_paciente);

    printf("\n");

    printf("O paciente é preferencial?\n");
    printf("Sim (0) - Não (1)\n");
    scanf("%d", tipo_paciente);

    novo_paciente->tipo_paciente = tipo_paciente;
    novo_paciente->nome_paciente = nome_paciente;
    novo_paciente->proximo = inicio;
    inicio = novo_paciente;
}

int imprimir_menu()
{
    printf("1. Adicionar paciente sem preferência\n");
    printf("2. Adicionar paciente com preferência\n");
    printf("3. Remover elemento\n");
    printf("4. Remover elemento no final\n");
    printf("5. Remover elemento no inicio\n");
    printf("6. Imprimir lista\n");
    printf("7. Tamanho da lista\n");
    printf("8. Sair\n");

    int escolha;
    scanf("%d", &escolha);

    return escolha;
}