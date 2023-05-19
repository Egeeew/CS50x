#include <cs50.h>
#include <stdio.h>

int main(void){
    printf("Program is running.\n");
    while (true){
        int num = get_int("Write a number (0 stands for escape): \n");
        if (num < 50){
            if (num == 0){
                printf("Program cutting off...\n");
                break;
            }
            else{
                printf("The number is smaller than 50!\n");
                continue;
            }
        }
        else if (num > 50){
            printf("The number is greater than 50!\n");
        }
        
        else {
            printf("The number equals to 50!\n");
        }
    }
    printf("Program ended successfully.\n");
}
