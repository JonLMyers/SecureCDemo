#include "amount.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getAmount(void) {
    printf("Enter purchase amount: ");
    char* amount = InputHandler();
    checkNullity(amount);
    
    int len = strlen(amount);
    printf("amount len %i \n",len);
    printf("amount len %s \n",amount);
    unsigned int period = 0;
    for (int i=0;i<len;i++) {
        
        printf("index: %i \n", i);
        if(i == 0 && amount[i] == '$'){
            continue;
        }
        
        if(i == 0 && amount[i] != '$'){
            printf("Invalid imput: Please start amount with $ \n");
            exit(4);
        }

        if(amount[i] == '.') {
            period++;
            continue;
        }
        if(period > 1) {
            printf("Invalid imput: Please use no more than 1 \".\"\n");
            exit(5);
        }
        if (i == len-1 && amount[i] == '\n') {
            printf("got nl");
            continue;
        }
        //if((i > 0) && (i != len-2) && (i != len) && !isdigit(amount[i])) {
        if(!isdigit(amount[i])) {
            if( !(i == len-1 && amount[i] == '\n')) {
                printf("Got here");
                printf("You have entered invalid input.\n");
                printf("Please enter amount in format $120.00\n");
                free(amount);
                exit(6);
            }
        }
    }
    return amount;
}
