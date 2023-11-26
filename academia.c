#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct User {
    char name[50];
    int password;
    char situation;
} User;

void clearBuffer() {
    while((getchar() != '\n') && !EOF);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    User client[100];
    int password[100], countClient = 0, countPassword = 0, i;

    do {
        scanf("%[^\n]", &client[countClient].name);
        
        if((strcmp(client[countClient].name, "SAIR") == 0)) break;

        scanf("%d", &client[countClient].password);
        scanf(" %c", &client[countClient].situation);
        countClient++;
        clearBuffer();
    } while(countClient < 100);

    do {
        scanf("%d", &password[countPassword]);

        if(password[countPassword] == -1)
            break;
        else
            countPassword++;
    } while(countPassword < 100);

    for(i=0; i<countPassword; i++) {
        if ((client[i].password == password[i]) && (client[i].situation == 'P')) {
            printf("%s, seja bem-vindo(a)!\n", client[i].name);
        }

        if((client[i].password == password[i]) && (client[i].situation == 'F')) {
            printf("Não está esquecendo de algo, %s? Procure a recepção!\n", client[i].name);
        }

        if((client[i].password != password[i])) {
            printf("Seja bem-vindo(a)! Procure a recepção!\n");
        }
    }

    return 0;
}