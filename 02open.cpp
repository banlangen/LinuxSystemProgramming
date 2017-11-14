#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif 
    //int open(const char *pathname, int flags);
    int open(const char*, int, ...);
    //DIR *opendir(const char *name);
#ifdef __cplusplus
};
#endif 

//#define ERR_EXIT(m) (perror(m), exit(EXIT_FAILURE))
#define ERR_EXIT(m) \
        do \
        { \
            perror(m); \
            exit(EXIT_FAILURE); \
        } while(0)

int main(void) {
    int fd;
    fd = open("text.txt", O_RDONLY | O_CREAT);
    if (fd == -1) {
        fprintf(stderr, "open error with errono=%d %s\n", errno, strerror(errno));
        // perror("oepn error:");
        //exit(EXIT_FAILURE);
        ERR_EXIT("open_error");
    }
    std::cout << "fd is : " << fd << std::endl;
    printf("open successful \n");
    return 0;
}
