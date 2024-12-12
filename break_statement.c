#include <stdio.h>

int main() {
    char operator;
    int num1, num2;
    int keepGoing = 1;

    while (keepGoing) {
        printf("\nEnter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        switch (operator) { //-----------------------------------------------------------------------
            case '+':
                printf(" %d +  %d =  %d\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf(" %d -  %d =  %d\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf(" %d *  %d =  %d\n", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 != 0) {
                    printf(" %d /  %d =  %d\n", num1, num2, num1 / num2);
                } else {
                    printf("Error! Division by zero.\n");
                }
                break;
            default:
                printf("Invalid operator! Please use from the above given ones.\n");
                break;
        }

        
    }

    
    return 0;
}
