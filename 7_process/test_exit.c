#include "apue.h"

static void exit_1(void);

static void exit_2(void);

int main(void)
{
	if(atexit(exit_1)!=0)
		err_sys("cannot register exit_1");
	
	if(atexit(exit_1)!=0)
		err_sys("cannot register exit_1");



	if(atexit(exit_2)!=0)
		err_sys("cannot register exit_2");

	printf("main is done\n");
	
	exit(-1);
	//return(0);
}

static void exit_1(void)
{
	printf("first exit handler!\n");
}

static void exit_2(void)
{
	printf("second exit handler!\n");
}



