#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L /* to use dprintf in error messages */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h> /* to use stat */
#include <fcntl.h> /* to use open */
#include <unistd.h> /* to use write and print error messages */
extern int global_variable;

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

/* functions */
char *openfile(char *filename);
char **set_strtok(char *s, char delimeter);
void (*get_opcode(char *str, int counterline))(stack_t **, unsigned int);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void free_grid(char **grid);
int verify_digit(char *num);
void free_dlistint(stack_t *head);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

#endif
