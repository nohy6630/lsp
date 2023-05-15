#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<syslog.h>
#include<sys/stat.h>
#include<sys/types.h>

int ssu_daemon_init();
int main()
{
	pid_t pid;

	pid=getpid();
	printf("parent process : %d\n",pid);
	printf("daemon process initialization\n");

	if(ssu_daemon_init()<0)
	{
		fprintf(stderr, "ssu_daemon_init failed\n");
		exit(1);
	}
	exit(0);
}

int ssu_daemon_init()
{
	pid_t pid;
	int fd, maxfd;

	if((pid=fork())<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid!=0)
		exit(0);//부모프로세스는 종료

	pid = getpid();
	printf("process %d running as daemon\n",pid);
	setsid();//새로운 세션에서 자식프로세스가 돌아가게 만듬
	signal(SIGTTIN, SIG_IGN);//터미널 입출력 시그널 무시
	signal(SIGTTOU, SIG_IGN);//터미널 입출력 시그널 무시
	signal(SIGTSTP, SIG_IGN);//터미널 입출력 시그널 무시
	maxfd=getdtablesize();

	for(fd=0;fd<maxfd;fd++)
		close(fd);//필요없는 파일디스크립터 닫아주기

	umask(0);
	chdir("/");//작업디렉토리 루트로
	fd=open("/dev/null",O_RDWR);//표준입력디스크립터 지정
	dup(0);//1로 표준출력디스크립터 지정
	dup(0);//2로 표준에러디스크립터 지정
	return 0;
}
