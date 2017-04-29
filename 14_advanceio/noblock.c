#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main(void)
{
	int ntowrite, nwrite;
	char *ptr;

	ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
	fprintf(stderr,"read %d bytes\n",ntowrite);

	set_fl(STDOUT_FILENO,O_NONBLOCK);

	ptr = buf;

	while(ntowrite >0)
	{
		errno = 0;
		nwrite = write(STDOUT_FILENO,ptr,ntowrite);
		fprintf(stderr,"nwrite = %d, errno = %d\n",nwrite,errno);

		if(nwrite>0)
		{
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}

	clr_fl(STDOUT_FILENO,O_NONBLOCK);
	exit(0);
}

void set_fl(int fd, int flags)
{
	int val;

	val = fcntl(fd,F_GETFL,0);

	val |=flags;

	fcntl(fd,F_SETFL,0);


}

void clr_fl(int fd, int flags)
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0)) == -1)
	{
		exit(1);
		
	}
	val &= ~flags; /* turn flags off */

	if (fcntl(fd, F_SETFL, val) == -1)	
	{
		exit(1);
	}
	return;

}
