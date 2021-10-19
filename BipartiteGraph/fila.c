#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//criar ponteiro da fila
fila *cria_fila(){

    fila *f;
    f=(fila*) malloc (sizeof(fila));
    f->first=NULL;
    f->last=NULL;
    return f;

}

//defini��o da fun��o pra enfileirar fila
void faz_fila(int vert, fila *f, int *visited){

    nodo *n;
    n=(nodo*)malloc(sizeof(nodo));
    n->vert=vert;
    visited[n->vert]=1;
    n->prox=NULL;
    n->ant=NULL;

    if (f->first==NULL){
        f->first=n;
        f->last=n;

    } else {
        f->last->prox=n;
        f->last=n;

    }
}

//defini��o da fun��o pra desenfileirar
int quebra_Fila(fila *f, int *visited){
    
    if (f->first==NULL){
        return -1;
    }

    nodo *n;
    n=f->first;
    visited[n->vert]=2;
    f->first=f->first->prox;
    int volta=n->vert;
    free (n);

    return volta;

}



