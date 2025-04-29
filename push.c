#include "monty.h"
/**
 * push - function that push an integer into a stack
 */


void push(int number)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));

	if (!new_node){
		fprintf(stderr, "Error: malloc faile\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->next = the_stack;
	the_stack = new_node;
}	
