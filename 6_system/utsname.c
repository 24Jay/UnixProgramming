#include <sys/utsname.h>
#include <stdio.h>

#include <unistd.h>
int main(void)
{
	struct utsname name;
	if(uname(&name)==-1)
		printf("error!\n");
	printf("sysname = %s\n",name.sysname);
	printf("nodename = %s\n",name.nodename);
	printf("release = %s\n",name.release);
	printf("version = %s\n",name.version);
	printf("machine = %s\n",name.machine);
	
	char hostname[20];
	gethostname(hostname,20);
	printf("hostname = %s\n",hostname);
}
