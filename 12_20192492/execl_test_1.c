#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	extern char **environ;//현재 환경변수들을 가리키는 배열
	char **str;
	int i;

	for(i=0;i<argc;i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	for(str=environ;*str!=0;str++)//environ이차원 배열을 돌면서 현재 환경변수들을 출력
		printf("%s\n", *str);

	exit(0);
}
