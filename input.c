#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkNullity(char *object)
{
    if(object == NULL){
        printf("Invalid input. Please enter non void values.");
        exit(1);
    }
    return 1;
}

char *InputHandler(void)
{
    char buffer[256];
    int i;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        if (1 == sscanf(buffer, "%d", &i)) {
            //MEh use I if needed            
        }
    }
    char *input = buffer;
    return input;
}

char *getName(void)
{
    printf("Name: ");
    char *name = InputHandler();
    checkNullity(name);


    return name;
}

char *getCreditCard(void)
{
    printf("Credit Card: ");
    char *card = InputHandler();
    checkNullity(card);

    unsigned int length = strlen(card);
    if(length != 20) {
        printf("Your credit card information is incorrect. Not 20 chars.\n");
        printf("Example Format: 1111-2222-3333-4444\n");
        exit(2);
    }
    for(unsigned int i = 0; i < length; i++){
        if(i == 4 || i == 9 || i == 14) {
            if(card[i] != '-') {
                printf("Your credit card information is incorrect. Lacking -\n");
                printf("Example Format: 1111-2222-3333-4444\n");
                exit(2);
            }
        }
    }
    return card;
}

int main()
{
    printf("############################################\n");
    printf("# Welcome to the Stratux Payment Processor #\n");
    printf("############################################\n\n");

    char *name = getName();
    //char *card = getCreditCard();

    printf("Name: %s\n", name);
    //printf("Credit Card: %s\n", card);
    return 0;
}
