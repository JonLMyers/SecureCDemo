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
        if (1 == sscanf(buffer, "%d", &i)) {
            //MEh use I if needed            
        }
    }
    return buffer;
}

char* getName(void)
{
    printf("Name: ");
    char* name = InputHandler();
    checkNullity(name);

    return name;
}

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

int main()
{
    printf("############################################\n");
    printf("# Welcome to the Stratux Payment Processor #\n");
    printf("############################################\n\n");

    char* name = getName();
    char* card = getCreditCard();
    char* expiration = getExprDate();
    printf("\n##################OUTPUT#################\n\n");

    printf("Name: %s", name);
    printf("Credit Card: %s", card);
    printf("Expiration Date: %s", expiration);

    free(name);
    free(card);
    free(expiration);
    return 0;
}
