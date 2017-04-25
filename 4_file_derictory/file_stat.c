#include "apue.h"

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;

	for(i = 1;i<argc;i++)
	{
		printf("%s:\n",argv[i]);
		if(lstat(argv[i],&buf)<0)
		{
			err_ret("lstat error!");
			continue;
		}

		printf("process_uid: %d\n", getuid());
		printf("process_gid: %d\n", getgid());
		printf("file_uid: %ld\n", (long int)buf.st_uid);
		printf("file_gid: %ld\n", (long int)buf.st_gid);
		printf("file_size: %ld\n", (long int)buf.st_size);
		if(S_ISREG(buf.st_mode))
			ptr = "regular";
		else if(S_ISDIR(buf.st_mode))
			ptr = "directory";
		else
			ptr = "***unknown mode***";
		printf("%s\n",ptr);
	}
	exit(0);
}

