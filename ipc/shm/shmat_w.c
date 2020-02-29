/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
    > 向共享内存中写数据，写到共享内存中后，就算程序结束，共享内存中的内容也不会结束
 ************************************************************************/

#include <func.h>

int main(int argc,char *argv[])
{

    int shmid = shmget(1000,1<<12,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");

    //传递字符串
    /* char *p = (char*)shmat(shmid,0,0); */
    /* ERROR_CHECK(p,(char*)-1,"shmat"); */
    /* strcpy(p,"hello shm"); */

    //传递整形数
    int* p = (int*)shmat(shmid,0,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    *p = 3;

    return 0;
}
