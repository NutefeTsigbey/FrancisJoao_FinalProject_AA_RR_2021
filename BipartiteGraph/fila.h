#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
//v = vertice
//criando estrutura do nodo
typedef struct nodo {
    struct nodo *prox;
    struct nodo *ant;
    int vert;
}nodo;

//criando estrutura da fila
typedef struct fila {
    struct nodo *first;
    struct nodo *last;
}fila;

fila *criaFila();

int desenfileirar(fila *f, int *visited); // pra desenfileirar

void enfileirar(int vert, fila *f, int *visited); //pra enfileirar

#endif // FILA_H_INCLUDED
