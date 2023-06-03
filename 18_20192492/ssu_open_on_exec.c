#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd;
	int val;
	fd = open("exec_copy.txt", O_CREAT);

	/*
	제가 코드를 작성한 환경의 리눅스버전에서는 기본적으로 FD_CLOEXEC플래그를 설정해놓기 때문에 교재와 똑같이 작성할경우 파일디스크립터가 상속되지 않습니다.
	그래서 제 환경에서는 아래 코드를 추가하여 파일디스크립터가 책처럼 상속되게 만들었습니다.
	int flag=fcntl(fd,F_GETFD);
	flag&=~FD_CLOEXEC;
	fcntl(fd,F_SETFD,flag);
	*/
	execl("loop", ".loop", NULL);
	exit(0);
}
