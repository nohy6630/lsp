#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define NAME_SIZE 54

struct ssu_employee
{
	char name[NAME_SIZE];
	int pid;
	int salary;
};

int main(int argc, char *argv[])
{
	struct ssu_employee record;
	int fd;

	fd=open(argv[1], O_WRONLY | O_CREAT | O_EXCL);
	while(1)
	{
		printf("Enter employee name <SPACE> salary: ");
		scanf("%s", record.name);
		if(record.name[0]=='.')
			break;
		scanf("%d", &record.salary);
		record.pid=getpid();
		write(fd, (char*)&record, sizeof(record));
	}
	close(fd);
	exit(0);
}
