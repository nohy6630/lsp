#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#define LINE_MAX 2048

static void ssu_alarm(int signo);

int main()
{
	char buf[LINE_MAX];
	int n;

	if(signal(SIGALRM, ssu_alarm)==SIG_ERR)//SIGALRM 시그널에 대한 시그널핸들러로 ssu_alarm을 등록
	{
		fprintf(stderr, "SIGALRM error\n");
		exit(1);
	}

	alarm(10);//10 초후에 SIGALRM 시그널이 발생하도록 설정

	if((n=read(STDIN_FILENO,buf,LINE_MAX))<0)
	{
		fprintf(stderr, "read() error\n");
		exit(1);
	}

	alarm(0);//설정되있는 알람을 해제
	write(STDOUT_FILENO,buf,n);
	exit(0);
}

static void ssu_alarm(int signo)
{
	printf("ssu_alarm() called!\n");
}
