/*************************************************************************
	> File Name: ftok.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-13 22:06:52
    > ftok 根据文件和数字生成一个唯一的数字
 ************************************************************************/

#include <func.h>

int main(int argc, char *argv[])
{
    key_t key;
    printf("argv[0] = %s\n",argv[0]);
    key = ftok(argv[1],1);
    printf("key1 = %d\n",key);

    key = ftok(argv[1],2);
    printf("key2 = %d\n",key);

    return 0;
}
