#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int num = 0;

void handel(int signal)
{
    if(num == 0)
	    printf("\n(HINT): Fast\n");
}

int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		printf("Error While Fork\n");
		return 1;
	}
	if(pid == 0) // Child process
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else // Parent process
	{
		struct sigaction sa = { 0 };
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handel;
        sigaction(SIGUSR1, &sa, NULL);


		printf("Please write a number: ");
		scanf("%d", &num);
        
		if(num == 5)
			printf("wel done you have guss the number\n");
		else
			printf("woung guss\n");
        wait(NULL);
	}
	return 0;
}