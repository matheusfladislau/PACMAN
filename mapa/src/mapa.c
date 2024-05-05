#include <stdio.h>
#include <stdlib.h>

#include "../include/mapa.h"

void liberarmapa(MAPA* m) {
  for (int i = 0; i < m->linhas; i++)
    free(m->matriz[i]);

  free(m->matriz);
}

void alocarmapa(MAPA* m) {
  m->matriz = malloc((sizeof m->matriz) * m->linhas);
  for (int i = 0; i < m->linhas; i++)
    m->matriz[i] = malloc((sizeof m->matriz[i]) * m->colunas);
}

void lermapa(MAPA* m) {
	FILE*f;
	f = fopen("./mapa/mapa.txt", "r");
	if (f == 0) {
		printf("Não foi possível acessar o mapa.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(f, "%d %d", &m->linhas, &m->colunas);
	printf("linhas: %d, colunas: %d\n", m->linhas, m->colunas);

  alocarmapa(m);
 	for (int i = 0; i < m->linhas; i++) 
    fscanf(f, "%s", m->matriz[i]);

  fclose(f);
}

void imprimirmapa(MAPA* m) {
 	for (int i = 0; i < m->linhas; i++)
      printf("%s\n", m->matriz[i]);
}

void encontrarmapa(MAPA* m, POSICAO* p, char c){
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      if (m->matriz[i][j] == c) {
        p->x = i;
        p->y = j;
        break;
      }        
    }
  }
}

int verificalimite(MAPA* m, int x, int y) {
  return (m->matriz[x][y] == '|' || m->matriz[x][y] == '-');
}




