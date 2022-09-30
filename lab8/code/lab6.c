#include <stdio.h>
#include "apue.h"

void accumulation(int d_sum);

int main()
{
    FILE* sum;
    int total_sum=0;
    pid_t pid[5];
    int year=5, week=52, day=7;

    sum = fopen("sum.txt", "w");
    fprintf(sum, "%d\n", 0);
    fclose(sum);

    /**********************************************************/

    int sum_d;
    int value;
    char filename [20];
    FILE * file;
    for(int cnt_pid=1; cnt_pid <6; cnt_pid++)
    {
        TELL_WAIT();

        if((pid [cnt_pid] = fork())<0)
        {
            err_sys("fork error");
        }
        else if(pid[cnt_pid] == 0)
        {
            for(int i=1; i<53; i++)
            {
                sprintf(filename,"%d-%02d.txt",cnt_pid,i);
                file=fopen(filename,"r");
                for(int j=0; j<7; j++)
                {
                    sum_d=0;
                    for(int k=0; k<96; k++)
                    {
                        fscanf(file,"%d",&value);
                        sum_d=sum_d+value;
                    }
                    WAIT_PARENT();
                    accumulation(sum_d);
                    TELL_PARENT(getppid());
                }

            }
            exit(0);
        }
        else
        {
            for(int i=0; i<52; ++i)
            {
                for(int j=0; j<7; ++j)
                {
                    TELL_CHILD(pid[cnt_pid]);
                    WAIT_CHILD();
                }
            }
        }
    }
    /**********************************************************/

    sum = fopen("sum.txt", "r");
    fscanf(sum, "%d", &total_sum);
    printf("Day_Average = %d\n",total_sum/(year*week*day));
    fclose(sum);

    return 0;
}

void accumulation(int d_sum)    //Accumulating the daily sum to "sum.txt".
{
    FILE* sum;
    int tmp=0;

    sum = fopen("sum.txt", "r+");
    fscanf(sum, "%d", &tmp);

    tmp += d_sum;

    rewind(sum);
    fprintf(sum, "%d", tmp);
    fclose(sum);

    return;
}
