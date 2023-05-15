#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>

static void ssu_func(int signo);
void ssu_print_mask(const char *str);

int main()
{
	sigset_t new_mask, old_mask, wait_mask;
	ssu_print_mask("program start: ");

	if(signal(SIGINT, ssu_func)==SIG_ERR)
	{
		fprintf(stderr, "signal(SIGINT) error\n");
		exit(1);
	}

	sigemptyset(&wait_mask);
	sigaddset(&wait_mask, SIGUSR1);
	sigemptyset(&new_mask);
	sigaddset(&new_mask, SIGINT);

	if(sigprocmask(SIG_BLOCK,&new_mask,&old_mask)<0)//SIGINT를 block
	{
		fprintf(stderr, "sigsuspend() error\n");
		exit(1);
	}

	ssu_print_mask("in critical region: ");

	if(sigsuspend(&wait_mask)!=-1)
	{
		fprintf(stderr, "sigsuspend() error\n");
		exit(1);
	}

	ssu_print_mask("after return from sigsuspend: ");

	if(sigprocmask(SIG_SETMASK, &old_mask, NULL)<0)
	{
		fprintf(stderr, "SIG_SETMASK() error\n");
		exit(1);
	}

	ssu_print_mask("program exit: ");
	exit(1);
}


void ssu_print_mask(const char *str)
{
	sigset_t sig_set;
	int err_num;

	err_num=errno;

	if(sigprocmask(0,NULL,&sig_set)<0)//block된 시그널 가져오기,두번째인자가 NULL이면 sigset_t값은 변경안됨
	{
		fprintf(stderr, "sigprocmask() error\n");
		exit(1);
	}

	printf("%s", str);

	if(sigismember(&sig_set, SIGINT))
		printf("SIGINT ");

	if(sigismember(&sig_set, SIGQUIT))
		printf("SIGQUIT ");

	if(sigismember(&sig_set, SIGUSR1))
		printf("SIGUSR1 ");

	if(sigismember(&sig_set, SIGALRM))
		printf("SIGALRM ");

	printf("\n");
	errno=err_num;
}

static void ssu_func(int signo)
{
	ssu_print_mask("\nin ssu_func: ");
}
