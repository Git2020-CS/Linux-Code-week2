/*************************************************************************
	> File Name: zombie.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 14:47:05
    > 创建僵尸进程
 ************************************************************************/

#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("this is child\n");
        return 0;
    }
    else{
        while(1);
    }
    return 0;
}

