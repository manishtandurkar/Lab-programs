#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: rm file\n");
        return 1;
    }
    int output_fd = unlink(argv[1]);
    if(output_fd == -1) {
        perror("unlink error");
        return 3;
    }
}