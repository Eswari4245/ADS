#include <stdio.h>

int mutex = 1, full = 0, empty = 3, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d\n", x);
    --x;
    ++mutex;
}

int main() {
    int n;
    do {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d", &n);

        if(n == 1 && empty != 0)
            producer();
        else if(n == 2 && full != 0)
            consumer();
        else if(n == 3)
            break;
        else
            printf("Buffer is full or empty!");
    } while(1);

    return 0;
}

