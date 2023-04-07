#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	char buf[BUFFER_SIZE];

	setbuf(stdout, buf); // 표쥰출력의 버퍼크기를 1024로 지정한다.
	printf("Hello, ");
	sleep(1);
	printf("OSLAB!!");
	sleep(1);
	printf("\n");
	sleep(1);

	setbuf(stdout, NULL); // 표준출력의 버퍼크기를 NULL로 지정하여 버퍼링을 비활성화시킴
	printf("How");
	sleep(1);
	printf(" are");
	sleep(1);
	printf(" you?");
	sleep(1);
	printf("\n");
	exit(0);
}
