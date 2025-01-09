#include "push_swap.h"

void pre_sort(t_vec *sorted)
{
	int i;
	int j;
	int temp;

	i = 0;
	while(i < sorted->size)
	{
		j = i + 1;
		while(j < sorted->size)
		{
			if(sorted->vector[i] > sorted->vector[j])
			{
				temp = sorted->vector[i];
				sorted->vector[i] = sorted->vector[j];
				sorted->vector[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void push_to_stack(t_vec *sorted, t_vec **stack_a)
{
	int i;

	i = 0;
	while(i < sorted->size)
	{
		push(*stack_a, sorted->vector[i]);
		i++;
	}
}

void sort(t_vec *sorted)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(sorted, &stack_a);
	pre_sort(sorted);
}
