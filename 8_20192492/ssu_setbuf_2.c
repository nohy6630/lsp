#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
	char buf[BUFFER_SIZE];
	int a, b;
	int i;

	setbuf(stdin, buf); // 표준입력의 버퍼를 buf로 지정한다.
	scanf("%d %d", &a, &b);

	for (i = 0; buf[i] != '\n'; i++)
		putchar(buf[i]);
	putchar('\n');
	exit(0);
}
