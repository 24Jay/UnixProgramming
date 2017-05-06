#include "apue.h"
#include <fcntl.h>
 #include <sys/types.h>
#include <limits.h>
#include <db.h>

int main(void)
{
       DB *db;
       
       db  = dbopen("dv4",O_RDWR|O_CREAT|O_TRUNC, DB_HASH,NULL);

}
