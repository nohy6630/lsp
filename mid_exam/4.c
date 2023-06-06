#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

#define NAME_SIZE 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char fname[NAME_SIZE];
	struct stat statbuf;

	printf("Enter your file name: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	lstat(fname, &statbuf);
	printf("File Type: ");
	if(S_ISREG(statbuf.st_mode))
		printf("Regular file\n");
	else if(S_ISDIR(statbuf.st_mode))
		printf("Directory\n");
	else if(S_ISLNK(statbuf.st_mode))
		printf("Symbolic link\n");
	printf("Owner Permission: \n");
	if(statbuf.st_mode & S_IRUSR)
		printf("Read Permission bit set\n");
	if(statbuf.st_mode & S_IWUSR)
		printf("Write Permission bit set\n");
	if(statbuf.st_mode & S_IXUSR)
		printf("Execute Permission bit set\n");
	printf("File Size: ");
	printf("%ld bytes\n", statbuf.st_size);
	printf("Last Modification Time: ");
	printf("%s", ctime(&statbuf.st_mtime));
	fclose(fp);
	exit(0);
}
