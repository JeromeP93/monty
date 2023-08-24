#include "monty.h"

/**
  *sub - Subtracts the top element from the second top element.
  *@stack: Pointer to the top of the stack
  *@line_number: Line number in the Monty file (unused)
  *Return: no return
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int sus, nodes;

	aux = *stack;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stack = aux->next;
	free(aux);
}
