#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char operator;
    FILE *fp;
    int character;
    int number = 0;

    if ((fp = fopen("ssu_expr.txt", "r")) == NULL)
    {
        fprintf(stderr, "fopen error for ssu_expr.txt\n");
        exit(1);
    }
    while (!feof(fp))//파일 끝에 도달할때 까지 반복
    {
        while ((character = fgetc(fp)) != EOF && isdigit(character))
            number = 10 * number + character - 48;
        fprintf(stdout, " %d\n", number);
        number = 0;
        if (character != EOF)
        {
            ungetc(character, fp);//읽은 문자를 다시 버퍼에 되돌려놓음
            operator= fgetc(fp);//버퍼에 돌려놓은 연산자 문자를 다시 읽음
            printf("Operator =〉 %c\n", operator);
        }
    }
    fclose(fp);
    exit(0);
}