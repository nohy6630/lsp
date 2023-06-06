#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

#define MODE_EXEC (S_IXUSR|S_IXGRP|S_IXOTH)

int main(int argc, char *argv[])
{
	struct stat statbuf;
	int i;

	for(int i=1;i<argc;i++)
	{
		if(stat(argv[1], &statbuf) < 0)
		{
			fprintf(stderr, "error\n");
			continue;
		}
		statbuf.st_mode |= MODE_EXEC;
		statbuf.st_mode ^= (S_IXGRP|S_IXOTH);
		chmod(argv[i], statbuf.st_mode);
	}
	exit(0);

}
