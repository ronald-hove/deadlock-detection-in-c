//
// Created by ronald on 2018/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"



/*
 * This function checks the item to be pushed is an alphabetical character that is between A- Z and is upper case
 *
 * Algorithm
 * 1. Check if the input item is an alphabetic character
 * 2.     Check if the alphabetic character is uppercase between A - Z
 * 3.         return 1 if condition met
 * 4.     return 0 if above condition not met
 * 5. return 0 if the first condition is not met
 *
 * Inputs
 * A character item to the run through the comparison algorithm
 *
 * Outputs
 * No outputs
 *
 */
int isPushItemValid(char item){
    if(isalpha(item) != 0){
        if(item  >= 'A' && item <= 'Z'){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}


/*
 * This function checks if a command is valid before executing it
 *
 * Algorithm
 * 1. check if the next character  is either  a space or new line char or or this character "\0"
 * 2. return 1 if the above condition passes or 0 if not
 *
 * Inputs
 * a character c to the run through the comparison algorithm
 *
 * Outputs
 * No outputs
 *
 */
int checkValidCommand(char c){
    return c == ' ' ||  c == '\n' || c == '\0' ? 1 : 0;
}


/*
 * This function throws an exception when inputs are invalid
 * Algorithm
 * 1. pipe output to stderr
 *
 * Inputs
 * No inputs
 *
 * Outputs
 * Prints out error to stderr
 *
 */
void throwInvalidInputException(){
    fprintf(stderr,"Input not valid\n");
}
