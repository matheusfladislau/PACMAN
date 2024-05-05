typedef struct mapa {
  char** matriz;
  int linhas;
  int colunas;
} MAPA;

typedef struct posicao {
  int x;
  int y;
} POSICAO;

void encontrarmapa(MAPA* m, POSICAO* p, char c);

void liberarmapa(MAPA* m);
  
void alocarmapa(MAPA* m);

void lermapa(MAPA* m); 

void imprimirmapa(MAPA* m);

int verificalimite(MAPA* m, int x, int y);
