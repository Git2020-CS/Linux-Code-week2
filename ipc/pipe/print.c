/*************************************************************************
	> File Name: print.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-01-10 17:58:00
 ************************************************************************/

#include <func.h>

int main()
{
    char buf[64]={0};

    fread(buf,sizeof(char),sizeof(buf),stdin);
    int i,j;
    scanf("%d%d",&i,&j);
    fgets(buf,sizeof(buf),stdin);
    printf("buf = %s\n",buf);
    return 0;
}

