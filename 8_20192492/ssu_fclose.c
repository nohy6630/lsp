#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *fname = "ssu_test.txt";
	FILE *fp;

	if ((fp = fopen(fname, "r")) == NULL) // ssu_test.txt의 파일스트림을 가져온다.
	{
		fprintf(stderr, "fopen error for %s\n", fname);
		exit(1);
	}
	else
	{
		printf("Success!\n");
		printf("Opening \"%s\" in \"r\" mode!\n", fname);
	}
	fclose(fp); // 열린 파일을 닫는다.
	exit(0);
}
