#include <stdio.h>
#include <stdlib.h>

struct ssu_pirate
{
    unsigned long booty;
    unsigned int beard_length;
    char name[128];
};

int main(void)
{
    struct ssu_pirate blackbeard = {950, 48, "Edward Teach"}, pirate;
    char *fname = "ssu_data";
    FILE *fp1, *fp2;

    if ((fp2 = fopen(fname, "w")) == NULL)
    {
        fprintf(stderr, "fopen error for %s\n", fname);
        exit(1);
    }

    if (fwrite(&blackbeard, sizeof(struct ssu_pirate), 1, fp2) != 1)
    //구조체 변수의 데이터를 파일에 저장
    {
        fprintf(stderr, "fwrite error\n");
        exit(1);
    }

    if (fclose(fp2))
    {
        fprintf(stderr, "fclose error\n");
        exit(1);
    }

    if ((fp1 = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr, "fopen error\n");
        exit(1);
    }

    if (fread(&pirate, sizeof(struct ssu_pirate), 1, fp1) != 1)
    //파일에서 읽어온 데이터를 구조체 변수의 저장
    {
        fprintf(stderr, "fread error\n");
        exit(1);
    }

    if (fclose(fp1))
    {
        fprintf(stderr, "fclose error\n");
        exit(1);
    }

    printf("name=\"%s\" booty=%lu beard_length=%u\n", pirate.name, pirate.booty, pirate.beard_length);
    exit(0);
}