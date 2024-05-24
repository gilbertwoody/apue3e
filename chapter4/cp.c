#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

int main(int argc, char * argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s src-file dest-file", argv[0]);
        exit(1);
    }

    int fd1, fd2;

    fd1 = open(argv[1], O_RDONLY);
    if (fd2 < 0) {
        fprintf(stderr, "Open dest-file %s error", argv[0]);
        exit(3);
    }
    
    fd2 = open(argv[2], O_CREAT|O_WRONLY);
    if (fd2 < 0) {
        fprintf(stderr, "Open dest-file %s error", argv[0]);
        exit(3);
    }

    off_t hole, data;
    struct stat buf;

    data = hole = 0;
    fstat(fd1, &buf);
    while (hole < buf.st_size) {
        data = lseek(fd1, hole, SEEK_DATA);
        hole = lseek(fd1, data, SEEK_HOLE);
        lseek(fd1, data, SEEK_SET);
        lseek(fd2, data, SEEK_SET);
        
        char * buf = (char *) malloc(hole - data);
        read(fd1, buf, hole - data);
        write(fd2, buf, hole - data);
    }

    return 0;
}
