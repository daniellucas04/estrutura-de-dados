#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct Client {
    int ticketNumber;
    char date[10];
    char from[20];
    char to[20];
    char time[5];
    int seat;
    int age;
    char name[50];
} Client;

void clearBuffer() {
    while((getchar() != '\n') && !EOF);
}

int main() {
    Client client[44];
    int countClient = 0, i;

    do {
        scanf("%d", &client[countClient].ticketNumber);

        if (client[countClient].ticketNumber == -1) break;

        clearBuffer();
        scanf("%[^\n]", &client[countClient].date);
        clearBuffer();
        scanf("%[^\n]", &client[countClient].from);
        clearBuffer();
        scanf("%[^\n]", &client[countClient].to);
        clearBuffer();
        scanf("%[^\n]", &client[countClient].time);
        clearBuffer();
        scanf("%d", &client[countClient].seat);
        clearBuffer();
        scanf("%d", &client[countClient].age);
        clearBuffer();
        scanf("%[^\n]", &client[countClient].name);
        clearBuffer();
        countClient++;
    } while(countClient < 44);

    int avgAge = 0;
    for(i=0; i<countClient; i++)
        avgAge += client[i].age;

    if(countClient != 0) 
        avgAge = avgAge/countClient;

    for(i=0; i<countClient; i++) {
        if ((client[i].age > avgAge) && ((client[i].seat % 2) == 0)) {
            printf("%s\n", client[i].name);
        }
    }
    return 0;
}