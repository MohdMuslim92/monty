#include"monty.h"
/**
 * pchar - letter print function
 * Description: Function that prints the char at the top of the stack, followed
 * by a new line
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag that it's value is 0 and will be updated
 *				if the stack is empty
*/

void pchar(stack_t **topptr, int *err_flag)
{
	int num;
	char letter;

	if (*topptr == NULL)
	{
		*err_flag = 1;
		return;
	}
	num = (*topptr)->n;
	if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
	{
		letter = (char)num;
		printf("%c\n", letter);
	} else
	{
		*err_flag = 2;
		return;
	}
}
