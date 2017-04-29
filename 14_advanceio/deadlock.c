#include "apue.h"
#include <fcntl.h>

static void lockabyte(const char *name, int fd,off_t offset)
{
	if(writew_lock(fd,offset,SEEK_SET,1)<0)
		err_sys("error lock file");	

	printf("%s: got the lock, byte %lld\n",name,(long long)offset);

}

int main(void)
{
	int fd;
	pid_t pid;
	
	if((fd=creat("templock",FILE_MODE))<0)
		err_sys("create error");

	if(write(fd,"ab",2)!=2)
		err_sys("write error");

//	TELL_WAIT();

	if((pid=fork())<0)
		err_sys("fork error");

	
	else if(pid ==0)
	{
		lockabyte("child",fd,0);
		//TELL_PARENT(getppid());
		sleep(3);
		lockabyte("child",fd,1);
	}

	
	else if(pid>0)
	{
		sleep(1);
		lockabyte("parent",fd,1);
	//	TELL_CHILD(pid);
		sleep(3);
		lockabyte("parent",fd,0);
	}

	exit(0);
}

