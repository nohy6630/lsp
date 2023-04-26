#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *argv[]={
		"ssu_execl_test_1", "param1", "param2", (char *)0
	};

	printf("this is the original program\n");
	execv("./execl_test_1", argv);//execl_test_1프로세스를 실행
	printf("%s\n", "This line should never get printed\n");//위에서 execv를 호출하였기 때문에 이줄은 출력되면 안됨/
	exit(0);
}


