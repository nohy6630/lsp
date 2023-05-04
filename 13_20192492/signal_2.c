#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

static void ssu_signal_handler(int signo);

int main()
{
	if(signal(SIGINT,ssu_signal_handler)==SIG_ERR)//SIGINT에 대한 시그널핸들러 등록
	{
		fprintf(stderr, "cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGTERM,ssu_signal_handler)==SIG_ERR)//SIGTERM에 대한 시그널핸들러 등록
	{
		fprintf(stderr, "cannot handle SIGTERM\n");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGPROF,SIG_DFL)==SIG_ERR)//SIGPROF 시그널이 발생하면 기본액션이 실행되도록 설정
	{
		fprintf(stderr, "cannot reset SIGPROF\n");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGHUP,SIG_IGN)==SIG_ERR)//SIGHUP 시그널이 발생하면 무시하도록 설정
	{
		fprintf(stderr, "cannot ignore SIGHUP\n");
		exit(EXIT_FAILURE);
	}

	while(1)
		pause();//시그널을 받을 때까지 대기

	exit(0);
}

static void ssu_signal_handler(int signo)
{
	if(signo==SIGINT)
		printf("caught SIGINT\n");
	else if(signo==SIGTERM)
		printf("caught SIGTERM\n");
	else
	{
		fprintf(stderr, "unexpected signal\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_FAILURE);
}
