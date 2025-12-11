#include <stdio.h>

int main() {
    int n, i;
    long long fact = 1;   // factorial grows fast, so long long is used

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } 
    else {
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}

