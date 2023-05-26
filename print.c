#include"monty.h"
/**
 * pall - print function
 * Description: Function that prints elements in the stack
 * @topptr: pointer to the top node in the stack
*/

void pall(stack_t **topptr)
{
	stack_t *temp;

	temp = *topptr;

	if (temp == NULL)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
