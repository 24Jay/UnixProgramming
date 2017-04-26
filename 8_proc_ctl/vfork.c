#include "apue.h"
#include <unistd.h>
#include <sys/wait.h>


int globvar = 24;

int main(void)
{
	int var;
	pid_t pid;

	printf("before vfork...\t");
	printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());

	var =24;

	pid = fork();
	if(pid < 0)
		printf("vfork error!!\n");
	else if(pid == 0)
	{
		printf("\nChild process continues here...");
		printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());
		globvar++;
		var++;
//		exit(7);
	
	}
	else
	{
		printf("Parent process continues here, but sleep for 2 seconds...\n");
		sleep(2);
	}
	int exit_stat;
	printf("killed child process ---->%d, status=%d\n",wait(&exit_stat),exit_stat);
	printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());
	printf("globvar = %d, var = %d\n",globvar,var);
//	exit(0);
}
