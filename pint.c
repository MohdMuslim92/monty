#include"monty.h"
/**
 * pint - print function
 * Description: Function that prints the element at the top of the stack
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag which it's value is 0 and will be updated
 *			if the stack is empty
*/

void pint(stack_t **topptr, int *err_flag)
{
	stack_t *temp;

	temp = *topptr;
	if (temp == NULL)
	{
		*err_flag = 1;
		return;
	}

		printf("%d\n", temp->n);
}
