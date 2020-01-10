/*************************************************************************
	> File Name: exit.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 18:06:54
 ************************************************************************/

#include <func.h>

void exitFun()
{
    printf("exitFun\n");
    printf("exit print");
    _exit(0);
}

int main()
{
    printf("main\n");
    exitFun();

    printf("after fun()\n");

    return 0;
}

