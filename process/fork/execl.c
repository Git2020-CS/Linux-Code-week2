/*************************************************************************
	> File Name: execl.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-07 15:37:17
    > execl 函数执行时， 第一个参数 第二个参数作为新的进程名称，后面继续传参
 ************************************************************************/

#include <func.h>

int main(int argc,char* argv[])
{
    printf("before execl\n");
    /* execl(argv[1],argv[2],argv[3],NULL); */
    execl("./print","hello","123",NULL);
    printf("before execl\n");
    return 0;
}
