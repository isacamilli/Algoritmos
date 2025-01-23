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
        if (strcmp(atual->nome_paciente, nome_paciente) == 0){ 
            if (anterior == NULL){ 
                struct Lista *temp = inicio;
                inicio = inicio->proximo;
                free(temp); 

            } else{ 
                anterior->proximo = atual->proximo;
                free(atual);
            }
            paciente_encontrado = 1;
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return paciente_encontrado;
    
}

int atender_paciente(int preferenciais_atendidos){

    struct Lista *atual = inicio;
    struct Lista *anterior = NULL;
    int atendimento = 0;
    char paciente_atender[50] = " ";

    if (atual != NULL){
        if (preferenciais_atendidos < 2 ){
            while (atual != NULL){
                if (atual->tipo_paciente == 0){
                    strcpy(paciente_atender,atual->nome_paciente);
                    atual = atual->proximo;
                }
                else{
                    atual = atual->proximo;
                }
            }

            if(paciente_atender!= " "){
                printf("Paciente preferencial %s está sendo atendido.\n", paciente_atender);
                remover_paciente(paciente_atender);
                preferenciais_atendidos++;
            }
            else{
                struct Lista *atual = inicio;
                while(atual != NULL){
                    
                    strcpy(paciente_atender,atual->nome_paciente);
                    atual = atual->proximo;
                }

                printf("Paciente normal %s está sendo atendido.\n", paciente_atender);
                remover_paciente(paciente_atender);
            }
        }
        else{
            while(atual != NULL){
                    
                    strcpy(paciente_atender,atual->nome_paciente);
                    atual = atual->proximo;
                }

                printf("Paciente normal %s está sendo atendido.\n", paciente_atender);
                remover_paciente(paciente_atender);
            preferenciais_atendidos = 0;
        }
    }
    else{
        printf("Não há pacientes para atendimento\n");
    }    
    return preferenciais_atendidos;
}

void imprimir_lista(){
    struct Lista *atual = inicio;
    char tipo[50];
    int quant_normais = 0;
    int quant_preferenciais = 0;
    int quant_total = 0;

    if (atual != NULL){
        while (atual != NULL){
            if (atual->tipo_paciente == 0){
                strcpy(tipo, "preferencial"); 

                quant_preferenciais++;
                quant_total++;

            }
            else{
                strcpy(tipo, "normal");

                quant_normais++;
                quant_total++;
            }
            printf("Paciente %s - %s\n", atual->nome_paciente, tipo);
            atual = atual->proximo;
        }
        printf("\n");
        printf("Quantidade pacientes normais: %d\n", quant_normais);
        printf("Quantidade pacientes preferenciais: %d\n", quant_preferenciais);
        printf("Quantidade de pacientes no total: %d\n", quant_total);
    }
    else{
        printf("Lista de pacientes vazia\n");
    }
}


int imprimir_menu()
{
    printf("1. Adicionar paciente sem preferência\n");
    printf("2. Adicionar paciente com preferência\n");
    printf("3. Atender paciente\n");
    printf("4. Remover paciente\n");
    printf("5. Imprimir lista de pacientes\n");
    printf("0. Sair\n");

    printf("\n");

    int escolha;
    scanf("%d", &escolha);

    return escolha;
}



int main(){

    int escolha = 1;
    int num_pacientes = 0;
    char nome_paciente[50];
    int preferenciais_atendidos = 0;
    char nome_remover[50];

    while (escolha != 0){
        escolha = imprimir_menu();

        printf("\n");

        switch (escolha)
        {
        case 1:

            if (num_pacientes < 16){
                printf("Nome do paciente: ");
                scanf("%s", nome_paciente);
                adicionar_paciente(1, nome_paciente);
                num_pacientes++;
            }
            else{
                printf("Quantidade de pessoas por medico excedida\n");
                printf("Há outro medico disponivel para atendimento?\n");
                printf("1 - Sim, 0 - Não\n");
                scanf("%d", &escolha);

                if(escolha == 1){
                    printf("Novo medico está atendendo\n");
                    num_pacientes = 0;
                }
                else{
                    printf("Atendimentos encerrados\n");
                }
            }

            printf("\n");
            
            break;

        case 2:

            if (num_pacientes < 16){
                printf("Nome do paciente: ");
                scanf("%s", nome_paciente);
                adicionar_paciente(0, nome_paciente);
                num_pacientes++;
            }
            else{
                printf("Quantidade de pessoas por medico excedida\n");
                printf("Há outro medico disponivel para atendimento?\n");
                printf("1 - Sim, 0 - Não\n");
                scanf("%d", &escolha);

                if(escolha == 1){
                    printf("Novo medico está atendendo\n");
                    num_pacientes = 0;
                }
                else{
                    printf("Atendimentos encerrados\n");
                }
            }

            printf("\n");
            
            break;

        case 3:

            preferenciais_atendidos = atender_paciente(preferenciais_atendidos);

            printf("\n");

            break;
        
        case 4:


            printf("Nome do paciente que deseja remover: ");
            scanf("%s", nome_remover);

            int paciente_encontrado = remover_paciente(nome_remover);

            if (paciente_encontrado == 1){
                printf("Paciente removido com sucesso\n");
                printf("\n");
            }
            else{
                printf("Paciente não encontrado no sistema\n");
                printf("\n");
            }

            break;

        case 5:
            imprimir_lista();
            printf("\n");

            break;

        default:

            printf("Opção não disponivel\n");
            printf("\n");
            break;
        }

    }
    
}