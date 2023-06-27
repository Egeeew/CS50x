#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main()
{
    string card_number;
    int valid = 0;
    int i = 0;
    int luhnMain = 0;
    int luhn = 0;
    int luhn2 = 0;
    int bug = 0;

    // First phase
    printf("Credit card number: ");
    card_number = get_string();

    int len = strlen(card_number);
    char card_number2[100];
    for (int j = 0; j < len; j++)
    {
        card_number2[j] = card_number[len - j - 1];
    }

    while (i < len)
    {
        if ((i + 1) % 2 == 0)
        {
            int doubled = (card_number2[i] - '0') * 2;
            luhn += (doubled / 10) + (doubled % 10);
        }
        else
        {
            luhn2 += card_number2[i] - '0';
        }

        i++;
    }

    // Second phase
    luhnMain = luhn + luhn2;

    // Third phase
    if (luhnMain % 10 == 0)
    {
        // Valid number
        valid = 1;
    }

    // Fourth phase - What type of card?
    if (valid == 1)
    {
        // American Express (AMEX)
        if (len == 15 && (card_number[0] == '3' && (card_number[1] == '4' || card_number[1] == '7')))
        {
            printf("%d %d %d\n", luhn, luhn2, luhnMain); // for debugging
            printf("AMEX\n");
        }
        // Mastercard (MASTERCARD) , Visa (VISA)
        if (len == 13 || len == 16)
        {
            if (card_number[0] == '4')
            {
                printf("%d %d %d\n", luhn, luhn2, luhnMain); // for debugging
                printf("VISA\n");
            }
            else
            {
                printf("%d %d %d\n", luhn, luhn2, luhnMain); // for debugging
                printf("MASTERCARD\n");
            }
        }
    }
    else
    {
        printf("%d %d %d\n", luhn, luhn2, luhnMain); // for debugging
        printf("INVALID\n");
    }

    return 0;
}