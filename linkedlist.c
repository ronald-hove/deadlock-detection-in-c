/*
 * Author: Ronald Hove
 * Student Number: 3459314
 * Date: August 30 2018
 * Assignment: Practical 4
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"
#include "helper.h"



/*
 * This function checks if the linked list is empty or not
 * Algorithm
 * 1. Method to check if linked list is populated with nodes
 * 2. Performs a null pointer check on the head node
 * 3. Returns an integer either 0 or 1, 1 if there are nodes in linked list, 0 if none
 *
 * Outputs
 * No outputs
 *
 */
int isEmpty(struct Node* *refToHeadNode){
    return *refToHeadNode == NULL ? 1 : 0;
}


/*
 * This function pushes new nodes onto the linked list using the following algorithm
 *
 * Algorithm
 * 1. If the item to push is validated
 * 2.       allocate node
 * 3.       put in the data
 * 4.       if the list is empty
 * 5.           set tail to the new node
 * 6.       Make next of new node as head
 * 7.       move the head to point to the new node
 *
 * Inputs
 * refToCurrentHeadNode is the address of the previously pushed node
 * newData contains the actual data stored by the newly created node being pushed
 *
 * Outputs
 * Outputs an error if the input is invalid
 *
 */
void push(struct Node* *refToCurrentHeadNode, char newData, struct Node* *refToTailNode){

    if(isPushItemValid(newData) == 1){
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data  = newData;

        if(isEmpty(&(*refToCurrentHeadNode)) == 1){
            (*refToTailNode) = newNode;
        }

        newNode->link = (*refToCurrentHeadNode);
        (*refToCurrentHeadNode)  = newNode;
    }else{
        throwInvalidInputException();
    }
}

/*
 * This function adds new nodes onto the linked list at the position before the head node
 *
 * Algorithm
 * 1.  allocate node
 * 2.  set a node last as ref to the last node
 * 3.  set the link to new node to NULL
 * 4.       if the list is empty
 * 5.           set head to the new node
 * 6.       Otherwise traverse to the end of the list
 * 7.       make tail pointer point to the new node
 *
 * Inputs
 * refToCurrentHeadNode is the address of the previously pushed node
 * newData contains the actual data stored by the newly created node being pushed
 *
 * Outputs
 * No outputs
 *
 */
void append(struct Node** refToCurrentHeadNode, char newData, struct Node* *refToTailNode) {


    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *refToCurrentHeadNode;

    newNode->data  = newData;
    newNode->link = NULL;

    if (isEmpty(&*(refToCurrentHeadNode)) == 1) {
        *refToCurrentHeadNode = newNode;
        return;
    }

    while (last->link != NULL){
        last = last->link;
    }

    last->link = newNode;
    (*refToTailNode) = newNode;
}


/*
 * This function adds a node after some existing node in the list
 *
 * Algorithm
 * 1. Find the node which will be previous to the new node to enter the list
 * 2. check if the search result returned anything other than null or of the list is empty
 * 3.       if yes throw an exception
 * 4.       Otherwise
 * 5.           set the pointer to the previous node to the new node's pointer to point to thew next node
 *
 * newData is data contained in thew new allocated node
 * existing data is the data contained in the node before thew new node to enter the list
 *
 * Outputs
 * No outputs to the user
 *
 */
void insertAfter(char newData, char existingData, struct Node* *refToHeadNode, struct Node* *refToTail){

    struct Node** previousNode = find(&(*refToHeadNode), existingData);

    if (previousNode == NULL || isEmpty(&(*refToHeadNode)) == 1) {
        throwInvalidInputException();
        return;
    }

    push(&(*previousNode)->link,newData, &(*refToTail));
}


/*
 * This function adds a node before some existing node in the list
 *
 * Algorithm
 * 1. Find the node which will be previous to the new node to enter the list
 * 2. check if the search result returned anything other than null or of the list is empty
 * 3.       if yes throw an exception
 * 4.       Otherwise
 * 5.           set the pointer to the previous node to the new node's pointer to point to thew next node
 *
 * Inputs
 * newData is data contained in thew new allocated node
 * existing data is the data contained in the node after thew new node to enter the list
 *
 * Outputs
 * no outputs to the user
 *
 */
void insertBefore(char newData, char existingData, struct Node* *refToHeadNode, struct Node* *refToTailNode){

    struct Node** nextNode = find(&(*refToHeadNode), existingData);

    if (nextNode == NULL || isEmpty(&(*refToHeadNode)) == 1) {
        throwInvalidInputException();
        return;
    }

    push(nextNode,newData, &(*refToTailNode));
}


/*
 * This function nodes containing specific input data
 *
 * Algorithm
 * 1. If list is not empty
 * 2.       traverse the list while there are nodes
 * 3.           check if the dataToFind is equal to each node in the list
 * 4.           if data is equal
 * 5.              return the data and exit the loop
 * 6.       return null if no data found
 *
 *
 * Inputs
 * refToCurrentHeadNode is the address of the previously pushed node
 * newData contains the actual data stored by the newly created node being pushed
 *
 * Outputs
 * No user outputs
 *
 * Return data
 *
 * the node containing the input data if found or null
 *
 */
struct Node** find(struct Node** refToCurrentHeadNode, char dataToFind){

    if(isEmpty(&(*refToCurrentHeadNode)) == 0){
        struct Node** temp = &(*refToCurrentHeadNode);
        while (*temp){

            if((*temp)->data == dataToFind){
                return temp;
            }
            temp = &(*temp)->link;
        }
    }
    return NULL;
}


/*
 * This function prints the data at each node in the linked list
 * Function of type void | no returned outputs
 *
 * Algorithm
 * 1. allocate node temp to the head node
 * 2. create a counter
 * 3. Iterate while the next node is not NULL
 * 4.       check if the counter is in range (0,size of linked list)
 * 5.           print a [-] after each printed node
 * 6.       print the date at each node
 * 7.       set temp equal to the next node
 * 8.       increment count variable
 * 9. print a new line after loop exits
 *
 * Outputs
 * prints out the data at each node for the size of the linked list
 *
 */
void printList(struct Node** refToHeadNode){

    if(isEmpty(&(*refToHeadNode)) == 1){
        printf("%s\n", "-");
    }else{
        struct Node** temp = &(*refToHeadNode);
        int count = 0;
        while (*temp != NULL){
            if(count > 0 && count < getSize(&(*refToHeadNode))) {
                printf("%s", "-");
            }
            printf("%c", (*temp)->data);
            temp = &(*temp)->link;
            count++;
        }
        printf("\n");
    }

}



/*
 * This function removes a node that contains a specified data item
 *
 * Algorithm
 * 1. Check if linked list is empty
 * 2.     throw an invalid input  | cant run remove command on empty list
 * 3.         return; | Simply break out of the method
 * 4. Otherwise
 * 5.     Create a new node temp which holds a reference to the head & last which points to the tail
 * 6.     Check if the temp node holds the node to remove
 * 7.           if yes then remove it and decrement the size of list as well remove the link and lastly free that memory
 * 8. Otherwise iterate the list while the pointer to each successive node is not a null pointer
 * 9.     if data in temp is equal to the node to remove
 * 10.          if date in temp is equal to the tail node data
 * 11.              set tail to the last node
 * 12.          set pointer to last node  equal to pointer to temp node
 * 13               decrement the size
 * 14               free up the memory
 *
 * Inputs
 * struct Node* *referenceToHeadNode | a pointer to the head node
 * char nodeToRemove | the data specific to the node to remove
 *
 * Outputs
 * Outputs an error if the the input is invalid
 *
 */
void removeNode(struct Node** refToCurrentHeadNode, char nodeToRemove, struct Node** refToTail){

    if (isEmpty(&(*refToCurrentHeadNode)) == 1){ /*Check if the list is empty*/
        throwInvalidInputException();
        return;
    }else{
        struct Node** temp = &(*refToCurrentHeadNode), **last = temp;

        if ((*temp) != NULL && (*temp)->data == nodeToRemove){ /* Check if the head node is the nodeToRemove */
            (*refToCurrentHeadNode) = (*temp)->link;
            //free(*temp);
            return;
        }
        while (*temp != NULL){
            if((*temp)->data == nodeToRemove){
                if((*temp)->data == (*refToTail)->data){
                    (*refToTail) = (*last); /*set tail as the last node*/
                }
                (*last)->link = (*temp)->link;
                //free((*temp));
                return;
            }
            last = temp;
            temp = &(*temp)->link;

        }
        throwInvalidInputException(); /* if program ends up here that means nodeToRemove was not found*/
    }
}



/*
 * This function returns the data in the head node of the linked list
 *
 * Algorithm
 * 1. return tail->data | a pointer accessing  the data in the head node
 *
 * Inputs
 * No inputs
 *
 * Outputs
 * No outputs
 *
 */
char getHead(struct Node* *refToHead){
    return (*refToHead)->data;

}


/*
 * This function returns the data in the tail node of the linked list
 * Algorithm
 * return tail->data | a pointer accessing  the data in the tail node
 *
 * Inputs
 * No inputs
 *
 * Outputs
 * No outputs
 *
 */
char getTail(struct Node* *refToTail){
    return (*refToTail)->data;
}


/*
 * This function returns the size of the linked list
 * Algorithm
 * 1. return size | an int storing the size of the array
 *
 * Inputs
 * No inputs
 *
 * Outputs
 * No outputs
 *
 */
int getSize(struct Node** refToHeadNode){
    int size = 0;
    if (isEmpty(&(*refToHeadNode)) == 1){
        size = 0;
    }else{
        struct Node** temp = &(*refToHeadNode);
        size = 0;
        while (*temp != NULL){
            size++;
            temp = &(*temp)->link;
        }

    }
    return size;
}
