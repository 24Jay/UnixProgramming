#include "apue.h"
#include <pthread.h>

void *foo1(void *arg)
{
	printf("thread 1 returning\n");
	return((void *)1);
}


void *foo2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void *)2);

}


int main(void)
{
	int err;
	pthread_t t1,t2;
	void *tret;

	err=pthread_create(&t1,NULL,foo1,NULL);
	if(err!=0)
		err_exit(err,"cannot create thread 1");

	err=pthread_create(&t2,NULL,foo2,NULL);
	if(err!=0)
		err_exit(err,"cannot create thread 2");

	err = pthread_join(t1,&tret);
	if(err!=0)
		err_exit(err,"cannot join with thread 1");
	printf("thread 1 exit with code=%ld\n",(long)tret);

	err = pthread_join(t2,&tret);
	if(err!=0)
		err_exit(err,"cannot join with thread 2");
	printf("thread 2 exit with code=%ld\n",(long)tret);

	exit(0);
}
