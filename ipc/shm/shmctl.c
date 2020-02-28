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

    // RMID共享内存的删除时标记删除，
    // 只有当最后一个使用共享内存的进程解除映射之后才会真正删除
    void *p = shmat(shmid,0,0);
    ERROR_CHECK(p,(void*)-1,"shmat");

    printf("before rmid\n");
    sleep(3);
    int ret = shmctl(shmid,IPC_RMID,NULL);
    ERROR_CHECK(ret,-1,"shmctl");
    printf("after rmid\n");
    
    sleep(10);

    return 0;
}
