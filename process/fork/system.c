/*************************************************************************
	> File Name: system.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-06 21:38:06
    > “system("command")” 等同于执行 /bin/sh -c "command"
    > 思考：如何用exec系列函数实现system("ls -l");
 ************************************************************************/

#include <func.h>

int main()
{
    system("ls -l");
    sleep(1);
    printf("\n\n");
    return 0;
}
