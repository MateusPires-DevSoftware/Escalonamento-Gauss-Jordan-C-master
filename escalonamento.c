 #include <stdio.h>
#include <locale.h>

int numeroLinhas = 0;
int numeroColunas = 0;


void imprimeMatriz(float a[][numeroColunas]){

	int i = 0;
	int j = 0;

	printf("\n");
	for(i = 0; i < numeroLinhas; i++){
		for(j = 0; j < numeroColunas; j++){
			printf("%f  ", a[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");

}


int main(){

	setlocale(LC_ALL,"Portuguese");

	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	float pivo = 0;
	float pivo2 = 0;

	printf("Informe o n�mero de linhas: ");
	scanf(" %d", &numeroLinhas);

	printf("Informe o n�mero de colunas: ");
	scanf(" %d", &numeroColunas);

	numeroColunas +=1;

	float matriz[numeroLinhas][numeroColunas];
	float vetorAuxiliar[numeroColunas];


	for(i = 0; i < numeroLinhas; i++){
		for(j = 0; j < numeroColunas; j++){
			if(j == (numeroColunas - 1)){
				printf("Informe o valor do termo independente da linha %d, coluna %d: ", i, j);
				scanf(" %f", &matriz[i][j]);
			}else{
				printf("Informe o valor do coeficiente da linha %d, coluna %d: ", i, j);
				scanf(" %f", &matriz[i][j]);
			}
		}
		printf("\n");
	}


	imprimeMatriz(matriz);

	system("pause");



	for(k = 0; k < numeroLinhas; k++){

		pivo = matriz[k][k];


		if(pivo == 0){
			for(m = 0; m < numeroColunas; m++){

				vetorAuxiliar[m] = matriz[k][m];

				matriz[k][m] = matriz[k+1][m];

				matriz[k+1][m] = vetorAuxiliar[m];

				pivo = matriz[k][k];

				imprimeMatriz(matriz);

			}
		}


		for(i = k+1; i < numeroLinhas; i++){

			pivo2 = matriz[i][k];


			for(j = 0; j < numeroColunas; j++){

				matriz[i][j] = ((pivo * matriz[i][j]) - (pivo2 * matriz[k][j]));

			}
		}
	}

	imprimeMatriz(matriz);
	system("pause");


	for(i = 0; i < numeroLinhas; i++){
		pivo = matriz[i][i];


		for(j = 0; j < numeroColunas; j++){
			matriz[i][j] = matriz[i][j]/pivo;
		}
	}

	imprimeMatriz(matriz);


	for(k = numeroColunas - 2; k > 0; k--){


		for(i = k-1; i >= 0; i--){
			pivo = matriz[k][k];
			pivo2 = matriz[i][k];


			for(j = numeroColunas - 1; j >= 0; j--){

				matriz[i][j] = ((pivo * matriz[i][j]) - (pivo2 * matriz[k][j]));

			}
		}
	}
	system("pause");
	imprimeMatriz(matriz);

	return 0;
}

/*
Etapas principais do código:
Leitura da matriz aumentada: O usuário informa o número de linhas e colunas (acrescida de 1 para incluir os termos independentes).

Exibição da matriz original.

Etapa de eliminação (Gauss):

Tenta colocar zeros abaixo da diagonal principal.

Se o pivô for zero, troca com a próxima linha.

Normalização das linhas: Transforma os pivôs em 1.

Etapa de retro-substituição (Jordan):

Zera os elementos acima da diagonal principal.

Exibe a matriz resultante: Que deve estar na forma da matriz identidade com a última coluna contendo a solução do sistema.
*/