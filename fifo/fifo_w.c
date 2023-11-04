#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd, cc;
    char buf[2048];
    
    if ((fd = open(argv[1], O_WRONLY)) < 0) {
        perror("open error");
    }
    printf("argc:%d\n", argc);

    int i = 0;
    while (1) {   
        sprintf(buf, "hello fifo %d\n", i++);

        write(fd, buf, strlen(buf));
      
        sleep(1);
    }
    
    if (close(fd) < 0) {
        perror("close error");
    }
    return 0;
}
