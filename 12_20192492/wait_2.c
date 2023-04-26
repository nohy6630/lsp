#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define EXIT_CODE 1

int main()
{
	pid_t pid;
	int ret_val, status;

	if((pid = fork())==0)
	{
		printf("child: pid = %d ppid = %d exit_code = %d\n", getpid(), getppid(), EXIT_CODE);
		exit(EXIT_CODE);
	}

	printf("parent: waiting for child = %d\n", pid);
	ret_val = wait(&status);//ret_vald의 자식프로세스의 pid를 저장하고 status에는 자식프로세스의 종료상태를 저장
	printf("parent: return value = %d, ", ret_val);
	printf(" child's status = %x", status);
	printf(" add shifted = %x\n", (status>>8));//비트연산자를 이용해 자식프로세스 exit의 인자 값을 출력한다.
	exit(0);
}
