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
    scanf("%s", &fila[tot_fila].idade);
    printf("Insira o tipo do atendimento: ");
    scanf("%s", fila[tot_fila].idade);
};



struct Fila{
    char pessoa[100];
    int* pont;
};

