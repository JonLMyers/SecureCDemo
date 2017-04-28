#include "zip.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getZip(void) {
    printf("Enter a valid zip code: ");
    char* zip = InputHandler();
    checkNullity(zip);
    int len = strlen(zip);
    
    int numHyph = 0;

    printf("len = %i \n", len);

    if(len != 11) { 
        if(len != 6) {
            printf("Invalid zip length\n");
            free(zip);
            exit(20);
        }
    }
    for (int i=0;i<len;i++) {
        // check char is a hyphen 
        if(len != 6 && zip[i] == '-') {
            numHyph++;
            continue;
        }
        // ensure only 1 hyphen is used
        if(numHyph > 1){
            printf("Invalid Input: only 1 hyphen '-' allowed in Zip Code\n");
            printf("Enter a Zip Code in format \"12345\" or \"12345-6789\"\n");
            free(zip);
            exit(21);
        }
        // allow trailing newline
        if(i == len-1 && zip[i] == '\n') {
            continue;
        }

        // only allow digits 
        if(!isdigit(zip[i])) {
            printf("Invalid Input: Numbers only in Zip Code. \n");
            printf("Enter a Zip Code in format \"12345\" or \"12345-6789\"\n");
            free(zip);
            exit(22);
        }
    
    }
    if((len == 11) && zip[5] != '-') {
        printf("Invalid Input: 10 digit Zip Code missing '-' \n");
        printf("Enter a Zip Code in format \"12345\" or \"12345-6789\"\n");
        free(zip);
        exit(23);
    } 
    return zip;
}
