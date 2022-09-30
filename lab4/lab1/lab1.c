#include "apue.h"
#include <sys/wait.h>
#include <unistd.h>

static void	sig_int(int);		/* our signal-catching function */
int main(void)
{
    char	buf[MAXLINE];	/* from apue.h */
    pid_t	pid = fork();
    int		status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");	/* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        char *space = " ";
        char argv[3] ;

        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        argv=strtok(buf,space);

        if(argv[0]=="ls")
            execvp("ls",argv);
        else if(argv[0]=="mkdir")
            execvp("mkdir",argv);
        else if(argv[0]=="cp")
            execvp("cp",argv);
        else if(argv[0]=="cd")
            execvp("cd",argv);
        else
            err_sys("signal error");

        if ((pid < 0)
        {
        err_sys("fork error");
        }
        else if (pid == 0)  		/* child */
        {
        execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
        err_sys("waitpid error");
        printf("%% ");
    }
exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}

