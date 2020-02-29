/*************************************************************************
	> File Name: abort.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 09:51:27
 ************************************************************************/

#include <func.h>

jmp_buf env;
void sigFunc(int signum)
{
    printf("sigFunc %d\n",signum);
    longjmp(env,1);
}

int main()
{
    signal(SIGABRT,sigFunc);
    printf("before abort\n");

    /* jmp_buf env; */
    /* setjmp(env); */
    abort();
    setjmp(env);

    /* longjmp(env,1); */

    return 0;
}

