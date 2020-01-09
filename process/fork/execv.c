/*************************************************************************
	> File Name: execp.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-07 21:03:55
 ************************************************************************/

#include <func.h>

int func()
{
    printf("func\n");
    return 0;
}

int main()
{
    func();
    char *env[] = {"hello","123","456",NULL};
    if(execv("./print_arg",env)< 0)
    {
        /* printf("execlp error\n"); */
        perror("execv");
        return -1;
    }
}
