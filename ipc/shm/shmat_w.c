/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
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
