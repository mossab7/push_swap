#include "push_swap.h"

void	push_to_stack(t_vec *sorted, t_vec **stack_a)
{
	int i;

	i = sorted->size - 1;
	while(i >= 0)
	{
		push(*stack_a,sorted->vector[i]);
		i--;
	}
}

void stack_sort(t_vec *stack)
{
	int i;
	int j;
	int temp;

	i = 0;
	while(i < stack->size)
	{
		j = i + 1;
		while(j < stack->size)
		{
			if(stack->vector[i] > stack->vector[j])
			{
				temp = stack->vector[i];
				stack->vector[i] = stack->vector[j];
				stack->vector[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void stack_index_dereference(t_vec *sorted, t_vec *stack_a)
{
	int i;
	int j;

	i = 0;
	while(i < stack_a->size)
	{
		j = 0;
		while(j < sorted->size)
		{
			if(stack_a->vector[i] == sorted->vector[j])
			{
				stack_a->vector[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void	stack_p(t_vec *stack)
{
	int i;

	i = stack->size - 1;
	while(i >= 0)
	{
		printf("%d\n",stack->vector[i]);
		i--;
	}
}

int all_in_range(t_vec *sorted, int start, int end, t_vec *stack_b)
{
    int i;
    int j;
    int found;

    found = 0;
    i = start;
    while (i <= end)
    {
        j = 0;
        while (j < stack_b->size)
        {
            if (stack_b->vector[j] == sorted->vector[i])
            {
                found = 1;
                break;
            }
            j++;
        }
        if (!found)
        {
            return 0;
        }
        found = 0;
        i++;
    }
    return 1;
}

void update_offset(t_chunk *chunk,t_vec *stack_b)
{
	if(all_in_range(chunk->sorted,chunk->start,chunk->mid,stack_b))
	{
		if(chunk->start - chunk->offset < 0)
			chunk->start = 0;
		else
			chunk->start -= chunk->offset;
	}
	if(all_in_range(chunk->sorted,chunk->mid + 1,chunk->end,stack_b))
	{
		if(chunk->end + chunk->offset > chunk->sorted->size - 1)
			chunk->end = chunk->sorted->size - 1;
		else
			chunk->end += chunk->offset;
	}
}

int in_range(int value, t_vec *sorted, int start, int end)
{
	int i;

	i = start;
	while(i <= end)
	{
		if(value == sorted->vector[i])
			return (1);
		i++;
	}
	return (0);
}

void init_chunk(t_chunk *chunk)
{
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

int get_pos(t_vec *stack_a, t_chunk *chunk)
{
	int i;
	int pos;

	pos = 0;
	i = stack_a->size - 1;
	while(i >= 0)
	{
		if(in_range(stack_a->vector[i],chunk->sorted,chunk->start,chunk->end))
			return (pos);
		i--;
		pos++;
	}
	return (-1);
}

void push_to_b(t_vec *stack_a, t_vec *stack_b,t_chunk *chunk)
{
	int pos;
	while(!is_empty(stack_a))
	{
		pos = get_pos(stack_a,chunk);
		while(pos > 0)
		{
			execute(stack_a,stack_b,RA);
			pos--;
		}
		execute(stack_a,stack_b,PB);
		if(in_range(stack_b->vector[stack_b->size - 1],chunk->sorted,chunk->start,chunk->mid - 1))
			execute(stack_a,stack_b,RB);
		update_offset(chunk,stack_b);
	}
}

int get_max_pos(t_vec *stack_b, int max)
{
	int i;
	int pos;
	i = stack_b->size - 1;
	pos = 0;
	while(i >= 0)
	{
		if(stack_b->vector[i] == max)
			return (pos);
		i--;
		pos++;
	}
	return (-1);
}

void push_back_to_a(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
{
	int down;
	int max;
	int pos;
	down = 0;


	while(!is_empty(stack_b))
	{

		max = chunk->sorted->vector[chunk->sorted->size - 1];
		pos = get_max_pos(stack_b,max);
		if(pos >= 0)
		{
			if(max == stack_b->vector[stack_b->size - 1])
			{
				execute(stack_a,stack_b,PA);
				chunk->sorted->size -= 1;
			}
			else if(down == 0 || stack_b->vector[stack_b->size - 1] > stack_a->vector[0])
			{
				execute(stack_a,stack_b,PA);
				execute(stack_a,stack_b,RA);
				down++;
			}
			else
			{
				if(pos <= stack_b->size / 2)
					execute(stack_a,stack_b,RB);
				else
					execute(stack_a,stack_b,RRB);
			}
		}
		else
		{
			execute(stack_a,stack_b,RRA);
			down--;
			chunk->sorted->size -= 1;
		}
	}
	while(down--)
		execute(stack_a,stack_b,RRA);
}

void	sort(t_chunk *chunk)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(chunk->sorted,&stack_a);
	stack_sort(chunk->sorted);
	init_chunk(chunk);
	push_to_b(stack_a,stack_b,chunk);
	// printf("start: %d\n",chunk->start);
	// printf("mid: %d\n",chunk->mid);
	// printf("end: %d\n",chunk->end);
	// printf("offset: %d\n",chunk->offset);
	// printf("size: %d\n",chunk->sorted->size);
	//stack_p(stack_a);
	//stack_index_dereference(chunk->sorted, stack_a);
	//pre_sort(stack_a,stack_b);
	//big_sort(stack_a,stack_b);
	// stack_p(stack_a);
	// printf("sorted 1 %d\n",chunk->sorted->vector[0]);
	// printf("sorted size %d\n",chunk->sorted->vector[chunk->sorted->size - 1]);
	push_back_to_a(stack_a,stack_b,chunk);
}
