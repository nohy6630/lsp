#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *fname = "ssu_test.txt";
    FILE *fp;
    long fsize;

    if ((fp = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr, "fopen error for %s\n", fname);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);//파일끝으로 파일 포인터 위치를 변경
    fsize = ftell(fp);//현재 파일포인터의 위치를 가져옴
    printf("The size of <%s> is %ld bytes\n", fname, fsize);
    exit(0);
}