/*************************************************************************
	> File Name: orphan.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 14:47:05
    > 创建孤儿进程
 ************************************************************************/

#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        while(1);
    }
    else{
        return 0;
    }
}

