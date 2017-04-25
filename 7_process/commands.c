#include "apue.h"

int main(int argc, char *argv[])
{
	int i;

	printf("The total commands including this itself!  argc=%d\n",argc);

	for(i=0;i<argc;i++)
	{
		printf("argv[%d] : %s\n",i,argv[i]);
	}
	exit(0);
}
