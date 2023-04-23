#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("Process ID		= %d\n", getpid());//pid
	printf("Parent process ID	= %d\n", getppid());//parent pid
	printf("Real user ID		= %d\n", getuid());//uid
	printf("Effective user ID	= %d\n", geteuid());//effective user id
	printf("Real group ID		= %d\n", getgid());//group id
	printf("Effective group ID	= %d\n", getegid());//effective group id
	exit(0);
}
