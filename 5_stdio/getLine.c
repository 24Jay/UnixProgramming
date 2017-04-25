#include <stdio.h>
#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	while(fgets(buf,MAXLINE,stdin) != NULL)
		fputs(buf,stdout);
}
