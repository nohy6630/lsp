#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main()
{
	sigset_t set;

	sigemptyset(&set);//시그널 집합 set을 빈 집합으로 초기화시킴
	sigaddset(&set,SIGINT);//set에 SIGINT를 추추가

	switch(sigismember(&set,SIGINT))//set에 SIGINT가 포함되있는지 검사
	{
		case 1:
			printf("SIGINT is included.\n");
			break;
		case 0:
			printf("SIGINT is not included.\n");
			break;
		default:
			printf("failed to call sigismember()\n");
	}

	switch(sigismember(&set, SIGSYS))//set에 SIGSYS가 포함되있는지 검사
	{
		case 1:
			printf("SIGSYS is included.\n");
			break;
		case 0:
			printf("SIGSYS is not included.\n");
			break;
		default:
			printf("failed to call sigismember()\n");
	}

	exit(0);
}
