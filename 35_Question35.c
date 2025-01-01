#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to check whether a number is prime
int isPrime(int n) {
    int notPrime = 0;
    if (n<=1)
        return notPrime;
    else {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0)
                return notPrime;
        }
        return 1;
    }
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to generate Fibonacci series up to n terms
void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to check if a number is Armstrong
int isArmstrong(int n) {
    int sum = 0, temp, remainder, digits = 0;
    temp = n;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }
    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        int power = 1;
        for (int i = 1; i <= digits; i++) {
            power *= remainder;
        }
        sum += power;
        temp /= 10;
    }
    return sum == n;
}

// Function to check if a number is Neon
int isNeon(int n) {
    int sum = 0;
    int square = n * n;
    while (square != 0) {
        sum += square % 10;
        square /= 10;
    }
    return sum == n;
}

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end])
            return 0;  // Not a palindrome
        start++;
        end--;
    }
    return 1;  // Palindrome
}

int main() {
    int choice, num, n;
    float temperature, result;
    char str[100];

    do {
        printf("\nMenu:\n");
        printf("1. Check if a number is prime\n");
        printf("2. Convert temperature (Fahrenheit to Celsius)\n");
        printf("3. Convert temperature (Celsius to Fahrenheit)\n");
        printf("4. Calculate factorial (using recursion)\n");
        printf("5. Generate Fibonacci series up to n terms\n");
        printf("6. Check if a number is Armstrong\n");
        printf("7. Check if a number is Neon\n");
        printf("8. Check if a string is palindrome\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPrime(num))
                    printf("%d is a prime number.\n", num);
                else
                    printf("%d is not a prime number.\n", num);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, result);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, result);
                break;

            case 4:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %d\n", num, factorial(num));
                break;

            case 5:
                printf("Enter the number of terms in Fibonacci series: ");
                scanf("%d", &n);
                fibonacci(n);
                break;

            case 6:
                printf("Enter a number to check if it's Armstrong: ");
                scanf("%d", &num);
                if (isArmstrong(num))
                    printf("%d is an Armstrong number.\n", num);
                else
                    printf("%d is not an Armstrong number.\n", num);
                break;

            case 7:
                printf("Enter a number to check if it's Neon: ");
                scanf("%d", &num);
                if (isNeon(num))
                    printf("%d is a Neon number.\n", num);
                else
                    printf("%d is not a Neon number.\n", num);
                break;

            case 8:
                printf("Enter a string to check if it's palindrome: ");
                getchar();  // To consume the newline character left by previous input
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  // Remove newline character
                if (isPalindrome(str))
                    printf("\"%s\" is a palindrome.\n", str);
                else
                    printf("\"%s\" is not a palindrome.\n", str);
                break;

            case 9:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
