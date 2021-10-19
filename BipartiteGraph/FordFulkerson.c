#include <stdio.h>
#include <stdlib.h>
#include "FordFulkerson.h"
#include "BFS.h"
//max_flow
int FordFulkerson(int vert,int **graph){

    int i;
    int max_flow = 0; // vari�vel que retorna o fluxo m�ximo desejado.
    int **flow;
    flow=(int**)calloc(vert+2,sizeof(int*)); //cria grafo residual - fluxo - usando alocação din�mica de mem�ria .

    for (i=0; i<vert+2; i++){
        flow[i]=(int)calloc(vert+2, sizeof(int));//aloca uma coluna completa para o graph flow,
    }

    int *path;    
    path=(int*)malloc((vert+2)*sizeof(int)); //criado o vetor que guardar� o path da busca em largura realizada.

    while(BFS(vert, path, graph, flow)){ // enquanto a busca de caminhos no algoritmo da Busca em Largura exitir
        
        int max_increase = 999999; // valor alto para que n�o seja nunca o menor na compara��o dentro do for

        for (i=vert+1; path[i]>=0; i=path[i]){ //leitura do path de tr�s para frente para determinar o incremento m�ximo daquele path

            if(max_increase<(graph[path[i]][i]-flow[path[i]][i])) {
                max_increase=max_increase;
            } 

            else {
                max_increase=graph[path[i]][i]-flow[path[i]][i];
            }

        }

        for (i=vert+1; path[i]>=0; i=path[i]){ //ler path de tr�s para frente, incrementando ou decrementando seu valor de acordo com sua dire��o.
            flow[path[i]][i] = flow[path[i]][i] + max_increase; //incrementado
            flow[i][path[i]] = flow[path[i]][i] - max_increase; //decrementando

        }

        max_flow=max_flow+max_increase; //flow m�ximo � determinado
        printf("Valor do Destino: %d\n", max_increase);
    }

    free(path);

    for (i=0; i<vert+2; i++){
        free(flow[i]); //libero mem�ria alocada para cada elemento do graph flow
    }

    free(flow);

    return max_flow;
}


