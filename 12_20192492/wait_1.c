#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void ssu_echo_exit(int status);

int main()
{
	pid_t pid;
	int status;

	if((pid=fork())<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid == 0)
		exit(7);//자식프로세스 정상 종료
	if(wait(&status)!=pid)
	{
		fprintf(stderr, "wait error\n");
		exit(1);
	}

	ssu_echo_exit(status);

	if((pid=fork())<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid==0)
		abort();//자식 프로세스 비정상 종료시킴

	if(wait(&status)!=pid)
	{
		fprintf(stderr, "wait error\n");
		exit(1);
	}

	ssu_echo_exit(status);

	if((pid=fork())<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid==0)
		status/=0;//0으로 나누어 자식프로세스를 비정상 종료시킴

	if(wait(&status)!=pid)
	{
		fprintf(stderr, "wait error\n");
		exit(1);
	}

	ssu_echo_exit(status);
	exit(0);
}

void ssu_echo_exit(int status)
{
	if(WIFEXITED(status))//자식프로세스가 정상적으로 종료된 경우
	{
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	}
	else if(WIFSIGNALED(status))//자식프로세스가 비정상적으로 종료된 경우
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status)?" (core file generated)":"");
#else
				"");
#endif
	else if(WIFSTOPPED(status))//자식프로세스가 중지상태인 경우
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
