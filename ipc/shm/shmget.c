/*************************************************************************
	> File Name: shm.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 21:38:44
 ************************************************************************/

#include <func.h>

//通过一个key(key是为了保证唯一性),创建一个可多个进程共享的存储区
int shmGet1(char* file)
{
    key_t key= ftok(file,1);
    printf("key = %d\n",key);

    //如果对应的key还没有创建共享内存，就创建新的，如果已经创建，就获取id
    int shmid = shmget(key,4096,IPC_CREAT);
    int shmid1 = shmget(IPC_PRIVATE,4096,IPC_CREAT|0600);
    printf("shmid1 = %d\n",shmid1);

    // 增加了IPC_EXCL后，如果key对应的共享内存已经创建，会返回-1.
    /* int shmid = shmget(key,4096,IPC_CREAT|IPC_EXCL); */ 


    printf("shmid = %d\n",shmid);
    return 0;
}

// 通过IPC_PRIVATE的方式创建，该共享内存只能用于父子进程间共享
int shmGetPrivate()
{
    int shmid = shmget(IPC_PRIVATE,4096,IPC_CREAT);
    printf("private shmid = %d\n",shmid);
    return 0;
}

int main(int argc,char *argv[])
{
    shmGet1(argv[1]);

    shmGetPrivate();

    return 0;
}
