#include"monty.h"
/**
 * processLine - process function
 * Description: a function that process lines that get
 *				read from the bytecode file
 *				whenever it encounters the valid instruction
 *				it calls the appropriate function to perform the instruction
 * @line: pointer to the first of the line to be processed
 * @ptr: pointer to the top of the stack
 * @line_num: the line number to print in case
 *			there is an error performing the instruction
 * @err_flag: a flag with a value of 0 which will change
 *				to 1 to indicate that there is an error
 *				and get back to main to free the stack memory
*/
void processLine(char *line, stack_t **ptr, int line_num, int *err_flag)
{
	char *token;
	const char *delimiter = " \t\n";

	token = strtok(line, delimiter);
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delimiter);
			handlePush(token, ptr, line_num, err_flag);
			return;
		}
		else if (strcmp(token, "pint") == 0)
		{
			handlePint(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "pop") == 0)
		{
			handlePop(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "swap") == 0)
		{
			handleSwap(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "add") == 0)
		{
			handleAdd(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "sub") == 0)
		{
			handleSub(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "div") == 0)
		{
			handleDiv(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "mul") == 0)
		{
			handleMul(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "mod") == 0)
		{
			handleMod(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "pchar") == 0)
		{
			handlePchar(ptr, line_num, err_flag);
			return;
		} else if (strcmp(token, "pstr") == 0)
		{
			handlePstr(ptr);
			return;
		} else if (strcmp(token, "nop") == 0)
		{
			nop();
		} else if (strcmp(token, "pall") == 0)
		{
			handlePall(ptr);
		} else
		{
			handleUnknownInstruction(token, line_num, err_flag);
		}
		token = strtok(NULL, delimiter);
	}
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

