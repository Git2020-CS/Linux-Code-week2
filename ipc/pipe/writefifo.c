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
    int writefd = open("fifo1",O_WRONLY);

    char buf[128]={0};
    strcpy(buf,"helloworld");

    write(writefd,buf,strlen(buf));

    int readfd = open("fifo2",O_RDONLY);
    read(readfd,buf,sizeof(buf));

    printf("read  buf = %s\n",buf);

    return 0;

}

