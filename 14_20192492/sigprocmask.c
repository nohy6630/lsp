#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sched.h>

int main()
{
	sigset_t sig_set;
	int count;

	sigemptyset(&sig_set);
	sigaddset(&sig_set,SIGINT);
	sigprocmask(SIG_BLOCK,&sig_set,NULL);

	for(count=3;0<count;count--)
	{
		printf("count %d\n", count);
		sleep(1);
	}

	printf("Ctrl-C에 대한 블록을 해제\n");
	sigprocmask(SIG_UNBLOCK,&sig_set,NULL);//sig_set에 있는 시그널들을 unblock한다.
	printf("count중 Ctrl-C입력하면 이 문장은 출력되지 않음.\n");

	while(1);

	exit(0);
}
