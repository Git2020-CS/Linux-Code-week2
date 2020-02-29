/*************************************************************************
	> File Name: popen.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 17:55:02
    > popen 创建子进程，并且在父子进程有一条管道，父子进程之间可以通过
    > 管道进行通信
 ************************************************************************/

#include <func.h>

int main()
{
    FILE* fp = popen("./print","w");
    int ret = fwrite("hello\n",sizeof(char),6,fp);
    printf("write ret = %d\n",ret);

    pclose(fp);

    return 0;
}

