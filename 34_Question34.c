#include <stdio.h>

// Function to add two numbers
void add(float num1, float num2) {
    printf("%.2f + %.2f = %.2f\n",num1,num2, num1 + num2);
}

// Function to subtract two numbers
void subtract(float num1, float num2) {
    printf("%.2f - %.2f = %.2f\n",num1,num2, num1 - num2);
}

// Function to multiply two numbers
void multiply(float num1, float num2) {
    printf("%.2f x %.2f = %.2f\n",num1,num2, num1 * num2);
}

// Function to divide two numbers
void divide(float num1, float num2) {
    if (num2 != 0) {
        printf("%.2f / %.2f = %.2f\n",num1,num2, num1 / num2);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

int main() {
    int choice;
    float num1, num2;

    // Menu-driven system
    do {
        printf("\n********** MENU **********\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check the choice and perform the corresponding operation
        if (choice >= 1 && choice <= 4) {
            printf("Enter 1st number: ");
            scanf("%f", &num1);
            printf("Enter 2nd number: ");
            scanf("%f", &num2);                      
        }

        switch(choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}


