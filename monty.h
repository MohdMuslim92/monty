#ifndef MONTY_H
#define MONTY_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void processLine(char *line, stack_t **ptr, int line_num, int *err_flag);

void push(stack_t **topptr, int data);
void pall(stack_t **topptr);
void pint(stack_t **topptr, int *err_flag);
void pop(stack_t **topptr, int *err_flag);
void free_stack(stack_t **topptr);
int empty_or_comment(const char *line);
void swap(stack_t **topptr, int *err_flag);
void nop(void);
void pchar(stack_t **topptr, int *err_flag);
void pstr(stack_t **topptr);

void add(stack_t **topptr, int *err_flag);
void sub(stack_t **topptr, int *err_flag);
void division(stack_t **topptr, int *err_flag);
void mul(stack_t **topptr, int *err_flag);
void mod(stack_t **topptr, int *err_flag);

void handlePush(char *token, stack_t **ptr, int line_num, int *err_flag);
void handlePall(stack_t **ptr);
void handlePint(stack_t **ptr, int line_num, int *err_flag);
void handlePop(stack_t **ptr, int line_num, int *err_flag);
void handleSwap(stack_t **ptr, int line_num, int *err_flag);
void handleAdd(stack_t **ptr, int line_num, int *err_flag);
void handleSub(stack_t **ptr, int line_num, int *err_flag);
void handleMul(stack_t **ptr, int line_num, int *err_flag);
void handleDiv(stack_t **ptr, int line_num, int *err_flag);
void handleMod(stack_t **ptr, int line_num, int *err_flag);
void handlePchar(stack_t **ptr, int line_num, int *err_flag);
void handlePstr(stack_t **ptr);
void handleUnknownInstruction(char *token, int line_num, int *err_flag);
#endif
