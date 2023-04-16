#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *fname = "ssu_test.txt";
    FILE *fp;
    long position;
    int character;

    if ((fp = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr, "fopen error for %s\n", fname);
        exit(1);
    }
    printf("Input number »");
    scanf("%ld", &position);
    fseek(fp, position - 1, SEEK_SET);//입력받은 위치로 파일 포인터 위치 변경
    character = getc(fp);
    printf("%ldth character =〉 %c\n", position, character);
    exit(0);
}