#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>

#ifdef PATH_MAX // 파일경로의 최대길이를 의미하는 매크로 상수
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

#define MAX_PATH_GUESSED 1024

#ifndef LINE_MAX // 한 줄의 최대 길이를 나타내는 매크로 상수
#define LINE_MAX 2048
#endif

char *pathname;
char command[LINE_MAX], grep_cmd[LINE_MAX];

int ssu_do_grep()
{
	struct dirent *dirp;
	struct stat statbuf;
	char *ptr;
	DIR *dp;

	if (lstat(pathname, &statbuf) < 0)//파일의 메타데이터를 가져온다.
	{
		fprintf(stderr, "lstat error for %s\n", pathname);
		return 0;
	}

	if (S_ISDIR(statbuf.st_mode) == 0)//파일이 디렉토리가 아니라면
	{
		sprintf(command, "%s %s", grep_cmd, pathname);
		printf("%s: \n", pathname);
		system(command);//grep명령어 실행
		return 0;
	}

	ptr = pathname + strlen(pathname);
	*ptr++ = '/';
	*ptr = '\0';

	if ((dp = opendir(pathname)) == NULL)//디렉토리 스트림을 받아온다.
	{
		fprintf(stderr, "opendir error for %s\n", pathname);
		return 0;
	}

	while ((dirp = readdir(dp)) != NULL)//디렉토리 내 파일 정보를 받아온다.
	{
		if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
		{
			strcpy(ptr, dirp->d_name);//파일이름을 path_name뒤에 붙여준다.
			if (ssu_do_grep() < 0)
				break;
		}
	}
	ptr[-1] = 0;
	closedir(dp);//디렉토리 스트림을 닫는다.
	return 0;
}

void ssu_make_grep(int argc, char *argv[])
{
	int i;
	strcpy(grep_cmd, "grep");

	for (i = 1; i < argc - 1; i++)
	{
		strcat(grep_cmd, " ");
		strcat(grep_cmd, argv[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "usage: %s <-CVbchilnsvwx> <-num> <-A num> <-B num> <-f file> <-e> expr <directory>\n", argv[0]);
		exit(1);
	}
	if (pathmax == 0)
	{
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
			pathmax = MAX_PATH_GUESSED;
		else
			pathmax++;
	}

	if ((pathname = (char *)malloc(pathmax + 1)) == NULL)
	{
		fprintf(stderr, "malloc error\n");
		exit(1);
	}

	strcpy(pathname, argv[argc - 1]);
	ssu_make_grep(argc, argv);
	ssu_do_grep();
	exit(0);
}
