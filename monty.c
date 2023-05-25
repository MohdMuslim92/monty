#include"monty.h"
/**
 * main - Entry point
 * Description: Main program function that receive
 *				the byte code file as argv[1] and
 *				parse it line by line then calls
 *				the needed function to execute the instruction
 * @argc: number of arguments
 * @argv: arguments passed to the main program
 * Return: return 0 for success or exit with (EXIT_FAILURE) when error occures
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *ptr = NULL;
	char line[256];
	int err_flag = 0, line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening the file.\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		processLine(line, &ptr, line_num, &err_flag);
		line_num++;
		if (err_flag)
		{
			free_stack(&ptr);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(&ptr);

	return (0);
}

