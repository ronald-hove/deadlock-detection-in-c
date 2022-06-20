//
// Created by ronald on 2018/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"
#include "helper.h"
#include "graph.h"
#include "main.h"


int main(int argc, char *argv[]) {



    Graph* processGraph = initGraph(GRAPH_SIZE);
    Graph* resourceGraph = initGraph(GRAPH_SIZE);

    /*push(&processGraph->listHead[0], 'A', &processGraph->listTail[0]);
    push(&processGraph->listHead[0], 'B', &processGraph->listTail[0]);
    push(&processGraph->listHead[0], 'C', &processGraph->listTail[0]);


    push(&resourceGraph->listHead[0], 'Z', &resourceGraph->listTail[0]);
    push(&resourceGraph->listHead[0], 'D', &resourceGraph->listTail[0]);
    push(&resourceGraph->listHead[0], 'M', &resourceGraph->listTail[0]);


    printList(&processGraph->listHead[0]);
    printList(&resourceGraph->listHead[0]);*/

    FILE *file = fopen ( argv[1], "r" );


    if ( file != NULL ) {
        char line [BUFFER_SIZE]; /*max size of characters in each line of file */
        while (fgets ( line, sizeof line, file ) != NULL) {
            handleLine(line, &resourceGraph, &processGraph);
        }
        fclose(file);
    }
    else{
        throwInvalidInputException();
    }

    return 0;

}


void handleLine(const char *line, Graph** refToResourceGraph, Graph** refToProcessGraph) {
    int count = 0;
    char temp_outer[MAX_CHAR_LEN] = "";
    char temp_inner[MAX_CHAR_LEN] = "";

    while(strncmp(&line[count], "\0", MAX_CHAR_LEN) != 0){ /*Check if it's the end of the line */
        temp_outer[count] = line[count];
        if(isPushItemValid(line[0]) == 1 ){
            temp_inner[count] = line[count + 2];
            if(strncmp(temp_inner, REQUEST_CMD, MAX_CHAR_LEN) == 0){
                if(isPushItemValid(line[count + 4]) == 1){ /* This & similar check the validity of a command before executing it  */
                    printf("%c----", line[0]);
                    printf("%s----", temp_inner);
                    printf("%c\n", line[count+4]);
                }else{
                    throwInvalidInputException();
                }
            }else if(strncmp(temp_inner, RELEASE_CMD, MAX_CHAR_LEN) == 0){
                if(isPushItemValid(line[count + 4]) == 1){ /* This & similar check the validity of a command before executing it  */
                    printf("%c----", line[0]);
                    printf("%s----", temp_inner);
                    printf("%c\n", line[count+4]);
                }else{
                    throwInvalidInputException();
                }
            }
        }else if(strncmp(temp_outer, CLEAR_CMD, MAX_CHAR_LEN) == 0){
            printf("%s\n", temp_outer);
            (*refToProcessGraph) = initGraph(GRAPH_SIZE);
            (*refToResourceGraph) = initGraph(GRAPH_SIZE);
        }else if(strncmp(temp_outer, KILL_CMD, MAX_CHAR_LEN) == 0){
            printf("%s----", temp_outer);
            printf("%c\n", line[count + 2]);
            /*Do DFS Algorithm to find and kill waiting & allocated processes */
        }else if(line[count] == ' ' && count < (sizeof(KILL_CMD) - 1) && isPushItemValid(line[0]) == 0 && strncmp(temp_outer, KILL_CMD, MAX_CHAR_LEN) != 0){
            throwInvalidInputException();
        }
        count++;
    }
}
