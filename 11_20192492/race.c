#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void ssu_charatatime(char *str);

int main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid==0)//자식프로세스
		ssu_charatatime("output from child\n");
	else//부모프로세스
		ssu_charatatime("output from parent\n");
	exit(0);
}

static void ssu_charatatime(char *str)
{
	char *ptr;
	int print_char;
	setbuf(stdout, NULL);
	for(ptr=str;(print_char=*ptr++)!=0;)
	{
		putc(print_char, stdout);//한글자씩 표준출력
		usleep(10);
	}
}

