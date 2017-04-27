#include "cardnumber.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getCreditCard(void)
{
    printf("Credit Card: ");
    char* card = InputHandler();
    checkNullity(card);

    int length = 20;

    for(int i = 0; i < length; i++)
    {
        if(i == 4 || i == 9 || i == 14) 
        {
            if(card[i] != '-') {
                printf("Your credit card information is not in the correct format.\n");
                printf("Example: 1234-1234-1234-1234\n");
                free(card);
                exit(3);
            }
        }
        else 
        {
            if(!isdigit(card[i])) 
            {
                if( !(i == length-1 && card[i] == '\n')) 
                {
                    printf("Your credit card contains invalid digits.\n");
                    printf("Example: 1234-1234-1234-1234\n");
                    free(card);
                    exit(4);
                }
            }
        }
    }

    return card;
}