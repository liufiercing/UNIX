#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    int f = fork();
   

    if (f != 0){
        printf("pid = %d\n", getpid());
        printf("gpid = %d\n", getppid());
        sleep(1);
    } else if (f == 0) {
        // execlp("date","-u", NULL);
        execlp("ls", "ls", "-l", "-h", NULL);
        perror("exec error");
        exit(1);
    }
    printf("end -------\n");
    



    return 0;
}

