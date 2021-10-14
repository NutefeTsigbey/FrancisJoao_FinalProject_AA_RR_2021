#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

//criando estrutura do nodo
typedef struct nodo {
    struct nodo *prox;
    struct nodo *ant;
    int vertice;
}nodo;

//criando estrutura da fila
typedef struct fila {
    struct nodo *primeiro;
    struct nodo *ultimo;
}fila;

fila *criaFila();

int desenfileirar(fila *f, int *visitado); // pra desenfileirar

void enfileirar(int vertice, fila *f, int *visitado); //pra enfileirar

#endif // FILA_H_INCLUDED
