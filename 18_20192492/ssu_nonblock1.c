#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

void set_flags(int fd, int flags);
void clr_flags(int fd, int flags);

char buf[500000];

int main()
{
	int ntowrite, nwrite;
	char *ptr;

	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "reading %d bytes\n", ntowrite);

	set_flags(STDOUT_FILENO, O_NONBLOCK);
	//O_NONBLOCK플래그 비트를 설정했기에 해당 파일에 해당 파일에 대한 I/O작업이 즉시 반환됨. 
	ptr = buf;
	while(ntowrite > 0)//buf의 크기보다 데이터가 더 커질수 있으니 while문이용
	{
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

		if(nwrite > 0)
		{
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
	clr_flags(STDOUT_FILENO, O_NONBLOCK);
	exit(0);
}

void set_flags(int fd, int flags)
{
	int val;

	if((val = fcntl(fd, F_GETFL, 0)) < 0)//플래그 가져옴
	{
		fprintf(stderr, "fcntl F_GETFL failed");
		exit(1);
	}

	val |= flags;//해당 비트 추가

	if(fcntl(fd, F_SETFL, val) < 0)//플래그 세팅
	{
		fprintf(stderr, "fcntl F_SETFL failed");;
		exit(1);
	}
}

void clr_flags(int fd, int flags)
{
	int val;

	if((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		fprintf(stderr, "fcntl F_GETFL failed");
		exit(1);
	}

	val &= ~flags;//해당 비트 제거

	if(fcntl(fd, F_SETFL, val) < 0)
	{
		fprintf(stderr, "fcntl F_SETFL failed");
		exit(1);
	}
}
