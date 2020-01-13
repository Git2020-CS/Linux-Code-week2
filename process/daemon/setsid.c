/*************************************************************************
	> File Name: setsid.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 11:54:23
    > 了解会话组的概念
    > 通过setsid让进程独自建立新的会话，并成为会话组组长
 ************************************************************************/

#include <func.h>


int main()
{
    if(!fork())
    {
        printf("i am child pid=%d,ppid=%d,pgid=%d,sid=%d\n"
               ,getpid(), getppid(), getpgid(0),getsid(0));
        /* setpgid(0,0); */
        setsid();
        printf("i am child pid=%d,ppid=%d,pgid=%d,sid=%d\n"
               ,getpid(), getppid(), getpgid(0),getsid(0));
        while(1);
        return 0;
    }
    else{
        printf("i am child pid=%d,ppid=%d,pgid=%d\n"
               ,getpid(), getppid(), getpgid(0));
        wait(NULL);
        return 0;
    }
}
