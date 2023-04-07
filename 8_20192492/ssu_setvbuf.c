#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void ssu_setbuf(FILE *fp, char *buf);

int main()
{
    char buf[BUFFER_SIZE];
    char *fname = "/dev/pts/19";
    FILE *fp;

    if ((fp = fopen(fname, "w")) == NULL)
    {
        fprintf(stderr, "fopen error for %s", fname);
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

void ssu_setbuf(FILE *fp, char *buf)
{
    size_t size;
    int fd;
    int mode;

    fd = fileno(fp); // 파일스트림으로 부터 파일 디스크립터를 가져옴
    if (isatty(fd)) // 파일디스크립터가 터미널과 연결되어잇는지 검사
        mode = _IOLBF;
    else
        mode = _IOFBF;

    if (buf == NULL)
    {
        mode = _IONBF;
        size = 0;
    }
    else
        size = BUFFER_SIZE;
    setvbuf(fp, buf, mode, size);//버퍼뿐 아니라 버퍼링 방법과 버퍼 크기까지 지정
}