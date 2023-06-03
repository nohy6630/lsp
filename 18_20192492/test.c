#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd=open("exec_copy.txt", O_CREAT);
	getchar();
	return 0;	
}
