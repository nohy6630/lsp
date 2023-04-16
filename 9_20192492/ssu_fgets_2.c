#include <stdio.h>
#include <stdlib.h>

#define BUFFER_MAX 256

int main(void)
{
    char command[BUFFER_MAX];
    char *prompt = "Prompt>>";

    while (1)
    {
        fputs(prompt, stdout);
        if (fgets(command, sizeof(command), stdin) == NULL)//표준입력스트림에서 문자열을 읽어온다.
            break;
        
        system(command);//입력받은 문자열을 통해 명령어를 실행한다.
    }
    fprintf(stdout, "Good bye...\n");
    fflush(stdout);
    exit(0);
}
