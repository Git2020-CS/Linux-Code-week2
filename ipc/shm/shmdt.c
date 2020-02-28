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
    ERROR_CHECK(shmid,-1,"shmget");
    /* printf("shmid = %d\n",shmid); */

    char *p = (char*)shmat(shmid,0,0);
    ERROR_CHECK(p,(char*)-1,"shmat");
    strcpy(p,"hello");
    printf("p=%p\n",p);

    /* int* p1 = (int*)shmat(shmid1,0,0); */
    /* printf("p1=%p\n",p1); */

    // 将共享内存段与进程空间分离
    shmdt(p);

    while(1);

    return 0;
}
