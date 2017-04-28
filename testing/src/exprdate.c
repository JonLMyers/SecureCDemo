#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getExprDate(void)
{
    printf("Expiration Date: ");
    char* expiration = InputHandler();
    checkNullity(expiration);

    int length = 11;
    for(int i = 0; i < length; i++) {
        if(i == 2 || i == 5) {
            if(expiration[i] != '/') {
                printf("Please use '/' between the month, date, and year.\n");
                printf("Example: MM/DD/YYYY.\n");
                free(expiration);
                exit(2);
            }
        } else if(!isdigit(expiration[i])){
            if( !(i == length-1 && expiration[i] == '\n') ) {
                printf("Your expiration data is invalid.\n");
                printf("Example: MM/DD/YYYY.\n");
                free(expiration);
                exit(3);
            }
        }
    }
    return expiration;
}
