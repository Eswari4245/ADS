#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head=NULL, *temp;
    int x;
    scanf("%d",&x);

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;

    printf("%d", head->data);
    return 0;
}

