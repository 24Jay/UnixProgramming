#include "apue.h"
#include <fcntl.h>
#define BUFFSIZE 1024


int main(void)
{
	char buf[BUFFSIZE];
	int n;
	int fd = open("test.txt",O_WRONLY,FILE_MODE);
	while((n=read(fd,buf,BUFFSIZE)>0))
	{
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	}
	if(n<0)
		err_sys("read error");
	exit(0);
}
