#include <stdio.h>
#include <stdlib.h>
#include "cardholder.h"
#include "cardnumber.h"
#include "exprdate.h"

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
