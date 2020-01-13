/*************************************************************************
	> File Name: setpgid.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 11:54:23
    > 了解进程组的概念
    > 父进程创建出子进程，默认是跟父进程属于同一个进程组的
    > 可以通过getgpid获取当前进程所处的进程组id
    > 通过setpgid()把调用的进程设置到其他进程组里面
    > 子进程设置到新的进程组之后，在通过终端ctrl+C终止时，
    > 子进程不会受到信号被终止。
 ************************************************************************/

#include <func.h>


int main()
{
    if(!fork())
    {
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        /* setpgid(0,0); */
        while(1);
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        return 0;
    }
    else{
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        wait(NULL);
        return 0;
    }
}
