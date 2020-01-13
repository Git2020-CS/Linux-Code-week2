/*************************************************************************
	> File Name: setpgid.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 11:54:23
    > 了解进程组的概念
    > 父进程创建出子进程，默认是跟父进程属于同一个进程组的
    > 可以通过getgpid获取当前进程所处的进程组id
    > 在终端输入ctrl+C产生的信号是发送给进程组的
    > 
 ************************************************************************/

#include <func.h>
void sigFun(int signum)
{
    printf("signal %d is comming\n",signum);
}

int main()
{
    if(!fork())
    {
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        signal(SIGINT,sigFun);
        /* while(1); */
        sleep(3);
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        return 0;
    }
    else{
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        signal(SIGINT,sigFun);
        wait(NULL);  //父进程如果退出了，只要进程组中还有其他进程，进程组就还在
        return 0;
    }
}
