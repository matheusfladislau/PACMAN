#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/mapa.h"

void copiamapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocarmapa(destino);
    for (int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int posicaovalida(MAPA* m, int x, int y) {
  return (x < m->linhas && y < m->colunas);
}

int posicaoparede(MAPA* m, int x, int y) {
  return (m->matriz[x][y] == PAREDE_VERTICAL) || (m->matriz[x][y] == PAREDE_HORIZONTAL);
}

int posicaopersonagem(MAPA* m, int x, int y, char c) {
    return (m->matriz[x][y] == c);
}

void andarmapa(MAPA* m, int x, int y, int proxx, int proxy) {
    char character = m->matriz[x][y];
    m->matriz[proxx][proxy] = character;
    m->matriz[x][y] = VAZIO; 
}

int podeandar(MAPA* m, int x, int y, char c) {
  return posicaovalida(m, x, y) && !posicaoparede(m, x, y) && !posicaopersonagem(m, x, y, c);
}

void liberarmapa(MAPA* m) {
  for (int i = 0; i < m->linhas; i++) {
    free(m->matriz[i]);
  }

  free(m->matriz);
}

void alocarmapa(MAPA* m) {
  m->matriz = malloc((sizeof m->matriz) * m->linhas);
  for (int i = 0; i < m->linhas; i++){
    m->matriz[i] = malloc((sizeof m->matriz[i]) * m->colunas);
  }
}

void lermapa(MAPA* m) {
	FILE*f;
	f = fopen("./mapa/mapa.txt", "r");
	if (f == 0) {
		printf("Não foi possível acessar o mapa.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(f, "%d %d", &m->linhas, &m->colunas);

  alocarmapa(m);
 	for (int i = 0; i < m->linhas; i++) {
    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);
}

void imprimirmapa(MAPA* m) {
 	for (int i = 0; i < m->linhas; i++) {
    printf("%s\n", m->matriz[i]);
  }
}

int encontrarmapa(MAPA* m, POSICAO* p, char c){
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      if (m->matriz[i][j] == c) {
        p->x = i;
        p->y = j;
        return 1;
      }        
    }
  }
  return 0;
}



