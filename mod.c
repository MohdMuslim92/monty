#include"monty.h"
/**
 * mod - division function
 * Description: Function that computes the rest of the division of the second
 *				top element of the stack by the top element of the stack
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag that it's value is 0 and will be updated
 *				if the stack is empty
*/

void mod(stack_t **topptr, int *err_flag)
{
	stack_t *temp;
	int num1, num2, result;

	if (*topptr == NULL || (*topptr)->prev == NULL)
	{
		*err_flag = 1;
		return;
	}
	num1 = (*topptr)->n;
	num2 = (*topptr)->prev->n;
	if (num1 == 0)
	{
		*err_flag = 2;
		return;
	}
	result = num2 % num1;
	(*topptr)->prev->n = result;

	temp = *topptr;
	*topptr = temp->prev;
	if (*topptr != NULL)
		(*topptr)->next = NULL;
	free(temp);
}
