#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    struct Lista *proximo;
    char nome_paciente[50];
    int tipo_paciente;
};

struct Lista *inicio = NULL;

void adicionar_paciente(int tipo_paciente, char* nome_paciente){
    struct Lista *novo_paciente = (struct Lista *)malloc(sizeof(struct Lista));
    
        novo_paciente->tipo_paciente = tipo_paciente;
        strcpy(novo_paciente->nome_paciente, nome_paciente);
        novo_paciente->proximo = inicio;
        inicio = novo_paciente;
    
}

int remover_paciente(char* nome_paciente){
    struct Lista *atual = inicio;
    struct Lista *anterior = NULL;
    int paciente_encontrado = 0;

    while (atual != NULL) {
        if (atual->nome_paciente == nome_paciente){ // se achar o valor
            if (anterior == NULL){ 
                struct Lista *temp = inicio;
                inicio = inicio->proximo;
                free(temp); 

            } else{ // se nao for NULL
                anterior->proximo = atual->proximo; // o proximo do anterior é o proximo do atual
                free(atual);
        }
        printf("Paciente");
    }

    else{
        paciente_encontrado = 1;
    }

    return paciente_encontrado;
    
}

}

int atender_paciente(int preferenciais_atendidos){

    struct Lista *atual = inicio;
    struct Lista *anterior = NULL;
    int atendimento = 0;

    if (preferenciais_atendidos < 2){
        while (atual != NULL){
            if (atual->tipo_paciente == 0){
                printf("Paciente %s está sendo atendido.\n", atual->nome_paciente);
                remover_paciente(atual->nome_paciente);
                atendimento++;
                break;
            }
        }
        if (atendimento != 0){
            preferenciais_atendidos++;
        }
        else{
            
        }
    }
    return preferenciais_atendidos;
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



// int main(){

//     int nome_paciente, tipo_paciente;
//     int preferenciais_atendidos = 0
//     printf("Nome do paciente: ");
//     scanf("%d", &nome_paciente);

//     printf("\n");

//     printf("O paciente é preferencial?\n");
//     printf("Sim (0) - Não (1)\n");
//     scanf("%d", tipo_paciente);

//     printf("\n");
// }