#include <unistd.h>
#include <stdio.h>
#include <signal.h>

 void print_set(sigset_t *set){
    int i;
    for (i = 1; i <= 32; i++) {
        if (sigismember(set, i)){
            putchar('1');
        }else {
            putchar('0');
        }
    }
    printf("\n");
 }

 int main() {

    sigset_t set, old_set, pedset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    int t = sigprocmask(SIG_BLOCK, &set, &old_set);

    while (1)
    {
        sigpending(&pedset);
        print_set(&pedset);
        sleep(1);
    }

    return 0;
 }