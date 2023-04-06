#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_MAX 1024

int main()
{
	char *pathname;

	if (chdir("/home/yenoh")<0)//작업디렉토리를 변경
	{
		fprintf(stderr, "chdir error\n");
		exit(1);
	}
	pathname = malloc(PATH_MAX);
	if (getcwd(pathname, PATH_MAX) == NULL)//프로세스의 현재 작업경로를 pathname에 저장
	{
		fprintf(stderr, "getcwd error\n");
		exit(1);
	}
	printf("current directory = %s\n", pathname);
	exit(0);
}
