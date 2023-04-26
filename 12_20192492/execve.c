#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *argv[]={
		"execl_test_1", "param1", "param2", (char *)0
	};

	char *env[]={
		"NAME = value",
		"nextname=nextvalue",
		"HOME=/home/oslab",
		(char *)0
	};

	printf("this is the original program\n");
	execve("./execl_test_1", argv, env);//execl_test_1을 실행하고 그 프로세스에서 사용할 환경변수들을이 저장된 env배열도 전달한다.
	printf("%s\n", "This line should never get printed\n");
	exit(0);
}
