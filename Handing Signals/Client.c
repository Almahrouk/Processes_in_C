#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
    pid_t Server_id = -1;
    printf("Get the Server Process ID ");
    scanf("%d", &Server_id);

    int time;
    printf("How much time (in second) do you want to running the child process? ");
    scanf("%d", &time);
    if(time > 0)
    {
        printf("Running for %d seconds\n", time);
        kill(Server_id, SIGCONT);
        sleep(time);
        kill(Server_id, SIGSTOP);
    }
    else
    {
        printf("please write a positave number\n");
    }
    kill(Server_id, SIGKILL);
    printf("End kill\n");
    wait(NULL);

    printf("End Program from main process | the child process is killed\n");
    return 0;
}