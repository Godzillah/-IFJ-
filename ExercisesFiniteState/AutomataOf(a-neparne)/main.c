#include <stdio.h>

/* ERRORS */
#define SUCCESS 0
#define LEX_ERROR 1
/*  STATES OF AUTOMATA  -----> Q */
#define S_START 100
#define S_END 101
/* INPUT ALFABET  -----------> E*/
#define ENTER 10

int counterOfChars = 0;

/**
 * Function, which take token from standard input
 * * @return actual token
 */
int getToken(){
    int concreteSymbol; // lexems
    int state = S_START;

    while((concreteSymbol = getchar()) != EOF){
        switch (state){
            case S_START:
                printf("S_START\n");
                if(concreteSymbol == 'a'){
                    printf("Symbol -> %c\n", concreteSymbol);
                    counterOfChars++;
                    state = S_END;
                }
                else if(concreteSymbol == ENTER){
                    getchar();
                }
                else{
                    return LEX_ERROR;
                }
                break;
            case S_END:
                printf("S_END\n");
                if(concreteSymbol == 'a'){
                    printf("Symbol -> %c\n", concreteSymbol);
                    counterOfChars++;
                    state = S_START;
                }
                // 10 is value representing ENTER from ASCII
                else if(concreteSymbol == ENTER){
                    getchar();
                }
                else if(concreteSymbol == EOF){
                    return SUCCESS;
                }
                else{
                    return LEX_ERROR;
                }
                break;
        }
    }
}

int main() {
    printf("***** LEX STARTS *****\n");
    int actToken  = getToken();
    printf("The input has |%d| chars\n", counterOfChars);
    if(actToken == LEX_ERROR){
        printf("LEX ERROR\n");
        return LEX_ERROR;
    }
    else if(actToken == SUCCESS){
        printf("SUCCESS\n");
    }
    printf("*****  LEX ENDS  *****\n");
    return 0;
}