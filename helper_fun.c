#include"monty.h"
/**
 * handleUnknownInstruction - helper function
 * Description: a function that print an error to the standard
 *				error outbot when the instruction is not valid
 *@token: pointer to token to be tokenize
 * @line_num: the line number which used when printing an error if happened
 * @err_flag: an error flag that it's value 0 and will be
 *				updatecld if an error happened
*/
void handleUnknownInstruction(char *token, int line_num, int *err_flag)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
	*err_flag = 1;
}
