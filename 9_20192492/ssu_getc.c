#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int character;

    while ((character = getc(stdin)) != EOF)//한글자씩 입력
    {
        if (putc(character, stdout) == EOF)//한글자씩 출력
        {
            fprintf(stderr, "standard output error\n");
            exit(1);
        }
    }
    if (ferror(stdin))
    {
        fprintf(stderr, "standard input error\n");
        exit(1);
    }
    exit(0);
}