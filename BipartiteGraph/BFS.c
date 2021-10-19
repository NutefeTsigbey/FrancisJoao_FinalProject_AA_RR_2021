#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//funcao de busca em largura, BFS
int BFS(int vert, int *path, int **graph, int **flow){

    int A_origin = vert+1; //determinando que a A-origem � penultimo elemento
    int B_destiny = vert+2; //determinando que  B-destino � o ultimo elemento

    fila *f = cria_fila(); //fun��o de criar fila que retorna uma fila do tipo fila

    int *visited; // 0 � n�o-visited,1 � visited, 2 � visited todos os vizinhos
    visited = (int*)calloc((vert+2), sizeof(int)); //aloca��o cont para o vetor visited
    for(int i = 0; i < vert+2; i++){
        visited[i] = 0; // colocando todos como n�o-visitados, ou seja, 0
    }

    faz_fila(A_origin-1, f, visited); //enfileirar o v�rtice origem na fila, A-origem se torna visited .1 no vetor visited

    while(f->first != NULL){ //condi��o: enquanto ainda existir elemento na fila, ainda tem lugar pra visitar

        int i = quebra_Fila(f, visited); //desenfileira e ainda torna o visited .2(fim de vertices visitados)

        for(int j = 0; j < vert+2; j++){

            //enquanto o vert ainda n�o for visited e se existe um path ali
            if(visited[j] == 0 && (graph[i][j] - flow[i][j] > 0)){

                faz_fila(j, f, visited); //enfileira ele pra ser analisado
                path[j] = i; //chegar no j apartir de i
            }
        }

    }

    int check = visited[B_destiny-1]; //recebe o valor visited, variando de 0,1 e 2

    free(visited);
    free(f);

    return (check == 2); //retorna 2 se achar um path at� B-destino
}

