#include "FordFulkerson.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    //Tela inicial
    printf("\n\t\t**********Bem Vindo**********\n");
    printf("\t\t\n");
    printf("\n\t\tEste programa realiza testes com Grafos Bipartidos\n");
    printf("\t\t\n");
    printf("\n\t\tCARREGANDO...\n");
    printf("\t\t\n");
    printf("\n\t\tpressione -Enter- iniciar\n");
    getchar();
    system("cls");

    int vert, edge, task, employees; //declaração dos itens a serem lidos na primeira linha

    printf("Insira respectivamente a quantidade De VERTICES, ARESTAS, TAREFAS e EMPREGADOS \n");
    scanf("%d %d %d %d", &vert, &edge, &task, &employees);

    int **graph; //cria��o do graph em aloca��o de mem�ria cont
    graph = (int**)calloc(vert+2, sizeof(int*));

    int i = 0;

    for (i = 0; i < vert+2; i++){

        graph[i] = (int*)calloc(vert+2, sizeof(int)); /*aloca��o de uma coluna completa para o graph, o tamanho �
        v�rtice +2 e a cria��o da A-origem e B-destino no graph, que s�o os dois ultimos elementos*/

    }

    for (i = 0; i < edge; i++){

        int num1, num2, Weight;

        printf("Insira um valor para o VERTICE De Origem, VERTICE de Destino e o Fluxo Maximo da ARESTA: ");
        scanf ("%d %d %d", &num1, &num2, &Weight); //leitura e atribui��o de valores diretamente no graph

        graph[num1][num2] = Weight;
    }

    for (i = 0; i < task; i++){

        int index_v;

        printf("Indique um -VERTICE- para ser Tarefa: ");
        scanf("%d", &index_v); //identificando um vert que ser� uma task

        graph[vert][index_v] = 99999999; //ligando a A-origem a ela
    }

    for (i = 0; i < employees; i++){

        int edge_index;

        printf("Indique um -VERTICE- para ser empregado: ");
        scanf("%d", &edge_index); //identificando um vert que ser� um employees

        graph[edge_index][vert+1] = 99999999; //ligando ele ao B-destino
    }

     printf("\n\t*****SEU RESULTADO FINAL É...*****\n\n");

    int resp;

    resp = FordFulkerson(vert, graph); //chamando o algoritmo de Ford Fulkerson.
    printf("-Ford Fulkerson: %d\n", resp);

    for (i=0; i<vert+2; i++){
        free(graph[i]);
    }
    free(graph);

    return 0;
}
