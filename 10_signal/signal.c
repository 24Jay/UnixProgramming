#include "apue.h"

static void sig_user(int);

int main(void)
{	if(signal(SIGUSR1,sig_user)==SIG_ERR)
		err_sys("cannot cath signal 1!");
	if(signal(SIGUSR2,sig_user)==SIG_ERR)
		err_sys("cannot cath signal 2!");

	for(;;)
		pause();
}


static void sig_user(int signo)
{
	
	if(signo == SIGUSR1)
		printf("reveived SIGUER1\n");
	if(signo == SIGUSR2)
		printf("reveived SIGUER2\n");
	
	else 
		err_dump("received signal %d\n", signo);
}
