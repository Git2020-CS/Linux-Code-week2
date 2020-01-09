/*************************************************************************
	> File Name: wait_arg.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 15:04:29
    > 父进程创建子进程后，等待(wait)子进程
    > 并且获取子进程的退出状态，并通过一些宏来获取状态信息
 ************************************************************************/

#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child \n");
        sleep(10);
        return 1;
    }
    else{
        printf("this is paretn ,child pid = %d\n",pid);
        pid_t waitpid;
        // wait()等到任何一个子进程退出后就会返回，返回值为子进程的pid
        int status;
        waitpid = wait(&status);
        printf("waitpid=%d, status = %d\n",waitpid,status);

        //要获得子进程的返回值不能直接用status,要用几个宏来判断，见wait的manpage
        if(WIFEXITED(status))//判断子进程是否是正常退出，如果是正常退出，返回true
        {
            printf("child exit normally, status=%d\n",WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status)){
            // 如果子进程是被信号终止的
            printf("child terminated by signal:%d\n",WTERMSIG(status));
        }
    }
}

