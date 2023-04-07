#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *fname = "ssu_test.txt";
	int fd;

	printf("First printf : Hello, OSLAB!!\n");

	if ((fd = open(fname, O_RDONLY)) < 0)
	{
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	if (freopen(fname, "w", stdout) != NULL) // 표준출력 파일포인터에 읽기모드로 연 ssu_test.txt의 파일스트림을 연결한다.
		printf("Second printf : Hello, OSLAB!!\n");

	exit(0);
}
