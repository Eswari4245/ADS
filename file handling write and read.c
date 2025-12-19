#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("data.txt", "w");
    fprintf(fp, "C programming is powerful.");
    fclose(fp);

    fp = fopen("data.txt", "r");
    fgets(text, 100, fp);
    printf("File content: %s", text);
    fclose(fp);

    return 0;
}

