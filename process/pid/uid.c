 ///
 /// @file    uid.c
 /// @author  ken
 /// @date    2020-01-03 01:01:28
 ///
 
#include <func.h>
 
int main()
{
    printf("pid=%d,uid=%d,gid=%d\n",getpid(),getuid(),getgid());
    while(1);
    return 0;
 
}
