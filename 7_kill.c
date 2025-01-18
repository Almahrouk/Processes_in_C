#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
    pid_t id = fork();
    if(id == -1)
    {
        printf("fork is not work\n");
        return 1;
    }
    if(id == 0)
    {
        while(1)
        {
            printf("Line forever\n");
            usleep(500000);
        }
        printf("This is hidden\n");
    }
    else
    {
        sleep(1);
        printf("End sleep\n");
        kill(id, SIGKILL);
        printf("End kill\n");
        wait(NULL);
    }
    printf("End Program from main process | the child process is killed\n");
    return 0;
}