#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

#define MAX_PATH_GUESSED 1024

#ifndef LINE_MAX
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

	if (lstat(pathname, &statbuf) < 0)
	{
		fprintf(stderr, "lstat error for %s\n", pathname);
		return 0;
	}

	if (S_ISDIR(statbuf.st_mode) == 0)
	{
		sprintf(command, "%s %s", grep_cmd, pathname);
		printf("%s: \n", pathname);
		system(command);
		return 0;
	}

	ptr = pathname + strlen(pathname);
	*ptr++ = '/';
	*ptr = '\0';

	if ((dp = opendir(pathname)) == NULL)
	{
		fprintf(stderr, "opendir error for %s\n", pathname);
		return 0;
	}

	while ((dirp = readdir(dp)) !=NULL
}
