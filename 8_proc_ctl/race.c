#include "apue.h"

static void charatime(char *);

int main(void)
{
	pid_t pid;

	if((pid=fork())<0)
	{
		err_sys("fork error!");
	}
	else if(pid ==0)
	{
		charatime("output-from-child\n");
	}
	else
	{
		charatime("OUTPUT-FROM-PARENT\n");
	}
	exit(0);
}

static void charatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout,NULL);
	for(ptr = str;(c=*ptr++)!=0; )
	{
		sleep(1);
		putc(c,stdout);
	}	
}
