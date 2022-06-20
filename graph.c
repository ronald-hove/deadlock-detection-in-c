//
// Created by ronald on 2018/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"
#include "linkedlist.h"
#include "helper.h"


Graph* initGraph(int N){

    Graph* graph = (Graph*) malloc(sizeof(Graph*));
    graph->listHead = malloc(N * sizeof(struct Node*));
    graph->listTail = malloc(N * sizeof(struct Node*));

    for(int i = 0; i < N ; i++){
        graph->listHead[i] = NULL;
        graph->listTail[i] = graph->listHead[i];
    }
    return graph;
}



