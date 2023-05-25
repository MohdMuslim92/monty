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
	char *token, *strptr;
	const char *delimiter = " \t\n";
	long int number;

	token = strtok(line, delimiter);
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delimiter);
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
		}
		if (strcmp(token, "pall") == 0)
		{
			pall(ptr);
		}

		token = strtok(NULL, delimiter);
	}
}
