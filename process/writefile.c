 ///
 /// @file    writefile.c
 /// @author  ken
 /// @date    2020-01-03 01:32:19
 ///
 
#include <func.h>
 
int main()
{
    printf("pid=%d,uid=%d,gid=%d\n",getpid(),getuid(),getgid());
    printf("euid=%d,egid=%d\n",geteuid(),getegid());
    int fd = open("file",O_RDWR);
    printf("fd=%d\n",fd);
    int ret = write(fd,"hello",5);
    if(ret != 5)
    {
        perror("write");
        return -1;
    }

    return 0;
 
}
