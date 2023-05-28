#include"monty.h"
/**
 * mul - multiply function
 * Description: Function that multiply the value of the top two elements
 *				 in the stack together and remove the top element
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag that it's value is 0 and will be updated
 *				if the stack is empty
*/

void mul(stack_t **topptr, int *err_flag)
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
	result = num1 * num2;
	(*topptr)->prev->n = result;

	temp = *topptr;
	*topptr = temp->prev;
	if (*topptr != NULL)
		(*topptr)->next = NULL;
	free(temp);
}
