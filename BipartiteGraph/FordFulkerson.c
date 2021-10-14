#include <stdio.h>
#include <stdlib.h>
#include "FordFulkerson.h"
#include "BFS.h"

int FordFulkerson(int vertice,int **grafo){
    int i;
    int fluxo_maximo = 0; // vari�vel que retornar� o fluxo m�ximo desejado.
    int **fluxo;
    fluxo = (int**)calloc(vertice+2,sizeof(int*)); //cria��o do grafo residual - fluxo - em mem�ria din�mica.

    for (i = 0; i < vertice+2; i++){
            fluxo[i] = (int)calloc(vertice+2, sizeof(int));/*aloca��o de uma coluna completa para o grafo fluxo,
            o tamanho � v�rtive+2 pois j� crio a A-origem e B-destino no grafo, que ser�o os dois ultimos elementos. este � o grafo residual*/

    }

    int *caminho;
    caminho = (int*)malloc((vertice+2)*sizeof(int)); //criado o vetor que guardar� o caminho da busca em largura realizada.

    while(buscaLargura(vertice, caminho, grafo, fluxo)){ // enquanto a busca de caminhos no algoritmo da Busca em Largura exitir
        int incremento_maximo = 999999; // valor alto para que n�o seja nunca o menor na compara��o dentro do for
        for (i = vertice+1; caminho[i] >=0; i = caminho[i]){ //leitura do caminho de tr�s para frente para determinar o incremento m�ximo daquele caminho

            if(incremento_maximo < (grafo[caminho[i]][i] - fluxo[caminho[i]][i])) {
                incremento_maximo = incremento_maximo;
            } else {
                incremento_maximo = grafo[caminho[i]][i] - fluxo[caminho[i]][i];

            }

                                                        }

        for (i = vertice+1; caminho[i] >=0; i = caminho[i]){ //ler caminho de tr�s para frente, incrementando ou decrementando seu valor de acordo com sua dire��o.
            fluxo[caminho[i]][i] = fluxo[caminho[i]][i] + incremento_maximo; //incrementado
            fluxo[i][caminho[i]] = fluxo[caminho[i]][i] - incremento_maximo; //decrementando

                                                            }

        fluxo_maximo = fluxo_maximo + incremento_maximo; //fluxo m�ximo � determinado

        printf("Valor do Destino: %d\n", incremento_maximo);

    }

    free(caminho);

    for (i = 0; i < vertice+2; i++){
        free(fluxo[i]); //libero mem�ria alocada para cada elemento do grafo fluxo
                                    }

    free(fluxo);

    return fluxo_maximo;
}


