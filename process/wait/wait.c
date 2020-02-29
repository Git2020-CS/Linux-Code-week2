/*************************************************************************
	> File Name: wait.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 15:04:29
    > 父进程创建子进程后，等待(wait)子进程
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
        pid_t waitpid;
        // wait()等到任何一个子进程退出后就会返回，返回值为子进程的pid
        waitpid = wait(NULL);
        printf("waitpid=%d\n",waitpid);
    }
}

