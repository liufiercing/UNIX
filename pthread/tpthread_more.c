#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


void *tfun(void* arg){
    int i = (int) arg; 
    sleep(i);
    printf("I'm %dth, thread pid = %d; tid = %lu\n", i + 1, getpid(), pthread_self());
    return NULL;
}


int main () {
    pthread_t tid;
    int i;
    for (i = 0; i < 5; i++){
        tid = pthread_create(&tid, NULL, tfun, (void *)i); //i传递地址不好 i会改变 值传递 强转
        if (tid != 0) {
            perror("pthread create error");
        }
        // sleep(1);
    }
    sleep(i);
    printf("main pid = %d; tid = %lu\n", getpid(), pthread_self());
    return 0;
}