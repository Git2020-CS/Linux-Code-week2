/*************************************************************************
	> File Name: print.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-07 15:36:35
 ************************************************************************/

#include <func.h>

int main(int argc,char* argv[])
{
    printf("this is print\n");
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    return 0;
}
