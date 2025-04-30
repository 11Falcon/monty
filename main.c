#include "monty.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

stack_t *the_stack = NULL; /* Global stack used throughout the program */

/**
 * main - function for testing our knowledge
 *
 * @argc: number of inputs
 * @argv: the input file
 * Return: 0 on sucess
 */

int main(int argc, char *argv[])
{
	ssize_t count;
	int fd;
	int Limit = 200;
	int line = 0;
	char *list;
	char *book = malloc(Limit);

	if (argc != 2)
	{
		dprintf(stderr, "Usage : file\n");
		exit(EXIT_FAILURE);
	}
	if (!book)
	{
		dprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}


	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	count = read(fd, book, Limit - 1);
	book[count] = '\0';
	list = strtok(book, "\n");
	while (list)
	{
		line++;
		process(list, line);
		list = strtok(NULL, "\n");
	}
	free(book);
	close(fd);
	return (0);
}

/**
 * process - processing line command
 * @command: the line commande
 * @line: the line of that commande in the file
 */

void process(char *command, int line)
{
	int i, j, the_number;
	char *test, *p;
	int found = 0, length = strlen(command);

	for (i = 0; i <= length; i++)
	{
		if (command[i] == ' ')
			continue;
		j = 0;
		test = "push";
		while (test[j] == command[j + i])
			j++;
		if (j == 4)
		{
			while (command[i + j] == ' ')
				j++;
			the_number = atoi(&command[i + j]);
			found = 1;
			push(the_number);
			i += 4;
		}
		j = 0;
		p = "pall";
		while (p[j] == command[j + i] && j <= 3)
			j++;
		if (j == 4 && (command[j + i + 1] == ' ' || command[j + i + 1] == '\0'))
		{
			while (command[i + j] == ' ')
				j++;
			pall();
			found = 1;
			i += 4;
		}
	}
	if (found == 0)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>", line);
		exit(EXIT_FAILURE);
	}
}


