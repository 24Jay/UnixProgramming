#include <unistd.h>
#include <stdio.h>
#include "apue.h"

int glovar = 6;

char buf[]= "a write ot stdout!\n";


int main(void)
{
	int var;
	pid_t pid;

	var = 88;

	int size = sizeof(buf)-1;
	if(write(STDOUT_FILENO,buf,size)!=size)
		err_sys("write error!");
	
	//父进程还未flush的缓冲也会被复制到子进程
	printf("before fork...\n");

	if((pid = fork())<0)
	{
		err_sys("fork error!");
	}
	else if(pid ==0)
	{
		glovar ++;
		var++;
	}
	else
	{
		//父进程休眠，让子进程先执行
		sleep(2);
	}
	
	printf("pid = %ld, glob = %d, var = %d\n",(long)getpid(),glovar,var);
	exit(0);
}
