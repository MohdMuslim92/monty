#include"monty.h"
/**
 * free_stack - free function
 * Description: Function that frees the stack based linked list
 * @topptr: pointer to the top node in the stack
*/
void free_stack(stack_t **topptr)
{
	stack_t *temp;

	while (*topptr != NULL)
	{
		temp = *topptr;
		*topptr = (*topptr)->prev;
		if (*topptr != NULL)
			(*topptr)->next = NULL;
		free(temp);
	}
}
