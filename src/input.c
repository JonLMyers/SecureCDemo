#include <stdio.h>
#include <stdlib.h>
#include "cardholder.h"
#include "cardnumber.h"
#include "exprdate.h"
#include "amount.h"
#include "zip.h"
#include "email.h"

int main()
{
    printf("############################################\n");
    printf("# Welcome to the Stratux Payment Processor #\n");
    printf("############################################\n\n");

    char* name = getName();
    char* card = getCreditCard();
    char* expiration = getExprDate();
    char* zip = getZip();
    char* amount = getAmount();
    char* email = getEmail();
    printf("\n##################OUTPUT#################\n\n");

    printf("Name: %s", name);
    printf("Credit Card: %s", card);
    printf("Expiration Date: %s\n", expiration);
    printf("Zip Code: %s", zip);
    printf("Purchase Amount: %s", amount);
    printf("Email Address: %s", email);

    free(name);
    free(card);
    free(expiration);
    free(zip);
    free(amount);
    free(email);
    return 0;
}
