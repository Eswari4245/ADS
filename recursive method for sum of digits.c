#include <stdio.h>

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0;   // Base case
    return (n % 10) + sumOfDigits(n / 10); // Recursive call
}

int main() {
    int num = 1234;
    printf("Sum of digits of %d = %d\n", num, sumOfDigits(num));
    return 0;
}

