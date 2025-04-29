#include "monty.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
/**
 * main - function for testing our knowledge
 */
stack_t *the_stack = NULL;

int main(int argc, char *argv[])
{
	ssize_t count;
	int fd;
	int Limit = 200;
	char *list;
	char *book = malloc(Limit);

	if (argc != 2){
		fprintf(stderr, "Usage : %s <filename>\n", argv[0]);
		return 1;
	}
	if (!book){
		fprintf(stderr, "Memory allocation error");
		return 1;
	}


	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "file doesn't existe , check again the name of the file");
		return 1;
	}

	count = read(fd, book, Limit - 1);
	book[count] = '\0';
        list = strtok(book, "\n");
        while(list){
		process(list);
                list = strtok(NULL, "\n");
        }
	free(book);
	close(fd);


	return 0;
}

void process(char* command)
{
	int i, j, the_number;
	char* test;
	char* p;
	int length = strlen(command);

	for (i = 0; i <= length; i++){
		if (command[i] == ' ')
			continue;
		j = 0;
		test = "push";
		while ( test[j]== command[j + i]){
			j++;
		}
		if (j == 4){
			while (command[i + j] == ' ')
				j++;
			the_number = atoi(&command[i + j]);
			push(the_number);
			i =+ 4;
		}
		j = 0 ;
		p = "pall";
		while ( p[j] == command[j + i] && j <= 3){
			j++;
		}
		if (j == 4 && (command[j + i + 1] == ' ' || command[j + i + 1] == '\0') ){
			while (command[i + j] == ' ')
				j++;
			pall();
			i += 4;
		}
	}
}


