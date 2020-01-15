/*************************************************************************
	> File Name: pipe1.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 20:26:46
 ************************************************************************/

#include <func.h>

int fds[2]; //定义int类型的数据用于保存管道的读写两端
char buf[64]={0};

int test1()
{
    // 0是读端，往fds[0]写数据会出错Bad file descriptor
    int ret = write(fds[0],buf,strlen(buf));
    if(ret <= 0)
    {
        perror("write");
        return -1;
    }

    return 0;
}

int test2()
{
    close(fds[0]);
    int ret = write(fds[1],buf,sizeof(buf));
    if(ret <= 0)
    {
        perror("write pipe");
        return -1;
    }

    return 0;
}

int main()
{
    pipe(fds);
    strcpy(buf,"hello there");

    /* test1(); */
    /* memset(buf,0,sizeof(buf)); */

    strcpy(buf,"hello wangdao");
    test2();

    read(fds[1],buf,sizeof(buf));
    printf("read buf = %s\n",buf);

    return 0;
}
