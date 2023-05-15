#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	sigset_t old_set;
	sigset_t sig_set;

	sigemptyset(&sig_set);
	sigaddset(&sig_set, SIGINT);
	sigprocmask(SIG_BLOCK, &sig_set, &old_set);
	sigsuspend(&old_set);//old_set에 있는 시그널을 제외한 시그널이 들어오면 대기중인 sigsuspend가 리턴되고 이후 코드가 진행됨. 
	exit(0);
}
