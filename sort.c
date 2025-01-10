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

void update_start_end_chunks(t_chunk *chunk)
{
	int i;
	static int j = 1;
	static int k = 0;
	//TO DO : Fix the logic for the start and end chunks
	i = (chunk->sorted->size / 2) - (chunk->offset * j);
	while(i < chunk->sorted->size / 2)
	{
		push(chunk->start, chunk->sorted->vector[i]);
		i++;
	}
	i = (chunk->sorted->size / 2) + (chunk->offset * k);
	while(i >= chunk->offset)
	{
		push(chunk->end, chunk->sorted->vector[i]);
		i--;
	}
}

void init_chunk(t_chunk *chunk)
{
	pre_sort(chunk->sorted);
	constructor(&chunk->start);
	constructor(&chunk->end);
	if(chunk->sorted->size <= 10)
		chunk->offset = chunk->sorted->size / 5;
	else if(chunk->sorted->size <= 150)
		chunk->offset = chunk->sorted->size / 8;
	else
		chunk->offset = chunk->sorted->size / 18;
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

void sort(t_chunk *chunk)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(chunk->sorted, &stack_a);
	init_chunk(chunk);
	update_start_end_chunks(chunk);
	for(int i = 0; i < chunk->sorted->size; i++)
	{
		printf("%d\n",chunk->sorted->vector[i]);
	}
	big_sort(stack_a, stack_b,chunk);
}
