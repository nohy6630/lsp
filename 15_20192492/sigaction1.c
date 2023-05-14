#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ssu_signal_handler(int signo)
{
	printf("ssu_signal)handler control\n");
}

int main()
{
	struct sigaction sig_act;
	sigset_t sig_set;

	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags=0;
	sig_act.sa_handler=ssu_signal_handler;
	sigaction(SIGUSR1,&sig_act,NULL);
	printf("before first kill()\n");
	kill(getpid(), SIGUSR1);
	sigemptyset(&sig_set);
	sigaddset(&sig_set,SIGUSR1);
	sigprocmask(SIG_SETMASK,&sig_set,NULL);
	printf("bbefore second kill()\n");
	kill(getpid(), SIGUSR1);
	printf("after second kill()\n");
	exit(0);
}
