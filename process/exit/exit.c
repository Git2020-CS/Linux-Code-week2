/*************************************************************************
	> File Name: exit.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-09 18:06:54
    > 调用exit退出会清理缓冲区，调用_exit退出不会清理缓冲区
 ************************************************************************/

#include <func.h>
void exitFun1()
{
    printf("this is exitFun1\n");
}

void exitFun()
{
    printf("exitFun\n");
    printf("exit print");//调用exit()退出时会打印这行，调用_exit()则不会打印
    _exit(0);
    /* exit(0); */
}

int main()
{
    atexit(exitFun1);
    printf("main\n");
    exitFun();

    printf("after fun()\n");

    return 0;
}

