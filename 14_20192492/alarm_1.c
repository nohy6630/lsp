#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ssu_signal_handler(int signo);

int count = 0;

int main()
{
	signal(SIGALRM, ssu_signal_handler);//SIGALRM에 대한 시그널핸들러로 ssu_sigal_handler를 등록
	alarm(1);//1초 후에 SIGALRM 시그널이 발생하도록 설정
	while(1);
	exit(0);
}

void ssu_signal_handler(int signo)
{
	printf("alarm %d\n", count++);
	alarm(1);//1초 후에 다시 SIGALRM 시그널이 발생하도록 설정
}
