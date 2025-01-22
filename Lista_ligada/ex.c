#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node* proximo;
};

struct Node* inicio = NULL;

void adicionar_elemento(int valor){
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node)); // cria-se um novo Node
    novo->valor = valor; // o valor do novo Node é o valor dado no parametro da funcão
    novo->proximo = inicio; // o proximo do novo é o Node inicio
    inicio = novo; // o inicio agora é o novo

    // antes -> [1] --> agora -> [2,1]
    // complexidade O(1)
    // a ordem dos elementos na lista é inversa à ordem de inserção (FILO / Pilha)
}

void adicionar_final(int valor){
    struct Node *novo = (struct Node*)malloc(sizeof(struct Node)); // cria-se um novo Node
    novo->valor = valor; // disse qual o valor do Node
    novo->proximo = NULL; // já disse que o próximo valor do Node é NULL (agora tem que colocar ele na lista)

    if (inicio == NULL){ // o inicio da lista é NULL? a lista está vazia?
        inicio = novo; // se a lista está vazia é só inseir o Node na lista

        // antes -> [] --> agora -> [1]
        // complexidade O(1)
    } else {
        struct Node *atual = inicio; // cria-se um novo Node que recebe o inicio da lista
        while (atual->proximo != NULL){ // o proximo não é NULL?
            atual = atual->proximo; // se sim, atual recebe o proximo de atual
        }
        atual->proximo = novo; // se nao, o proximo do atual é o novo

        // antes -> [1] --> agora -> [1,2]
        // complexidade O(n)
    }
}

void remover_inicio(){
    struct Node *temp = inicio;
    inicio = inicio->proximo;
    free(temp);
}
void remover_elemento(int valor){
    struct Node *atual = inicio; // cria-se um novo Node que recebe o inicio da lista
    struct Node *anterior = NULL; // cria-se um novo Node que recebe NULL (estou no inicio da lista, entao o anterior é NULL) para nao precisar ficar chegando o proximo do proximo
    while (atual != NULL){
        if (atual->valor == valor){ // se achar o valor
            if (anterior == NULL){ // se anterior for igual a NULL significa que estamos no primeiro elemento
                remover_inicio(); // remover primeiro elemento
                // complexidade O(1)
            } else{ // se nao for NULL
                anterior->proximo = atual->proximo; // o proximo do anterior é o proximo do atual
                free(atual);
                // antes -> [4,1,7] (procura o 1) --> agora -> [4,7]
                // complexidade O(n)
            }
            return;
        }
        anterior = atual; // passa para o proximo elemento
        atual = atual->proximo; // passa para o proximo elemento
    }
}

void remover_final(){
    struct Node *atual = inicio;
    struct Node *anterior = NULL;
    while (atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo; // vai andando até o final da lista
    } if (anterior == NULL){ // se o anterior é NULL estamos no inicio da lista
        inicio = NULL; // inicio é removido
    } else { // se nao
        anterior->proximo = NULL; // aponta para o proximo do atual, que é NULL
    }
    free(atual); // remove o atual

    // complexidade O(n)
}


int busca (int valor){
    struct Node* temp = inicio;
    while (temp != NULL){
        if (temp->valor == valor){
            return 1;
        }
        temp = temp->proximo;
    }
}

void imprimir_lista (){
    struct Node* temp = inicio;
    printf("INICIO --> ");
    while (temp != NULL){
        printf("%d --> ", temp->valor);
        temp = temp->proximo;
    }
    printf(" NULL\n");
}

int tamanho_da_lista (){
    int tam = 0;
    struct Node* temp = inicio;
    while (temp != NULL){
        tam++;
        temp = temp->proximo;
    }
    return tam;
}

int vazia (){
    return inicio == NULL;
}

void imprimir_menu(){
    printf("1. Adicionar elemento\n");
    printf("2. Adicionar elemento no final\n");
    printf("3. Remover elemento\n");
    printf("4. Remover elemento no final\n");
    printf("5. Remover elemento no inicio\n");
    printf("6. Imprimir lista\n");
    printf("7. Tamanho da lista\n");
    printf("8. Sair\n");
}

int main (){
    //criar_lista()
    int opcao;
    int valor;
    while(1){
        imprimir_menu();
        printf("Digite a opção: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                adicionar_elemento(valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                adicionar_final(valor);
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                remover_elemento(valor);
                break;
            case 4:
                remover_final();
                break;
            case 5:
                remover_inicio();
                break;
            case 6:
                imprimir_lista();
                break;
            case 7:
                printf("Tamanho da lista: %d\n", tamanho_da_lista());
                break;
            case 8:
                return 0;
            default:
                printf("Opção invalida\n");
        }
    }
    return 0;
}