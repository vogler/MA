#include <stdio.h>

FILE *fp;

int main(){
    int c;
    FILE *fp;
    fp = fopen("test.txt", "w");
    // if (fp) {
        while ((c = getc(fp)) != EOF)
            putchar(c);
        fclose(fp);
    // }
}
