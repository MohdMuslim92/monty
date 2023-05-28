#include"monty.h"

/**
 * handlePchar - helper function
 * Description: a function that calls another function to
 *				print the char at the top of the stack, followed by a new line
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handlePchar(stack_t **ptr, int line_num, int *err_flag)
{
	pchar(ptr, err_flag);
	if (*err_flag == 1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		return;
	}
	if (*err_flag == 2)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		*err_flag = 1;
		return;
	}
}


/**
 * handlePstr - helper function
 * Description: a function that calls a function to prints the string starting
 *				at the top of the stack, followed by a new line
 * @ptr: pointer to the top of the stack
 *				updatecld if an error happened
*/
void handlePstr(stack_t **ptr)
{
	pstr(ptr);
}

/**
 * handlePush - helper function
 * Description: a function that tokenize the line and then call
 *				the function push and pass the number to it
 *				to push an element to the stack
 *@token: pointer to token to be tokenize
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handlePush(char *token, stack_t **ptr, int line_num, int *err_flag)
{
	char *strptr;
	long int number;

	if (token != NULL)
	{
		number = strtol(token, &strptr, 10);
		if (strptr == token)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			*err_flag = 1;
			return;
		}
		push(ptr, number);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		*err_flag = 1;
		return;
	}
}

