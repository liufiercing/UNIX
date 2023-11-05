#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int val = 100;

struct thrd
{
    int val;
    char str[256];
};

void *tfun(void* arg){
    struct thrd *tval;  // 指针变量不能直接用 需要申请大小
    tval = malloc(sizeof(tval));
    tval->val = 100;
    strcpy(tval->str, "hello join");

    return (void *)tval;
}

int main () {
    pthread_t tid;
    struct thrd *retval;

    pthread_create(&tid, NULL, tfun, NULL);
  
    pthread_join(tid, (void**)&retval);
    
    printf("val = %d, str = %s\n", retval->val, retval->str);
    pthread_exit(NULL);
    // sleep(1);
    // printf("I'm main2: %d\n", val);
    // return 0;
}