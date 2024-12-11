#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    int id;
    char nome[100];
    int idade;
    char atendimento[100];
    int pref;
};

struct Paciente* criar_paciente(struct Paciente pessoa, int tot_fila){
    pessoa.id = tot_fila + 1;
    printf("Insira o nome do paciente: ");
    scanf("%s", pessoa.nome);
    printf("Insira a idade do paciente: ");
    scanf("%d", &pessoa.idade);
    printf("Insira o tipo do atendimento: ");
    scanf("%s", pessoa.idade);
    printf("O paciente é preferencial? 1 - Sim, 0 - Não");
    scanf("%d", &pessoa.pref);
};



struct Fila{
    struct Paciente fila[100];
    int* pont;
};

struct Fila* add_pref(struct Paciente )