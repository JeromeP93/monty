#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file (unused)
 * Return: no return
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @new_value: new_value
 * @stack: Pointer to the top of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int new_value)
{
	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = new_value;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * addnode - add node to the head stack
 * @stack: Pointer to the top of the stack
 * @new_value: new_value
 * Return: no return
*/
void addnode(stack_t **stack, int new_value)
{

	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = new_value;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
