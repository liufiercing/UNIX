#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd, cc, len;
    char buf[2048];
    
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open error");
    }

    
    while (1) {
        len = read(fd, buf, sizeof(buf));
        
        write(STDOUT_FILENO, buf, len);
        sleep(1);
    }
    
    if (close(fd) < 0) {
        perror("close error");
    }
    return 0;
}
