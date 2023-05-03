#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ssu_alarm(int signo);

int main()
{
	printf("Alarm Setting\n");
	signal(SIGALRM,ssu_alarm);//SIGALRM 시그널에 대한 시그널핸들러로 ssu_alarm등록
	alarm(2);
	while(1)
	{
		printf("done\n");
		pause();//SIGALRM 시그널이 발생할 때까지 프로세스르 중지
		alarm(2);
	}
	exit(0);
}

void ssu_alarm(int signo)
{
	printf("alarm..!!!\n");
}
