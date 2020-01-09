/*************************************************************************
	> File Name: fork.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-06 21:42:58
    > fork()函数，创建子进程，执行一次，返回两个结果
    > 子进程创建后与父进程的独立执行各自的流程
 ************************************************************************/


#include <func.h>

int main()
{
    pid_t pid;
    int i=3;
    printf("&i = %p\n",&i);
    pid = fork();
    if(pid == 0)
    {
        // fork返回值为0时，是子进程
        printf("child i=%d\n",i);
        i+=3;
        printf("&i = %p\n",&i);
        printf("child i=%d\n",i);
        printf("i am child, getpid=%d\n",getpid());
        /* while(1); */
        return 0;
    }
    else{
        // 父进程的返回值是子进程的id
        printf("i am parent pid = %d,getpid=%d\n",pid,getpid());
        printf("parent i=%d\n",i);
        i+=1;
        printf("&i = %p\n",&i);
        printf("parent i=%d\n",i);
        /* while(1); */
        return 0;
    }
}
