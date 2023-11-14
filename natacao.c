#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * sort: Ordena um vetor com o tipo double;
 * 
 * @param address ptrArray: Endereço de memória do vetor
 * @return void
*/
void sort(double *ptrArray) {
	int i=0;
	for(i=1; i<2; i++) {
		double key = ptrArray[i];
		int index = i;

		while(index > 0 && ptrArray[index-1] > key) {
			ptrArray[index] = ptrArray[index-1];
			index--;
		}
		ptrArray[index] = key;
	}
}

/**
 * showValues: Mostra os valores dentro de um vetor de tipo double
 * 
 * @param address ptrArray: Endereço de memória do vetor
 * @return void
*/
void showValues(double *ptrArray) {
	int i;
	for(i=0; i<100; i++) 
		printf("%lf\n", ptrArray[i]);
}

/**
 * clearArray: Limpa o lixo de memória dentro do vetor adicionando 0 nas posições
 * 
 * @param address ptrArray: Endereço de memória do vetor
 * @return void
*/
void clearArray(double *ptrArray) {
	int i;
	for(i=0;i<(sizeof(ptrArray)/sizeof(ptrArray[0])); i++) {
		ptrArray[i] = 0.0;
	}
}

int main() {
	int minuto, i=0;
	double segundos;
	char minutoString[100], segundosString[100], concatString[100];

	// Recebe os valores
	while(scanf("%d:%lf", &minuto, &segundos) != EOF){
		// Transforma em texto e concatena
		itoa(minuto, minutoString, 10);
		sprintf(segundosString, "%lf", segundos);
		strcat(concatString, minutoString);
		strcat(concatString, segundosString);

		// Transformar em número 
		double timeInDouble = atof(concatString);
		printf("%lf\n\n", timeInDouble);
		// Adicionar valor dentro de um array
		double timeArray[100];
		
		// Retira o lixo de memória
		clearArray(timeArray);
		timeArray[i] = timeInDouble;
		i++;

		// Ordena o array em ordem crescente
		sort(timeArray);
		// Mostra os valores ordenados
		// showValues(timeArray);

		minuto = 0;
		segundos = 0;
	}

	return 0;
}