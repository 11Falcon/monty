#include "monty.h"
void pall(void){
	stack_t *the_next = the_stack;
	
	while (the_next){
		printf("%d\n", the_next->n);
		the_next = the_next->next;
	}
}
