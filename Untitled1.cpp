//programa que implementa um percurso no grafo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração de constante

const int tamanho = 700;

//função que cria o grafo

void criar(int grafo[tamanho][tamanho], int aleatorio) {
	int i = 0;
	int j = 0;
	int aresta = 0;
	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < tamanho; j++) {
			grafo[i][j] = 0;
		}
	}
	
	//preenchimento do grafo
	for (i = 0; i < tamanho - 1; i++) {
		for (j = (i +1); j < tamanho; j++) {
			if (aleatorio) {
				aresta = (rand() % 2);
			} else {
				printf("Digite <1> se %d tem aresta com %d: ", i, j);
				scanf("%d", &aresta);
			}
			grafo[i][j] = aresta;
			grafo[j][i] = aresta;
		}
	}
	
}

//funcao recursiva que executa a descoberta do caminho

int procurarPercursoRecursivo(int grafo[tamanho][tamanho], int visitado[tamanho], int inicio, int fim) {
	int vizinho, retorno = 0;
	if (inicio == fim) {
		retorno = 1;
	} else {
		visitado[inicio] = 1;
		for (vizinho = 0; vizinho < tamanho; vizinho++) {
			if ((grafo[inicio][vizinho]) && (! visitado[vizinho])) {
				if (procurarPercursoRecursivo(grafo, visitado, vizinho, fim)) {
					retorno = 1;
					printf("%d <-", vizinho);
					break;
				}
			}
		}
	}
	return retorno;
}

 // funcao que executa a descoberta do caminho 
 
 int procurarPercurso(int grafo[tamanho][tamanho], int inicio, int fim) {
 	int i = 0;
 	int visitado[tamanho];
 	int encontrei = 0;
 	
 	for (i = 0; i < tamanho; i++) {
 		visitado[i] = 0;
	 }
	 encontrei = procurarPercursoRecursivo(grafo, visitado, inicio, fim);
	 printf("%d\n", inicio);
	 
	 return encontrei;
 }
 
 // funcao principal de execucao de programa
 
 int main() {
 	int grafo[tamanho][tamanho];
 	int inicio, fim = 0;
 	criar(grafo, 1);
 	printf("Digite o vertice inicial: ");
 	scanf("%d", &inicio);
 	printf("Digite o vertice final: ");
 	scanf("%d", &fim);
 	
 	if (procurarPercurso(grafo, inicio, fim)) {
 		printf("Ha um caminho!\n");
	 } else {
	 	printf("Nao ha um caminho!\n");
	 }
 }
