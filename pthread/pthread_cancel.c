#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int val = 100;

void *tfun(void* arg){
    while (1) {
        printf("pid = %d; tid = %lu\n", getpid(), pthread_self());
        sleep(1);
        // pthread_testcancel();
    }    
    return NULL;
}


int main () {
    pthread_t tid;
 
    tid = pthread_create(&tid, NULL, tfun, NULL);
    if (tid != 0) {
        perror("pthread create error");
    }

    sleep(2);
    pthread_cancel(tid);  // 线程需要取消点

    printf("pid = %d\n", getpid());
    return 0;
}