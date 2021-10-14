#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//funcao de busca em largura, BFS
int buscaLargura(int vertice, int *caminho, int **grafo, int **fluxo){

    int A_origem = vertice+1; //determinando que a A-origem é penultimo elemento
    int B_destino = vertice+2; //determinando que  B-destino é o ultimo elemento
    fila *f = criaFila(); //função de criar fila que retorna uma fila do tipo fila

    int *visitado; // 0 é não-visitado,1 é visitado, 2 é visitado todos os vizinhos
    visitado = (int*)calloc((vertice+2), sizeof(int)); //alocação cont para o vetor visitado
    for(int i = 0; i < vertice+2; i++){
        visitado[i] = 0; // colocando todos como não-visitados, ou seja, 0
    }

    enfileirar(A_origem-1, f, visitado); //enfileirar o vértice origem na fila, A-origem se torna visitado .1 no vetor visitado

    while(f->primeiro != NULL){ //condição: enquanto ainda existir elemento na fila, ainda tem lugar pra visitar

        int i = desenfileirar(f, visitado); //desenfileira e ainda torna o visitado .2(fim de vertices visitados)

        for(int j = 0; j < vertice+2; j++){

            //enquanto o vertice ainda não for visitado e se existe um caminho ali
            if(visitado[j] == 0 && (grafo[i][j] - fluxo[i][j] > 0)){

                enfileirar(j, f, visitado); //enfileira ele pra ser analisado
                caminho[j] = i; //chegar no j apartir de i
            }
        }

    }

    int check = visitado[B_destino-1]; //recebe o valor visitado, variando de 0,1 e 2

    free(visitado);
    free(f);

    return (check == 2); //retorna 2 se achar um caminho até B-destino
}

