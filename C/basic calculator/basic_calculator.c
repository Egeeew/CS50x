#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    string operation = get_string("What do you want to do (+, -, * or /) : \n");
    float x = get_float("What is the first number: ");
    float y = get_float("What is the second number: ");
    if (strncmp(operation, "+", 1) == 0){
        float result = x + y;
        printf("%.2f + %.2f = %.2f\n", x, y, result);
    }
    else if (strncmp(operation, "-", 1) == 0){
        float result = x - y;
        printf("%.2f - %.2f = %.2f\n", x, y, result);
    }
    else if (strncmp(operation, "*", 1) == 0){
        float result = x * y;
        printf("%.2f * %.2f = %.2f\n", x, y, result);
    }
    else if (strncmp(operation, "/", 1) == 0){
        float result = x / y;
        printf("%.2f / %.2f = %.2f\n", x, y, result);
    }
    else {
        printf("You entered a wrong operator (maybe not operator).\n");
    }
}
