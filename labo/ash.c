#include "monty.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

stack_t *the_stack = NULL;

char* clean_line(char* input_string);

int main(int argc, char *argv[])
{
    ssize_t count;
    int fd;
    int Limit = 200;
    char *list;
    char *book = malloc(Limit);

    if (argc != 2) {
        fprintf(stderr, "Usage : %s <filename>\n", argv[0]);
        return 1;
    }

    if (!book) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "File doesn't exist, check the name of the file\n");
        free(book);
        return 1;
    }

    count = read(fd, book, Limit - 1);
    if (count == -1) {
        fprintf(stderr, "Error reading the file\n");
        free(book);
        close(fd);
        return 1;
    }
    book[count] = '\0';
    list = strtok(book, "\n");
    while (list) {
        char *cleaned_line = clean_line(list);
        printf("Cleaned Line: \"%s\"\n", cleaned_line);
        list = strtok(NULL, "\n");
    }

    free(book);
    close(fd);

    return 0;
}

char* clean_line(char* input_string)
{
    int start = 0;
    int end = strlen(input_string) - 1;

    while (input_string[start] == ' ' && start <= end) {
        start++;
    }

    while (input_string[end] == ' ' && end >= start) {
        end--;
    }

    input_string[end + 1] = '\0';

    return &input_string[start];
}
