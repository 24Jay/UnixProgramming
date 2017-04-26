#include "apue.h"
#include <unistd.h>
int globvar = 24;

int main(void)
{
	int var = 24;
	pid_t pid;

	printf("before vfork...\t");
	printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());

	pid = fork();

	if(pid < 0)
		printf("vfork error!!\n");
	else if(pid == 0)
	{
		printf("This is the child process!...\t");
		printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());
		globvar++;
		var++;
		_exit(0);
	}
	sleep(2);
	//parent process continues here
	printf("parent process continues here...\t");

	printf("pid = %ld, ppid = %ld\n",(long)getpid(),(long)getppid());
	printf("globvar = %d, var = %d\n",globvar,var);

}
