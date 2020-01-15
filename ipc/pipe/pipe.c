/*************************************************************************
	> File Name: pipe.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 14:26:35
 ************************************************************************/

#include <func.h>

int main()
{
    int fds[2];
    pipe(fds);
    char buf[128]={0};
    int ret =0;

    if(fork())
    {
        /* close(fds[0]); */
        strcpy(buf,"this is parent");
        write(fds[1],buf,strlen(buf));
        memset(buf,0,sizeof(buf));

        // 写两次或者多次管道，可以一次读出来
        /* strcpy(buf," how are you"); */
        /* write(fds[1],buf,strlen(buf)); */

        sleep(10);

        memset(buf,0,sizeof(buf));
        read(fds[0],buf,sizeof(buf));
        printf("parent read : %s\n",buf);

        wait(NULL);
    }
    else{
        /* close(fds[1]); */
        ret = read(fds[0],buf,sizeof(buf));
        printf("child read ret = %d\n",ret);

        printf("child read : %s\n",buf);

        strcpy(buf,"this is child");
        ret = write(fds[1],buf,strlen(buf));
        printf("child write len=%d\n",ret);
    }
    return 0;
}
