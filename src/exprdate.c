#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CURRENT_YEAR 2017
#define CURRENT_MONTH 4
#define CURRENT_DAY 28

char* getExprDate(void)
{
    printf("Expiration Date: ");
    char* expiration = InputHandler();
    checkNullity(expiration);

    int length = 11;
    for(int i = 0; i < length; i++) 
    {
        if(i == 2 || i == 5) 
        {
            if(expiration[i] != '/') 
            {
                printf("Please use '/' between the month, date, and year.\n");
                printf("Example: MM/DD/YYYY.\n");
                free(expiration);
                exit(2);
            }
        } 
        else if(!isdigit(expiration[i]))
        {
            if( !(i == length-1 && expiration[i] == '\n') )
            {
                printf("Your expiration data is invalid.\n");
                printf("Example: MM/DD/YYYY.\n");
                free(expiration);
                exit(3);
            }
        }
    }

    char *buffer;
    int month_digit = (int)strtod(expiration, &buffer);

    char retval[50];

    char day[3];
    day[0] = expiration[3];
    day[1] = expiration[4];
    day[2] = '\0';

    int d = (int)strtod(day, &buffer);
    if(d > 31 || d < 1) 
    {
        printf("Invalid Day. Please enter a valid day 1-31\n");
        free(expiration);
        exit(11);
    }

    char month[3];
    month[0] = expiration[0];
    month[1] = expiration[1];
    month[2] = '\0';
    int m = (int)strtod(month, &buffer);
    if(m > 12 || m < 1) 
    {
        printf("Invalid Month. Please enter a valid month 1-12\n");
        free(expiration);
        exit(12);
    }

    char year[5];
    year[0] = expiration[6];
    year[1] = expiration[7];
    year[2] = expiration[8];
    year[3] = expiration[9];
    year[4] = '\0';

    int y = (int)strtod(year, &buffer);

    /* Ensure valid year. */
    if(y < CURRENT_YEAR) 
    {
        printf("Invalid Date. Card Expired.\n");
        free(expiration);
        exit(13);   
    }
    
    /* Ensure valid month. */
    if(y == CURRENT_YEAR) 
    {
        if(m < CURRENT_MONTH) {
            printf("Invalid Date. Card Expired.\n");
            free(expiration);
            exit(14);  
        }

        if(m == CURRENT_MONTH) 
        {
            if(d < CURRENT_DAY) 
            {
                printf("Invalid Date. Card Expired.\n");
                free(expiration);
                exit(15);
            }
        }
    }

    switch((int)month_digit) 
    {

        case 1  :
            sprintf(retval, "January %d", (int)strtod(day, &buffer));
            break;
        case 2  :
            sprintf(retval, "February %d", (int)strtod(day, &buffer));
            break;
        case 3  :
            sprintf(retval, "March %d", (int)strtod(day, &buffer));
        case 4  :
            break;
            sprintf(retval, "April %d", (int)strtod(day, &buffer));
        case 5  :
            sprintf(retval, "May %d", (int)strtod(day, &buffer));
            break;
        case 6  :
            sprintf(retval, "June %d", (int)strtod(day, &buffer));
            break;
        case 7  :
            sprintf(retval, "July %d", (int)strtod(day, &buffer));
            break;
        case 8  :
            sprintf(retval, "August %d", (int)strtod(day, &buffer));
            break;
        case 9  :
            sprintf(retval, "September %d", (int)strtod(day, &buffer));
            break;
        case 10  :
            sprintf(retval, "October %d", (int)strtod(day, &buffer));
            break;
        case 11  :
            sprintf(retval, "November %d", (int)strtod(day, &buffer));
            break;
        case 12  :
            sprintf(retval, "December %d", (int)strtod(day, &buffer));
            break;
        
        default :
                printf("You have entered an invalid month.\n");
                printf("Please use the format MM/DD/YYYY.\n");
                free(expiration);
                exit(12);
    }

    free(expiration);

    expiration = (char *)calloc(1, strlen(retval)+1);
    strncpy(expiration, retval, strlen(retval)+1);

    return expiration;
}
