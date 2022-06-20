//
// Created by ronald on 2018/10/24.
//


#ifndef PRAC4DEADLOCK_GRAPH_H
#define PRAC4DEADLOCK_GRAPH_H


typedef struct Graph{
    struct Node** listHead;
    struct Node** listTail;
} Graph;

#define GRAPH_SIZE 26

Graph* initGraph(int N);

#endif //PRAC4DEADLOCK_GRAPH_H
