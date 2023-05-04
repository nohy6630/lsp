#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "usage: %s [Process ID]\n",argv[0]);
		exit(1);
	}
	else
		kill(atoi(argv[1]),SIGKILL);//인자로 넘긴 pid의 프로세스에게 시그널을 발생시켜 종료시킴
	exit(0);
}
