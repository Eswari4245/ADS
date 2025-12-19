#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void display(struct Student s) {
    printf("\nID: %d", s.id);
    printf("\nName: %s", s.name);
    printf("\nMarks: %.2f\n", s.marks);
}

int main() {
    struct Student s1 = {101, "Rahul", 87.5};
    display(s1);
    return 0;
}

