#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

//PROGRAMA PARA LEER GRAFOS

//MATRICES

bool** allocate_matrix(int N, int M) {
	bool** m = (bool**)malloc(sizeof(bool*)*N);
	for (int i = 0; i < N; i++) {
		m[i] = (bool*)malloc(sizeof(bool)*M);
	}
	//Check if (m == NULL)return NULL; // perror
	//

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			m[i][j] = 0;
		}
	}

	return m;

}

void free_matrix(bool** m, int N) {
	for (int i = 0; i < N; i++){
		free(m[i]);
	}
	free(m);
	m = NULL;
}

void print_matrix(bool ** m, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

//GRAFOS

graph* init_graph(int NV) {
	graph* pg = (graph*)malloc(sizeof(graph));
	pg->NV = NV;
	pg->adj = allocate_matrix(pg->NV, pg->NV);

	return pg;

}

void free_graph(graph* pg) {
	free_matrix(pg->adj, pg->NV);
	free(pg);
	pg = NULL;
}

void print_header(graph* pg) {
	printf("Grafo con %d vertices\n", pg->NV);
}

void print_edges(graph* pg) { //Imprime qué nodos están enlazados, no la matriz en sí
	for (int i = 0; i < pg->NV; i++) {
		for (int j = i + 1; j < pg->NV; j++) { //j = i + 1 para solo parte superior
			if (pg->adj[i][j] == 1) {
				printf("%d...%d\n", i + 1, j + 1);
			}
		}
	}
}