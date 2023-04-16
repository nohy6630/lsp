#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char buf[BUFFER_SIZE];
    FILE *fp;
    int len = 0;

    if (argc != 2)
    {
        fprintf(stderr, "usage %s <file> \n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "w+")) == NULL)
    {
        fprintf(stderr, "fopen error for %s\n", argv[1]);
        exit(1);
    }

    fputs("Input String >> ", stdout);
    fgets(buf, sizeof(buf), stdin);
    while(buf[len])
	    len++;
    buf[len-1]=0;//교재와 달리 gets말고 fgets를 쓰면 개행까지 버퍼에 입력되기 때문에 개행문자를 없애준다.
    fputs(buf, fp);//파일에 buf 문자열 내용을 쓴다
    rewind(fp);//파일 포인터를 파일의 맨 터음으로 이동
    fgets(buf, sizeof(buf), fp);
    puts(buf);
    fclose(fp);
    exit(0);
}
