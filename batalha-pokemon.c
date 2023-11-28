#include<stdio.h>

typedef struct Pokemon {
    char name[50];
    int id;
    int attack;
    int health;
} Pokemon;

typedef struct Fight {
    Pokemon red;
    Pokemon blue;
} Fight;

void clearBuffer() {
    while((getchar() != '\n') && !EOF);
}

int main() {
    Pokemon blue[6], red[6];
    Fight fight;
    int i;

    for(i=0; i<6; i++) {
        scanf("%[^\n]", &red[i].name);
        clearBuffer();
        scanf("%d", &red[i].id);
        clearBuffer();
        scanf("%d", &red[i].attack);
        clearBuffer();
        scanf("%d", &red[i].health);
        clearBuffer();
    }

    fight.red = red[0];
    
    for(i=1; i<6; i++) {
        if(red[i].attack > fight.red.attack) {
            fight.red = red[i];
        }

        if((red[i].attack == fight.red.attack) && (red[i].id < fight.red.id) ) {
            fight.red = red[i];
        }
    }

    for(i=0; i<6; i++) {
        scanf("%[^\n]", &blue[i].name);
        clearBuffer();
        scanf("%d", &blue[i].id);
        clearBuffer();
        scanf("%d", &blue[i].attack);
        clearBuffer();
        scanf("%d", &blue[i].health);
        clearBuffer();
    }

    fight.blue = blue[0];
    
    for(i=1; i<6; i++) {
        if(blue[i].attack > fight.blue.attack) {
            fight.blue = blue[i];
        }

        if((blue[i].attack == fight.blue.attack) && (blue[i].id < fight.blue.id) ) {
            fight.blue = blue[i];
        }
    }

    int blueAttack = fight.blue.attack, redAttack = fight.red.attack;
    while(fight.red.health > 0 || fight.blue.health > 0) {
        fight.blue.health -= redAttack;
        fight.red.health -= blueAttack;

        if(fight.blue.health <= 0) break;
        if(fight.red.health <= 0) break;
    }

    printf("Pokemon do Red: %s\n", fight.red.name);
    printf("Pokemon do Blue: %s\n", fight.blue.name);
    if (fight.blue.health <= 0 && fight.red.health > 0) {
        printf("Vencedor: Red\n");
    }   
    
    if (fight.red.health <= 0 && fight.blue.health > 0) {
        printf("Vencedor: Blue\n");
    }
    
    if (fight.red.health <= 0 && fight.blue.health <= 0) {
        printf("Empate\n");
    }

    return 0;
}