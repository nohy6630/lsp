#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if (chdir("/etc")<0)// /etc로 프로세스의 작업디렉토리를 변경한다.
	{
		fprintf(stderr, "chdir error\n");
		exit(1);
	}
	printf("chdir to /etc succeeded.\n");
	exit(0);
}
