/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
 ************************************************************************/

#include <func.h>

#define N 100000000

int global = 0;

int main(int argc,char *argv[])
{
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    /* printf("shmid = %d\n",shmid); */

    int *p = (int*)shmat(shmid,0,0);
    ERROR_CHECK(p,(int*)-1,"shmat");

    // 不用共享内存，用一个int类型的变量行不行?
    int num=0;

    //父进程和子进程对共享内存中的数字各加1000万
    //最后的结果未必等于2000万
    //有几次的结果甚至小于1000万？
    if(fork())
    {
        printf("i am parent\n");

        for(int i=0;i<N;i++)
        {
            *p += 1;
            num++;
            global++;
        }
    }
    else{
        printf("i am child\n");

        for(int i=0;i<N;i++)
        {
            *p += 1;
            num ++;
            global++;
        }
        return 0;
    }

    wait(NULL);
    //多核处理器中，两个进程是并行执行的(同时执行),得到的值更接近于1000万
    //单核处理器中，两个进程是并发执行的(同时存在，但同一时刻只有一个进程执行)，
    //因此单核处理器系统执行的结果更大，更接近2000万
    printf("%d\n",*p);
    /* printf("%d\n",num); */
    /* printf("%d\n",global); */
    *p=0;

    return 0;
}
