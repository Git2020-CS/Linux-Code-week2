/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
    > 从共享内存中读取数据,共享内存中的数据读取后不会消失，下次读仍然能读出来
 ************************************************************************/

#include <func.h>

int main(int argc,char *argv[])
{
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    /* printf("shmid = %d\n",shmid); */

    /* int shmid_private = shmget(IPC_PRIVATE,4096,IPC_CREAT); */

    // 传递字符串
    /* char *p = (char*)shmat(shmid,0,0); */
    /* ERROR_CHECK(p,(char*)-1,"shmat"); */
    /* puts(p); */
    /* printf("p=%s\n",p); */
    /* printf("p=%p\n",p); */

    // 传递整形数
    int *p = (int*)shmat(shmid,0,0);
    printf("p=%d\n",*p);

    while(1);

    return 0;
}
