/*************************************************************************
	> File Name: daemon.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 17:10:47
 ************************************************************************/

#include <func.h>

int main()
{
    if(fork())
    {
        exit(0);
    }

    setsid();

    for(int i=0;i<3;i++)
    {
        close(i);
    }

    chdir("/");
    umask(0);

    while(1);

    return 0;
}
