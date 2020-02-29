 ///
 /// @file    uid.c
 /// @author  ken
 /// @date    2020-01-03 01:01:28
 ///
 
#include <func.h>
 
int main()
{
    printf("pid=%d,uid=%d,gid=%d\n",getpid(),getuid(),getgid());
    printf("euid=%d,egid=%d\n",geteuid(),getegid());
    while(1);
    return 0;
 
}
