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

void push_to_stack(t_vec *sorted, t_vec **stack)
{
	int i;

	i = sorted->size - 1;
	while(i >= 0)
	{
		push(*stack, sorted->vector[i]);
		i--;
	}
}

int is_in_range(t_vec *stack, t_chunk *chunk, int start, int end)
{
    if (!stack || !chunk || start < 0 || end > chunk->sorted->size)
	{
        return (0);
	}
    while (start < end)
    {
        if (stack->vector[stack->size - 1] == chunk->sorted->vector[start])
            return (1);
        start++;
    }
    return (0);
}

int check_range(t_vec *stack,t_vec *sorted,int start,int end)
{
	int i;
	int is_in_range;
	int j;

    if (!stack || !sorted || start < 0 || end > sorted->size)
	{
    	return (0);
	}
	i = start;
	while(i < end)
	{
		j = 0;
		is_in_range = 0;
		while(j < stack->size)
		{
			if(sorted->vector[i] == stack->vector[j])
			{
				is_in_range = 1;
				break;
			}
			j++;
		}
		if(!is_in_range)
			return (0);
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


int push_to_b(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
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
		i++;
	}
	return (0);
}

int find_max(t_vec *stack)
{
	int i;
	int max;

	i = 0;
	max = stack->vector[0];
	while(i < stack->size)
	{
		if(stack->vector[i] > max)
			max = i;
		i++;
	}
	return (max);
}

int push_back(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
{
	int max;
	(void)chunk;
	while(!is_empty(stack_b))
	{
		max = find_max(stack_b);
		if(stack_b->vector[stack_b->size - 1] == stack_b->vector[max])
		{
			if(execute(stack_a, stack_b, PA) == -1)
				return (-1);
		}
		else
		{
			if(is_empty(stack_a) || stack_b->vector[stack_b->size - 1] > stack_a->vector[0])
			{
				if(execute(stack_a, stack_b, PA) == -1)
					return (-1);
				if(execute(stack_a, stack_b, RA) == -1)
					return (-1);
			}
			else
			{
				if(max <= stack_b->size / 2)
				{
					if(execute(stack_a, stack_b, RB) == -1)
						return (-1);
				}
				else
				{
					if(execute(stack_a, stack_b, RRB) == -1)
						return (-1);
				}
			}
		}
	}
	return (0);
}

int	big_sort(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
{
	if(push_to_b(stack_a,stack_b,chunk) == -1)
		return (-1);
	if(push_back(stack_a,stack_b,chunk) == -1)
		return (-1);
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
	big_sort(stack_a, stack_b,chunk);
	// for(int i = 0; i < stack_a->size; i++)
	// {
	// 	printf("%d\n",stack_a->vector[i]);
	// }
	// printf("----------------\n");
	// for(int i = 0; i < chunk->sorted->size; i++)
	// {
	// 	printf("%d\n",chunk->sorted->vector[i]);
	// }
	// printf("----------------\n");
	// for(int i = stack_b->size - 1; i >= 0; i--)
	// {
	// 	printf("%d\n",stack_b->vector[i]);
	// }
}

