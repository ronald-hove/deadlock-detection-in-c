//
// Created by ronald on 2018/10/24.
//

#include "graph.h"

#ifndef PRAC4DEADLOCK_MAIN_H
#define PRAC4DEADLOCK_MAIN_H


#define BUFFER_SIZE 20
#define MAX_CHAR_LEN 20

#define REQUEST_CMD "requests"
#define RELEASE_CMD "releases"
#define KILL_CMD "kill"
#define CLEAR_CMD "clear"

void handleLine(const char *line, Graph** refToResourceGraph, Graph** refToProcessGraph);


#endif //PRAC4DEADLOCK_MAIN_H
