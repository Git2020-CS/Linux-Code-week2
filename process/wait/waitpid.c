/*************************************************************************
	> File Name: waitpid.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 15:04:29
    > 父进程创建子进程后，等待(wait)子进程
    > 使用waitpid可以等待特定进程号的子进程退出
 ************************************************************************/

#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child \n");
        sleep(3);
        return 0;
    }
    else{
        printf("this is paretn ,child pid = %d\n",pid);
        pid_t wpid;
        int exitStatus;
        // waitpid()等到指定进程号的子进程退出后才会返回，返回值为子进程的pid
        /* wpid = waitpid(pid,&exitStatus,0); */
        /* pid_t group_id = 0 - getpid(); */
        /* wpid = waitpid(group_id,&exitStatus,0); */ // 当pid的值填的是小于-1的整数时，等待该pid值的绝对值的进程组中任一子进程退出
        wpid = waitpid(pid,&exitStatus,WNOHANG);
        printf("waitpid=%d\n",wpid);
        if(WIFEXITED(exitStatus))
        {
            printf("child %d exit status : %d\n",wpid,WEXITSTATUS(exitStatus));
        }
        return 0;
    }
}

