#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int id = fork();

	if(id == 0) // Child Process
		sleep(1);

	// Danger instruction -> Parent Terminate & Child is not --> Zoombi
	printf("PID: (%d) | PPID: (%d)\n", getpid(), getppid());

	// This command make to wait all children processes to end -> Safe of Zoombi
	if(wait(NULL) == -1)
		printf("No children to wait for\n");

	return 0;
}

// pid_t wait(int *status)
// wait for a child process to terminate.
// return -> [OK -> Child PID]  ||  [KO -> -1]
