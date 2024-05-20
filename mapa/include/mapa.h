#define FANTASMA 'F'
#define PERSONAGEM '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

typedef struct mapa {
  char** matriz;
  int linhas;
  int colunas;
} MAPA;

typedef struct posicao {
  int x;
  int y;
} POSICAO;

void copiamapa(MAPA* destino, MAPA* origem);

int posicaovalida(MAPA* m, int x, int y);

int posicaoparede(MAPA* m, int x, int y);

int posicaopersonagem(MAPA* m, int x, int y, char c);

void andarmapa(MAPA* m, int x, int y, int proxx, int proxy);

int podeandar(MAPA* m, int x, int y, char c); 

void liberarmapa(MAPA* m);
  
void alocarmapa(MAPA* m);

void lermapa(MAPA* m); 

void imprimirmapa(MAPA* m);

int encontrarmapa(MAPA* m, POSICAO* p, char c);
