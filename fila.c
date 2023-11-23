#include<stdio.h>
#include<stdlib.h>
struct queue {
    int info;
    int *prox;
};

typedef struct queue *Fila;

Fila alocaEspaco(){
    Fila novo;
    // Aloca espaço na HEAP
    novo = (Fila) malloc(sizeof(struct queue));
    // Retorna a fila
    return novo;
}

void inserirFila(Fila *ptrFila, int valor){
    Fila novo, aux;
    novo = alocaEspaco();
    novo->info = valor;
    novo->prox = NULL;

    if(*ptrFila==NULL) {
        *ptrFila = novo;
    } else {
        aux = *ptrFila;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void mostrarFila(Fila fila) {
    while(fila->prox != NULL) {
        printf("%d -> ", fila->info);
        fila = fila->prox;
    }
    printf("%d -> NULL", fila->info);
}

void removerFila(Fila *ptrFila) {
    Fila aux;
    aux = *ptrFila;
    if(*ptrFila == NULL) {
        printf("Nao tem elementos na fila\n");
    } else {
        printf("O elemento %d foi removido da memoria\n", aux->info);
        *ptrFila = (*ptrFila)->prox;
        free(aux);
        aux = NULL;
    }
}

int main() {
    Fila fila;
    fila = NULL;

    int op, valor;

    do {
        system("cls");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Mostrar a fila\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("\nDigite o valor que deseja colocar na fila: ");
                scanf("%d", &valor);
                // Chamar função de inserção
                inserirFila(&fila, valor);

                printf("\nO elemento %d foi inserido na fila", valor);
                getch();
                break;
            case 2:
                removerFila(&fila);
                getch();
                // Chamar função de remoção
                break;
            case 3:
                mostrarFila(fila);
                getch();
                // Chamar função de mostrar
                break;
            case 0: break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(op != 0);

    return 0;
}
