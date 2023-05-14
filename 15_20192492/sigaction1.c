#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ssu_signal_handler(int signo)
{
	printf("ssu_signal_handler control\n");
}

int main()
{
	struct sigaction sig_act;
	sigset_t sig_set;

	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags=0;
	sig_act.sa_handler=ssu_signal_handler;//핸들러 함수 설정
	sigaction(SIGUSR1,&sig_act,NULL);//SIGUSR1시그널이 발생하면 sig_act가 동작되게 설정
	printf("before first kill()\n");
	kill(getpid(), SIGUSR1);
	sigemptyset(&sig_set);
	sigaddset(&sig_set,SIGUSR1);
	sigprocmask(SIG_SETMASK,&sig_set,NULL);//SIG_SETMASK플래그를 블록
	printf("before second kill()\n");
	kill(getpid(), SIGUSR1);
	printf("after second kill()\n");
	exit(0);
}
