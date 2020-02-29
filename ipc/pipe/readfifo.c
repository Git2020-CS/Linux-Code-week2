/*************************************************************************
	> File Name: fifo.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 14:09:33
    > 命名管道fifo文件的使用
 ************************************************************************/

#include <func.h>

int main()
{
    int readfd= open("fifo1",O_RDONLY);

    char buf[128]={0};

    read(readfd,buf,sizeof(buf));
    printf("read buf = %s\n",buf);

    int writefd = open("fifo2",O_WRONLY);

    strcpy(buf,"hello,this is fifo");
    int ret = write(writefd,buf,strlen(buf));
    printf("ret = %d\n",ret);

    return 0;

}

