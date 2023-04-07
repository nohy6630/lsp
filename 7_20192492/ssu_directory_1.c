#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define DIRECTORY_SIZE MAXNAMLEN // 파일이름의 최대길이를 나타내는 상수

int main(int argc, char *argv[])
{
	struct dirent *dentry;
	struct stat statbuf;
	char filename[DIRECTORY_SIZE + 1];
	DIR *dirp;

	if (argc < 2)
	{
		fprintf(stderr, "usage: %s <directory>\n", argv[0]);
		exit(1);
	}

	if ((dirp = opendir(argv[1])) == NULL || chdir(argv[1]) == -1)
	// 디렉토리 스트림을 받아오고 작업디렉토리를 전환함.
	{
		fprintf(stderr, "opendir, chdir error for %s\n", argv[1]);
		exit(1);
	}

	while ((dentry = readdir(dirp)) != NULL)
	// 디렉토리 스트림으로부터 디렉토리 내 파일정보를 받아옴.
	{
		if (dentry->d_ino == 0) // inode가 0인경우는 파일이 존재하지 않는 경우
			continue;

		memcpy(filename, dentry->d_name, DIRECTORY_SIZE); // 파일이름 가져옴

		if (stat(filename, &statbuf) == -1)
		{
			fprintf(stderr, "stat error for %s\n", filename);
			break;
		}

		if ((statbuf.st_mode & S_IFMT) == S_IFREG)
			printf("%-14s %ld\n", filename, statbuf.st_size);
		else
			printf("%-14s\n", filename);
	}
	exit(0);
}
