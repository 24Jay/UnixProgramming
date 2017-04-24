#include "apue.h"
#include <fcntl.h>
#define BUFFSIZE 1024

/*
 * read a specified file , and print to stdout
 *
 */
int main(void)
{
	char buf[BUFFSIZE];
	int n;
	int fd = open("test.txt",O_RDWR,FILE_MODE);
	//int fd = open(file,O_RDWR,FILE_MODE);
	if(fd<0)
		err_sys("open filed error!");

//	printf("fd=%d\n",fd);
	while((n=read(fd,buf,BUFFSIZE))>0)
	{
//		printf("n=%d\n",n);
//		printf("buf = %s\n",buf);
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	}
	if(n<0)
		err_sys("read error");
	close(fd);
	exit(0);
}
