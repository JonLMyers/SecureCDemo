#include "email.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>

void usage(void) {
    printf("Bad input: Please enter a vaild email address. \n");
    printf("Please use the format: student@rit.edu \n");
}

char* getEmail(void) {
    printf("Enter a valid email: ");
    char* email = InputHandler();
    unsigned int len = strlen(email);
    
    // No email can be shorter than 3 chars
    if(len < 4) {
        printf("Invalid Input: Email length of %i is too short\n", len);
        usage();
        exit(12);
    }
    int numAmp = 0;
    int numPer = 0; 
    // iterate down string and check chars
    for(unsigned int i=0;i<len;i++) {
        //printf("index: %i \n", i);
        // Handle '.' 
        if(email[i] == '.') {
            if(numAmp == 0) {
                continue; }
            if(numAmp == 1) {
                numPer++;
                continue; }
        }
        // do not allow more than 2 periods after the @  
        if(numPer == 2) {
            printf("Invalid input: Cannot have 2 periods after '@' symbol\n");
            usage();
            exit(12);
        }
        // Handle the @ symbol, allow only 1  
        if(email[i] == '@') {
            if (numAmp == 0) {
                //printf("got @ \n");
                numAmp++;
                continue;
            }
            else {
                printf("Invalid Input: Please use only 1 '@' \n");
                exit(7);
            }
        }
        //Allow a trailing newline
        if(i == len-1 && email[i] =='\n') {
            continue;
        }
        // Check if character is Alpha/Numeric
        if(!isdigit(email[i])) {
            //printf("got notdigit\n");
            if (!isalpha(email[i])) {
                //printf("not alpha/digit \n");
                usage();
                free(email);
                exit(10);
            }
        }
    }
    // Check if email ends with "@" or "." characters
    if((email[len-2] == '@') || (email[len-2] == '.')) {
        printf("Email address cannot end with '@' or '.' symbols \n");
        usage();
        exit(9);
    }
    // Check if email starts with "@" or "." 
    if((email[0] == '@') || (email[0] == '.')) {
        printf("Email address cannot start with '@' or '.' symbols \n");
        usage();
        exit(13);
    }
    // Ensures only 1 "@" 
    if(numAmp != 1) {
        printf("Invalid Input: Please use only 1 '@' \n");
        usage();
        exit(11);
    }
    // Validates for a single "." after "@" char
    if(numPer != 1) {
        printf("Invalid Input: Must have 1 '.' after @ symbol\n");
        usage();
        exit(14);
    }

return email;
}
