#include "apue.h"

int main(void)
{
	printf("uid=%d, gid=%d\n",getuid(),getgid());
	printf("hello world from process ID %ld\n",(long)getpid());
	exit(0);
}
