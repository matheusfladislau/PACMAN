#include <stdio.h>
#include <stdlib.h>

#include "pacman.h"
#include "mapa.h" 

MAPA m;
POSICAO p;

int acabou() {
  return 0;
}

void move(char direcao) {
  if (direcao != 'w' && direcao != 'a' && direcao != 's' && direcao != 'd')
    return;

  switch (direcao) {
    case 'w':
      if (verificalimite(&m, p.x-1, p.y) == 1) return;
      m.matriz[p.x][p.y] = '.';
      p.x--;
      break;
    case 'a':
      if (verificalimite(&m, p.x, p.y-1) == 1) return;
      m.matriz[p.x][p.y] = '.';
      p.y--;
      break;
    case 's':
      if (verificalimite(&m, p.x+1, p.y) == 1) return;
      m.matriz[p.x][p.y] = '.';
      p.x++;
      break;
    case 'd':
      if (verificalimite(&m, p.x, p.y+1) == 1) return;
      m.matriz[p.x][p.y] = '.';
      p.y++;
      break;
  }

  m.matriz[p.x][p.y] = '@';
}

int main() {
  lermapa(&m);
  encontrarmapa(&m, &p, '@');

  do {
    imprimirmapa(&m);

    char comando;
    scanf(" %c", &comando);
  move(comando);

  } while (!acabou());

  liberarmapa(&m);
  
  return 0;
}
