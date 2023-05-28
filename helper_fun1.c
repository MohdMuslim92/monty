#include"monty.h"
/**
 * handleDiv - helper function
 * Description: a function that calls another function to
 *				devide the value of the second top two element of the stack by the top
 *				element of the stack
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handleDiv(stack_t **ptr, int line_num, int *err_flag)
{
	division(ptr, err_flag);
	if (*err_flag == 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		return;
	}
	if (*err_flag == 2)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		*err_flag = 1;
		return;
	}
}


/**
 * handleMod - helper function
 * Description: a function that calls another function to
 *				computes the rest of the division of the second top element of the stack
 *				by the top element of the stack
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handleMod(stack_t **ptr, int line_num, int *err_flag)
{
	mod(ptr, err_flag);
	if (*err_flag == 1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		return;
	}
	if (*err_flag == 2)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		*err_flag = 1;
		return;
	}
}

/**
 * handlePall - helper function
 * Description: a function that calls printing function to
 *				print stack elements
 * @ptr: pointer to the top of the stack
 *				updatecld if an error happened
*/
void handlePall(stack_t **ptr)
{
	pall(ptr);
}

/**
 * handlePint - helper function
 * Description: a function that calls another function to
 *				print the top element in the stack
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handlePint(stack_t **ptr, int line_num, int *err_flag)
{
	pint(ptr, err_flag);
	if (*err_flag == 1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		return;
	}
}

/**
 * handlePop - helper function
 * Description: a function that calls another function to
 *				remove the top element in the stack
 * @ptr: pointer to the top of the stack
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handlePop(stack_t **ptr, int line_num, int *err_flag)
{
	pop(ptr, err_flag);
	if (*err_flag == 1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		return;
	}
}
