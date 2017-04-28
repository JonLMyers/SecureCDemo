#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkNullity(char *object)
{
    if(object == NULL || 0 == strcmp(object, "\n")){
        printf("Invalid input. Please enter non void values.\n");
        free(object);
        exit(1);
    }
    return 0;
}

char* InputHandler(void)
{
    char* buffer = (char*)malloc(256);
    int i;
    if (fgets(buffer, 256, stdin)) {
        if (1 == sscanf(buffer, "%d", &i)) 
        {
            //MEh use I if needed            
        }
    }
    return buffer;
}
