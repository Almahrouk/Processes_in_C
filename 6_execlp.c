#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    int id = fork();
    if (id == -1)
    {
        printf("Error in fork\n");
        return 1;
    }
    if(id == 0) // Child Process
    {
        execlp("ping", "-c", "4", "google.com", NULL);
        printf("This will not execution\n");
    }
    else
    {
        wait(NULL);
        printf("The child is finished\n");
    }

    return 0;
}
