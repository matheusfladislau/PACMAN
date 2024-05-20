#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/pacman.h"
#include "../mapa/include/mapa.h" 

MAPA m;
POSICAO p;

int direcaomovimentofantasma(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
        { xatual, yatual+1 },
        { xatual+1, yatual },
        { xatual, yatual-1 },
        { xatual-1, yatual },
    };

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if (podeandar(&m, opcoes[posicao][0], opcoes[posicao][1], FANTASMA)) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}

void movefantasmas() {
    MAPA copia;
    copiamapa(&copia, &m);

    for (int i = 0; i < copia.linhas; i++) {
        for (int j = 0; j < copia.colunas; j++) {
            if (copia.matriz[i][j] == FANTASMA) {
                int xdestino, ydestino;
                int encontrou = direcaomovimentofantasma(i, j, &xdestino, &ydestino);
                if (encontrou) {
                    andarmapa(&m, i, j, xdestino, ydestino);
                }
            } 
        }
    }
    liberarmapa(&copia);
}

int acabou() {
    int encontrou = encontrarmapa(&m, &p, PERSONAGEM);
    return !encontrou;
}

int permitemovimento(char direcao){
  return direcao == CIMA || direcao == BAIXO || direcao == ESQUERDA || direcao == DIREITA;
}

void move(char direcao) {
  if (!permitemovimento(direcao)) {
   return;
  }

  int proximox = p.x;
  int proximoy = p.y;

  switch (direcao) {
    case CIMA:
      proximox--;
      break;
    case ESQUERDA:
      proximoy--;
      break;
    case BAIXO:
      proximox++;
      break;
    case DIREITA:
      proximoy++;
      break;
  } 


  if (!podeandar(&m, proximox, proximoy, PERSONAGEM)) {
    return;
  }

  andarmapa(&m, p.x, p.y, proximox, proximoy);
  p.x = proximox;
  p.y = proximoy;
}


int main() {
  lermapa(&m);
  encontrarmapa(&m, &p, PERSONAGEM);

  do {
    imprimirmapa(&m);

    char comando;
    scanf(" %c", &comando);
    move(comando);
    movefantasmas();
  } while (!acabou());

  liberarmapa(&m);
  
  return 0;
}
