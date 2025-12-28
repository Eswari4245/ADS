#include <stdio.h>

int main() {
    FILE *f1, *f2, *f3;
    char ch;

    f1 = fopen("file1.txt", "r");
    f2 = fopen("file2.txt", "r");
    f3 = fopen("merge.txt", "w");

    if(f1 == NULL || f2 == NULL) {
        printf("Error opening file");
        return 1;
    }

    while((ch = fgetc(f1)) != EOF)
        fputc(ch, f3);

    while((ch = fgetc(f2)) != EOF)
        fputc(ch, f3);

    printf("Files merged successfully");

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}

