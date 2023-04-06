#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void ssu_setbuf(FILE *fp, char *buf);

int main()
{
    char buf[BUFFER_SIZE];
    char *fname="/dev/pts/19";
    FILE *fp;

    if ((fp = fopen(fname, "w"))==NULL)
    {
        fprintf(stderr, "fopen error for %s",fname);
        exit(1);
    }

    ssu_setbuf(fp, buf);
    fprintf(fp, "Hello, ");
    sleep(1);
    fprintf(fp, "UNIX!!");
    sleep(1);
    fprintf(fp, "\n");
    sleep(1);
    ssu_setbuf(fp, NULL);
    fprintf(fp, "HOW");
    sleep(1);
    fprintf(fp, " ARE");
    sleep(1);
    fprintf(fp, " YOU?");
    sleep(1);
    fprintf(fp, "\n");
    sleep(1);
    exit(0);
}