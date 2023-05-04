#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_signal_handler(int signo);

void (*ssu_func)(int);

int main()
{
	ssu_func=signal(SIGINT, ssu_signal_handler);//인터럽트에 대한 시그널핸들러로 ssu_signal_handler를 등록

	while(1)
	{
		printf("process running...\n");
		sleep(1);
	}
	exit(0);
}

void ssu_signal_handler(int signo)
{
	printf("SIGINT 시그널 발생.\n");
	printf("SIGINT를 SIG_DFL로 재설정 함.\n");
	signal(SIGINT, ssu_func);//인터럽트에 대한 시그널핸들러로 정의되지 않은 함수, 즉 NULL을 등록하여 인터럽트가 발생하면 디폴트 액션이 실행되게함
}
