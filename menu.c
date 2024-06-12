#include <stdio.h>
#include <stdlib.h>  // Needed for the exit() function

void addition() {
    int num1, num2;

    printf("Enter two numbers to add:\n");
    scanf("%d %d", &num1, &num2);
    printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
}

void multiplication() {
    int num1, num2;

    printf("Enter two numbers to multiply:\n");
    scanf("%d %d", &num1, &num2);
    printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
}

void exitProgram() {
    char confirmation;
    printf("Are you sure you want to exit? (y/n):\n");
    scanf(" %c", &confirmation);  // Fixed typo: confimation -> confirmation

    if (confirmation == 'Y' || confirmation == 'y') {
        printf("Exiting the program.\n");
        exit(0);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\tMenu:\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");  // Fixed typo: prinrf -> printf
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition();
                break;
            
            case 2:
                multiplication();
                break;
            case 3:
                exitProgram();
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                exit(0);
        }
    }
    return 0;
}

