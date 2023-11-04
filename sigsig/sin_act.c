#include <unistd.h>
#include <stdio.h>
#include <signal.h>

 void sig_catch(int signo){
   printf("we cath: %d\n", signo);
   return;
 }

 int main() {

    struct sigaction act, oldact;

    act.sa_handler = sig_catch;   // set callback function name       设置回调函数
    sigemptyset(&(act.sa_mask));    // set mask when sig_catch working. 清空sa_mask屏蔽字, 只在sig_catch工作时有效
    act.sa_flags = 0;   // usually use.                     默认值

    sigaction(SIGINT, &act, &oldact);
    sigaction(SIGQUIT, &act, &oldact);

    while (1);
    return 0;
 }