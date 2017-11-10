#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char **argv) {
    int infd;
    int outfd;
    if (argc != 3) {
        fprintf(stderr, "Usage %s src dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    infd = open(argv[1], O_RDONLY | O_SYNC);
    if (infd == -1) {
        ERR_EXIT("open src error");
    }

    if ((outfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        ERR_EXIT("open dest error\n");
    }
    char buff[1024];
    memset(buff, 0, 1024);
    int nread = 0;
    while ((nread = read(infd, buff, 1024)) > 0) {
        printf("the character of the first byte of the buffer is %c\n", buff[0]);
        write(outfd, buff, nread);
    }
    close(infd);
    close(outfd);
    return 0;
}


