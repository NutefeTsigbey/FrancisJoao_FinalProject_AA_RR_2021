#include <stdio.h>
#include <stdlib.h>
#include "FordFulkerson.h"
#include "BFS.h"

int FordFulkerson(int vertice,int **grafo){
    int i;
    int fluxo_maximo = 0; // variável que retornará o fluxo máximo desejado.
    int **fluxo;
    fluxo = (int**)calloc(vertice+2,sizeof(int*)); //criação do grafo residual - fluxo - em memória dinâmica.

    for (i = 0; i < vertice+2; i++){
            fluxo[i] = (int)calloc(vertice+2, sizeof(int));/*alocação de uma coluna completa para o grafo fluxo,
            o tamanho é vértive+2 pois já crio a A-origem e B-destino no grafo, que serão os dois ultimos elementos. este é o grafo residual*/

    }

    int *caminho;
    caminho = (int*)malloc((vertice+2)*sizeof(int)); //criado o vetor que guardará o caminho da busca em largura realizada.

    while(buscaLargura(vertice, caminho, grafo, fluxo)){ // enquanto a busca de caminhos no algoritmo da Busca em Largura exitir
        int incremento_maximo = 999999; // valor alto para que não seja nunca o menor na comparação dentro do for
        for (i = vertice+1; caminho[i] >=0; i = caminho[i]){ //leitura do caminho de trás para frente para determinar o incremento máximo daquele caminho

            if(incremento_maximo < (grafo[caminho[i]][i] - fluxo[caminho[i]][i])) {
                incremento_maximo = incremento_maximo;
            } else {
                incremento_maximo = grafo[caminho[i]][i] - fluxo[caminho[i]][i];

            }

                                                        }

        for (i = vertice+1; caminho[i] >=0; i = caminho[i]){ //ler caminho de trás para frente, incrementando ou decrementando seu valor de acordo com sua direção.
            fluxo[caminho[i]][i] = fluxo[caminho[i]][i] + incremento_maximo; //incrementado
            fluxo[i][caminho[i]] = fluxo[caminho[i]][i] - incremento_maximo; //decrementando

                                                            }

        fluxo_maximo = fluxo_maximo + incremento_maximo; //fluxo máximo é determinado

        printf("Valor do Destino: %d\n", incremento_maximo);

    }

    free(caminho);

    for (i = 0; i < vertice+2; i++){
        free(fluxo[i]); //libero memória alocada para cada elemento do grafo fluxo
                                    }

    free(fluxo);

    return fluxo_maximo;
}


