#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    ssize_t count;
    int fd;
    int Limit = 200;
    char *book = malloc(Limit);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (!book) {
        perror("Memory allocation failed");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        free(book);
        return 1;
    }

    count = read(fd, book, Limit - 1);
    if (count == -1) {
        perror("Error reading file");
        free(book);
        close(fd);
        return 1;
    }

    book[count] = '\0';  // Null-terminate the buffer
    printf("%s\n", book);

    free(book);
    close(fd);
    return 0;
}

