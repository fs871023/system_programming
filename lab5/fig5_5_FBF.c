#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	setvbuf(stdin,buf,_IOFBF,100);
	while( (fgets(buf,MAXLINE,stdin)) != NULL )
	{
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
	}	
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}

