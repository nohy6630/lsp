#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAME_SIZE 256

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2, *fp3;
	char buf1[NAME_SIZE], buf2[NAME_SIZE];
	char fname1[NAME_SIZE], fname2[NAME_SIZE], temp[]="temp.txt";

	printf("Enter your first file name: ");
	scanf("%s", fname1);
	printf("Enter your second file name: ");
	scanf("%s", fname2);
	fp1 = fopen(fname1, "r");
	fp2 = fopen(fname2, "r");
	fp3 = fopen(temp, "w");
	while(!feof(fp1) || !feof(fp2))
	{
		fgets(buf1, NAME_SIZE, fp1);
		if(!feof(fp1))
			fprintf(fp3, "%s", buf1);
		fgets(buf2, NAME_SIZE, fp2);
		if(!feof(fp2))
			fprintf(fp3, "%s", buf2);
		memset(buf1, 0, NAME_SIZE);
		memset(buf2, 0, NAME_SIZE);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	remove(fname1);
	remove(fname2);
	rename(temp, fname1);
	exit(0);
}
