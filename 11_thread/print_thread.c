#include "apue.h"
#include <pthread.h>


/***
 *
 *gcc print_thread.c -lpthread -o pthread
 *
 *
 */





pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s, pid %lu, tid %lu \n",s,(unsigned long)pid,(unsigned long)tid);
}

void * thread_foo(void *arg)
{
	printids("new thread: ");
	return((void *)0);
}

int main(void)
{
	int err;

	err = pthread_create(&ntid, NULL,thread_foo,NULL);
	if(err!=0)
		err_exit(err,"cannot create thread.");
	printids("main thread:");
	sleep(1);
	exit(0);
}
