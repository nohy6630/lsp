#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("this is the original program\n");
	execl("./execl_test_1", "ssu_execl_test_1", "param1", "param2", "param3", (char*)0);
	printf("%s\n", "this line should never get printed\n");//위에서 execl을 호출하였기 때문에 이 문장을 출력되면 안됨/
	exit(0);
}
