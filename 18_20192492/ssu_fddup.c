#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main()
{
	int testfd;
	int fd; 

	fd = open("test.txt", O_CREAT);

	testfd = fcntl(fd, F_DUPFD, 5);//파일디스크립터 복제
	printf("testfd = %d\n", testfd);
	testfd = fcntl(fd, F_DUPFD, 5);//파일디스크립터 5가 이미 사용중이므로 6에 복제됨
	printf("testfd = %d\n", testfd);

	getchar();
}
