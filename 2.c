#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{

    FILE *f = fopen("2.txt", "r");
    char buffer[1002][1002];
    char *token;
    char *token1;
    int token1_int;
    char c; int i = 0; int j = 0;
    int x = 0; int depth = 0;

    while ((c = getc(f)) != EOF) {
        if (c == '\n') {
            i = 0;
            j++;
        } else {
            buffer[j][i++] = c;
        }
    }


    i = 0;
    for (i; i < 1000; i++) {

        /* Tokenize `Direction` and `Value` */
        token = strtok((char*)buffer[i], " ");
        token1 = strtok(NULL, " ");

        /* convert second token to int */
        sscanf(token1, "%d", &token1_int);

        /* Compute values */
        x += strcmp(token, "forward") == 0 ? token1_int : 0;

        depth += strcmp(token, "up") == 0 ? token1_int : 0;

        depth -= strcmp(token, "down") == 0 ? token1_int : 0;
    }

    printf("The result is %d\n", result * -depth);

    return 0;
}
