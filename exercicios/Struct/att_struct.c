#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    int id;
    char nome[100];
    int idade;
    char atendimento[100];
    int pref;
};

struct Paciente* criar_paciente(struct Paciente fila[], int tot_fila){
    fila[tot_fila].id = tot_fila + 1;
    printf("Insira o nome do paciente: ");
    scanf("%s", fila[tot_fila].nome);
    printf("Insira a idade do paciente: ");
    scanf("%d", &fila[tot_fila].idade);
    printf("Insira o tipo do atendimento: ");
    scanf("%s", fila[tot_fila].idade);
    printf("O paciente é preferencial? 1 - Sim, 0 - Não");
    scanf("%d", &fila[tot_fila].pref);
    // if(fila[tot_fila].pref == 1){
    //     printf("Qual é o tipo de preferência: 1 - Idoso, ");
    //     printf("2 - Gestante/Lactante, ");
    //     printf("3 - Deficiência");
    //     scanf("%d", &fila[tot_fila].pref);
    //     switch (fila[tot_fila].pref)
    //     {
    //     case 1:
    //         if(fila[0].pref != 1){
    //             fila[0].id = 2;
    //             fila[tot_fila].id = 1;
    //             for(int i = 2;i < tot_fila; i++){
    //                 fila[i].id = fila[i].id + 1;
    //             }
    //         }
    //         else{
    //             for(int i = 1;i < tot_fila;i++){
    //                 if(fila[i-1].pref - fila[1].pref != 1){
    //                     fila[tot_fila]
        //             }
        //         }
        //     }

        //     break;
        
        // default:
        //     break;
        // }
    }
};



struct Fila{
    struct Paciente pessoa[100];
    int* pont;
};

