#include <stdio.h>

int main() {
    char str[100];
    int v = 0, c = 0, d = 0, s = 0, i;

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9')
            d++;
        else if(str[i] == ' ')
            s++;
        else if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
                str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            v++;
        else
            c++;
    }

    printf("Vowels=%d\nConsonants=%d\nDigits=%d\nSpaces=%d", v, c, d, s);
    return 0;
}

