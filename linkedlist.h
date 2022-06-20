/*
 * Author: Ronald Hove
 * Student Number: 3459314
 * Date: August 30 2018
 * Assignment: Prac 2
 *
 * ------------------------------------------------------------------------------
 *
 * This is a header file for the linkedlist.c program
 *
 * Description:
 * This header defines constants  and function headers
 *
 *
*/

#ifndef LINKED_LIST
#define LINKED_LIST


struct Node{
    char data;
    struct Node* link;
};


char getHead(struct Node* *refToHead);
char getTail(struct Node* *refToTail);
int getSize(struct Node** refToHeadNode);
void printList(struct Node* *refToHeadNode);
int isEmpty(struct Node* *refToHeadNode);
void removeNode(struct Node** refToCurrentHeadNode, char nodeToRemove, struct Node* *refToTail);
void push(struct Node* *refToCurrentHeadNode, char newData, struct Node* *refToTailNode);
void append(struct Node** refToCurrentHeadNode, char newData, struct Node* *refToTailNode);
void insertAfter(char newData, char existingData, struct Node* *refToHeadNode, struct Node* *refToTail);
struct Node** find(struct Node** refToCurrentHeadNode, char dataToFind);
void insertBefore(char newData, char existingData, struct Node* *refToHeadNode, struct Node* *refToTailNode);



#endif //LINKED_LIST
