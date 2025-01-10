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

void init_chunk(t_chunk *chunk)
{
	pre_sort(chunk->sorted);
	if(chunk->sorted->size <= 10)
		chunk->offset = chunk->sorted->size / 5;
	else if(chunk->sorted->size <= 150)
		chunk->offset = chunk->sorted->size / 8;
	else
		chunk->offset = chunk->sorted->size / 18;
	chunk->mid = chunk->sorted->size / 2;
	chunk->start = chunk->mid - chunk->offset;
	chunk->end = chunk->mid + chunk->offset;
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

int is_in_range(t_vec *stack, t_chunk *chunk,int start, int end)
{
	int i;
	int num;

	i = start;
	num = pop(stack);
	while(i < end)
	{
		if(num == chunk->sorted->vector[i])
			return (1);
		i++;
	}
	return (0);
}

int check_range(t_vec *stack,t_vec *sorted,int start,int end)
{
	int i;
	int is_in_range;
	int j;

	i = start;
	is_in_range = 0;
	while(i < end)
	{
		j = 0;
		while(j < stack->size)
		{
			if(sorted->vector[i] == stack->vector[j])
			{
				is_in_range = 1;
				break;
			}
			if(!is_in_range)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void update_offset(t_vec *stack_b,t_chunk *chunk)
{

	if(check_range(stack_b,chunk->sorted,chunk->start,chunk->mid))
	{
		if(chunk->start - chunk->offset >= 0)
			chunk->start -= chunk->offset;
		else
			chunk->start = 0;
	}
	if(check_range(stack_b,chunk->sorted,chunk->mid,chunk->end))
	{
		if(chunk->end + chunk->offset < chunk->sorted->size)
			chunk->end += chunk->offset;
		else
		chunk->end = chunk->sorted->size;
	}
}

int	big_sort(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
{
	int i;

	i = 0;
	while(!is_empty(stack_a))
	{
		update_offset(stack_b,chunk);
		if(is_in_range(stack_a,chunk,chunk->start,chunk->end))
		{
			if(execute(stack_a, stack_b, PB) == -1)
				return (-1);
			if(is_in_range(stack_b,chunk,chunk->mid,chunk->end))
			{
				if(execute(stack_a, stack_b, RB) == -1)
					return (-1);
			}
		}
		else
		{
			if(i < stack_a->size / 2)
			{
				if(execute(stack_a, stack_b, RA) == -1)
					return (-1);
			}
			else
			{
				if(execute(stack_a, stack_b, RRA) == -1)
					return (-1);
			}
		}
		printf("mid:%d\nstart: %d\nend:%d\n",chunk->mid,chunk->start,chunk->end);
		i++;
	}
	return (0);
}

void sort(t_chunk *chunk)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(chunk->sorted, &stack_a);
	init_chunk(chunk);
	// for(int i = 0; i < chunk->sorted->size; i++)
	// {
	// 	printf("%d\n",chunk->sorted->vector[i]);
	// }
	big_sort(stack_a, stack_b,chunk);
	// printf("stack_b\n");
	// for(int i = 0; i < stack_a->size; i++)
	// {
	// 	printf("%d\n",stack_a->vector[i]);
	// }
	printf("size: %d\n",stack_b->size);
	for(int i = 0; i < stack_b->size; i++)
	{
		printf("%d\n",stack_b->vector[i]);
	}
}
