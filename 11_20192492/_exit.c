#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Good afternoon?");
	_exit(0);//버퍼 비우지 않고 프로그램 종료
}
