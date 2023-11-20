#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct user {
	int age;
	char name[50];
	char gender;
	char maritalStatus;
	int friendsQuantity;
	int photosQuantity;
} User;

void limpaBuffer() {
	while ((getchar() != '\n') && !EOF);
}

User lerUsuario() {
	User user;

	scanf("%d", &user.age);
	limpaBuffer();
	scanf("%[^\n]", &user.name);
	limpaBuffer();
	scanf(" %c", &user.gender);
	limpaBuffer();
	scanf(" %c", &user.maritalStatus);
	limpaBuffer();
	scanf("%d", &user.friendsQuantity);
	limpaBuffer();
	scanf("%d", &user.photosQuantity);
	limpaBuffer();

	return user;
}

void mostrarUsuario(User user) {
	printf("Idade: %d\n", user.age);
	printf("Nome: %s\n", user.name);
	printf("Sexo: %c\n", user.gender);
	printf("Estado Civil: %c\n", user.maritalStatus);
	printf("Numero de amigos: %d\n", user.friendsQuantity);
	printf("Numero de fotos: %d", user.photosQuantity);
}

int main() {
	User *ptrUser, user;
	ptrUser = &user;

	int userQuantity, i=0;
	scanf("%d", &userQuantity);

	User *arrayUser = malloc(userQuantity*sizeof(User));

	limpaBuffer();

	for(i=0; i<userQuantity; i++) 
		arrayUser[i] = lerUsuario();

	for(i=0; i<userQuantity; i++) {
		mostrarUsuario(arrayUser[i]);
		if (i == userQuantity-1) printf("\n");
		else printf("\n\n");
	}

    return 0;
}