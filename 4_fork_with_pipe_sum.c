#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    int fd[2];
    int re_pipe = pipe(fd);
    if(re_pipe == -1)
    {
        printf("Error While Opening Pipe\n");
        return 9;
    }

    int arr[] = { 1, 2, 3, 4, 5 };
    int arrSize = sizeof(arr) / sizeof(int);

    int start, end, sum = 0;

    pid_t id = fork();
    if (id == -1)
    {
        printf("Error While Fork");
        return 1;
    }
    if(id == 0) // Child Process
    {
        start = 0;
        end = arrSize / 2;
    }
    else
    {
        wait(NULL);
        start = arrSize / 2;
        end = arrSize;
    }

    int i;
    for(i = start; i < end; i++)
    {
        sum += arr[i];
        printf("I -> (%d) | arr[%d] -> (%d) | sum -> (%d) |\n", i, i, arr[i], sum);
    }
    printf("Sum -> %d\n", sum);


    // Try to send sum variable from Child process to Parent process -> using pipe
    printf("Part 2:\n", sum);

    // write sum to pipe fd[1] (Child process)
    if(id == 0)
    {
        close(fd[0]);
        int return_write;
        return_write = write(fd[1], &sum, sizeof(int));
        if(return_write == -1)
        {
            printf("Error while writing\n");
            return 1;
        }
        close(fd[1]);
    }

    // write sum to pipe fd[1] (Child process)
    else
    {
        close(fd[1]);
        int return_read;
        int sum_child;
        return_read = read(fd[0], &sum_child, sizeof(int));
        if(return_read == -1)
        {
            printf("Error while reading\n");
            return 2;
        }
        close(fd[0]);
        sum += sum_child;

        printf("Sum -> %d\n", sum);
    }

    return 0;
}