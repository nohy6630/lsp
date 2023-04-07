#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *fname = "ssu_test.txt";
	char *mode = "r";

	if (fopen(fname, mode) == NULL) // ssu_test.txt의 파일스트림을 읽기모드로 가져온다
	{
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}
	else
		printf("Success!\nFilename: <%s>, mode: <%s>\n", fname, mode);
	exit(0);
}
