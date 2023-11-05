#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>

 void catch_child(int signo){
    pid_t wpid;
    while ((wpid = wait(NULL)) != -1)
    {
        printf("we cath child: %d\n", wpid);
    }
    return;
 }


int main(){
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);

    int i;
    for (i = 0; i < 25; i++) {
        pid_t f = fork();
        if (f == 0)
            break;
    }
    if (i == 25) {
        struct sigaction act;
        act.sa_handler = catch_child;   // set callback function name       设置回调函数
        sigemptyset(&(act.sa_mask));    // set mask when sig_catch working. 清空sa_mask屏蔽字, 只在sig_catch工作时有效
        act.sa_flags = 0;   // usually use.                     默认值

        printf("pid = %d\n", getpid());
        sigaction(SIGINT, &act, NULL);
        sigaction(SIGCHLD, &act, NULL);
        printf("I'am parent pid = %d\n", getpid());

        sigprocmask(SIG_UNBLOCK, &set, NULL);
        while (1);
  
    } else {   
        printf("I'am child pid = %d\n", getpid());
        // while (1);
    }

    return 0;
}