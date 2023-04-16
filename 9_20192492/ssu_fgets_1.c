#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char buf[BUFFER_SIZE];

    while (fgets(buf, BUFFER_SIZE, stdin) != NULL)//표준입력스트림으로부터 문자열을 읽음
    {
        if (fputs(buf, stdout) == EOF)//문자열 표준출력
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