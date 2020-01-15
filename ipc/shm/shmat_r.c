/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
 ************************************************************************/

#include <func.h>

int main(int argc,char *argv[])
{
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    /* printf("shmid = %d\n",shmid); */
    /* int shmid1 = shmget(1000,4096,IPC_CREAT); */

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

    return 0;
}
