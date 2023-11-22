#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack {
    int topo; // indice controlador
    int *info;
};

typedef struct stack Pilha;

void aloca(Pilha *ptrPilha, int c) {
    ptrPilha->topo = -1;
    ptrPilha->info = (int*) malloc(c*sizeof(int));
}

bool estacheia(Pilha *ptrPilha, int c) {
    if(ptrPilha->topo == c-1) {
        return true;
    } else {
        return false;
    }
}

bool estavazia(Pilha *ptrPilha, int c) {
    if(ptrPilha->topo == -1) {
        return true;
    } else {
        return false;
    }
}

void empilhar(Pilha *ptrPilha, int dado) {
    ptrPilha->topo++;
    ptrPilha->info[ptrPilha->topo] = dado;
}

void desempilha(Pilha *ptrPilha) {
    ptrPilha->topo--;
}
int mostraTopo(Pilha ptrPilha){
    return ptrPilha.info[ptrPilha.topo];
}

void mostraPilhaCompleta(Pilha ptrPilha) {
    while(ptrPilha.topo > -1) {
        printf("%d\t", ptrPilha.info[ptrPilha.topo]);
        ptrPilha.topo--;
    }
}

int main() {
    Pilha p;
    int op, cap, valor, r;

    printf("Digite a capacidade da pilha: ");
    scanf("%d", &cap);

    // Chamar a função alocar espaço na memória
    aloca(&p, cap);

    do {
        printf("--- Sistema de Pilha --- \n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar o topo da pilha\n");
        printf("4 - Mostrar a pilha completa\n");
        printf("0 - Sair\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                if (estacheia(&p, cap) == true) {
                    printf("Pilha esta cheia");
                    getch();
                } else {
                    // Chama função push (empilhar)
                    printf("Digite o valor que deseja empilhar: ");
                    scanf("%d", &valor);
                    empilhar(&p, valor);
                }
                break;
            case 2:
                if (estavazia(&p, cap) == true) {
                    printf("Pilha esta vazia");
                    getch();
                } else {
                    // Chama função pop (desempilhar)
                    r = mostraTopo(p);
                    desempilha(&p);
                    printf("Elemento %d retirado da pilha.\n", r);
                    getch();
                }
                break;
            case 3:
                if (estavazia(&p, cap) == true) {
                    printf("Pilha esta vazia");
                    getch();
                } else {
                    printf("Topo da pilha: %d", mostraTopo(p));
                    getch();
                }
                break;
            case 4:
                mostraPilhaCompleta(p);
                getch();
                break;
            case 0: break;
            default:
                printf("Opcao invalida.\n");
                getch();
                break;
        }
        system("cls");
    } while(op != 0);

    return 0;
}
