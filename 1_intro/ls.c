#include <dirent.h>
#include "apue.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc , char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc !=2)
		err_quit("usage : ls directroty_name");
	if((dp = opendir(argv[1]))==NULL)
		err_sys("cannot open file");
	while((dirp=readdir(dp))!= NULL)
		printf("%s\n",dirp->d_name);
	
	closedir(dp);
	exit(0);
}
