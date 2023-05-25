#include"monty.h"
/**
 * push - add function
 * Description: Function that push elements in the stack
 * @topptr: pointer to the top node in the stack
 * @data: data to be pushed to the stack
*/

void push(stack_t **topptr, int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(topptr);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = NULL;
	new_node->prev = *topptr;
	if (*topptr != NULL)
		(*topptr)->next = new_node;
	*topptr = new_node;
}
