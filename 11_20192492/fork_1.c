#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char glob_str[]="write to statndard output\n";
int glob_val=10;

int main()
{
	pid_t pid;
	int loc_val;
	loc_val=100;
	if(write(1, glob_str, sizeof(glob_str)-1)!=sizeof(glob_str)-1)
	{
		fprintf(stderr, "write error\n");
		exit(1);
	}
	printf("before fork\n");
	if((pid=fork())<0)//자식프로세스 생성
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else if(pid==0)//자식프로세스 일때 변수 값 변경
	{
		glob_val++;
		loc_val++;
	}
	else//부모프로세스 일때
		sleep(3);
	printf("pid = %d, glob_val = %d, loc_val = %d\n", getpid(), glob_val, loc_val);
	exit(0);
}
