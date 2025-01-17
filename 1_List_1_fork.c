#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int id = fork();

	int n;
	if(id == 0) // Child Process
		n = 1;
	else // Parent Process
		n = 6;

	if(id != 0) // Parent Process
		wait(NULL);

	int i;
	for(i = n; i < n+5; i++) { // Child Process will exe at first then the Parent Process
		printf("i ", i);
		fflush(stdout);
	}

	if(id != 0) // Parent Process
		printf("\n");
}

// Output:
//  1 2 3 4 5  6 7 8 9 10
// |_________||__________|
//  Child Pro  Parent Pro

/*
Process ID (1), fork return (2) -> Parent
Process ID (2), fork return (0) -> Child

+-------------+---+---+---+---+----+----+----+-----+
| Fork Call   | 0 | 1 | 2 | 3 | 4  | 5  | 6  |  7  |
+-------------+---+---+---+---+----+----+----+-----+
| NO. Process | 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 |
+-------------+---+---+---+---+----+----+----+-----+

Equation:
#-process = 2 ^ (fork-call)
*/