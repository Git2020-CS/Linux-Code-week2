/*************************************************************************
  > File Name: daemon2.c
  > Author: Name
  > Mail: Name@163.com 
  > Created Time: 2020-01-10 21:34:37
  > 复杂一点的守护进程，fork两次，第二次fork是为了把原来的会话组组长与控制终端分离。
 ************************************************************************/

#include <func.h>


void init_daemon() {
    pid_t pid;
    int i;

    pid = fork();
    if (pid>0) {//是父进程，结束父进程
        exit(0);
    } else if (pid < 0) {//fork()失败
        perror("fork");
    }

    //是第一子进程，继续执行
    setsid();//第一子进程成为新的会话组长和进程组长，并与控制终端分离，为了防止其再打开一个控制终端，再调用一次fork()
    pid = fork();
    if (pid > 0) {//是第一子进程，结束第一子进程
        exit(0);
    } else if (pid < 0) {//fork()失败
        exit(1);
    }

    //是第二子进程，继续执行，已经不再是会话组长，执行关闭文件描述符操作
    for (i = 0; i < 10; i++) {
        close(i);
    }

    //改变工作目录
    chdir("/tmp");

    //重设文件创建掩模
    umask(0);

    //重定向标准输入、标准输出、标准错误输出到/dev/NULL
    /*
     * STDERR_FILENO = 2 标准错误输出
     * STDIN_FILENO = 0 标准输入
     * STDOUT_FILENO = 1 标准输出
     */
    int fp = open("/dev/null", O_RDWR);
    dup2(fp, STDERR_FILENO);
    dup2(fp, STDIN_FILENO);
    dup2(fp, STDOUT_FILENO);

    //处理SIGCHLD信号
    signal(SIGCHLD,SIG_IGN);
    return;
}

int main() {
    FILE *fp;
    time_t t;
    init_daemon();

    while (1) {
        sleep(10);//睡眠10妙
        fp = fopen("test.log", "a");
        if (fp != NULL) {
            time(&t);
            fprintf(fp, "Now time is %s\r\n", asctime(gmtime(&t)));
            fclose(fp);
        }
    }
}

