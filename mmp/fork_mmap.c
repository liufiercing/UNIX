#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd, cc, len;
    char buf[2048];
    char *p = NULL;

    fd = open("gogo", O_RDWR | O_CREAT |O_TRUNC, 0644);
    // fd = open("gogo", O_RDWR | O_CREAT , 0644);
    if (fd < 0) {
        perror("open error");
    }
    ftruncate(fd, 20);
    len = lseek(fd, 0, SEEK_END);
    
    p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (close(fd) < 0) {
        perror("close error");
    }

    int pid = fork();    
    if (pid < 0) {
        perror("fork error");
    } else if (pid == 0) {
        strcpy(p, "helle mmap\n");
    } else {
        sleep(1);
        printf("%s", p);
        wait(NULL);
    }
    munmap(p, len);

    return 0;
}
