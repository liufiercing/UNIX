#include <unistd.h>
#include <stdio.h>
#include <signal.h>

 void sig_cath(int signo){
   printf("we cath: %d\n", signo);
   return;
 }

 int main() {
   signal(SIGINT, sig_cath);
   signal(SIGQUIT, sig_cath);
   while (1);
   return 0;
 }