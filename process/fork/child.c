/*************************************************************************
	> File Name: child.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-06 21:42:58
    > 
 ************************************************************************/


#include <func.h>

void print()
{
    printf("getpid=%d\n",getpid());
    return;
}

int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        print();
        printf("getpid=%d\n",getpid());
    }
    else{
        printf("pid = %d,getpid=%d\n",pid,getpid());
    }

    // 子进程是否会执行这一句？
    printf("after fork()\n");
    return 0;
}
