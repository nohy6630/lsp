#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("abort terminate this program\n");
	abort();
	printf("this line is never reached\n");
	exit(0);
}
