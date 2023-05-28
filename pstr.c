#include"monty.h"
/**
 * pstr - print function
 * Description: Function that prints the string starting at the top of the
 *				stack, followed by a new line
 * @topptr: pointer to the top node in the stack
*/

void pstr(stack_t **topptr)
{
	stack_t *temp;

	temp = *topptr;

	while (temp && temp->n != 0)
	{
		if (temp->n < 32 || temp->n > 126)
		{
			break;
		}
		printf("%c", (char)temp->n);
		temp = temp->prev;
	}

	printf("\n");
}
