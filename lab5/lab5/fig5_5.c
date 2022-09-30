#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	int counter=0;
	while( (fgets(buf,MAXLINE,stdin)) != NULL )
	{
		counter++;
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
	}	
	if(ferror(stdin))
		err_sys("input error");
	printf("%d\n",counter);
	exit(0);
}

