#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
int main()
{
	int id1 = fork();
	int id2 = fork();

	if(id1 == 0)
	{
		if(id2 == 0)
			printf("3\n");
		else
			printf("1\n");
	}
	else
	{
		if(id2 == 0)
			printf("2\n");
		else
			printf("0\n");
	}

	// wait(NULL); this will wait one child only
	while(wait(NULL) != -1 || errno != ECHILD);

}