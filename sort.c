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

void	pre_sort(t_vec *stack_a, t_vec *stack_b)
{
	int i;
	int mid;
	i = 0;

	mid = stack_a->size / 2;
	while(stack_a->size > 1)
	{
		if(stack_a->vector[stack_a->size - 1] >= mid)
		{
			execute(stack_a,stack_b,PB);
			i++;
		}
		else
		{
			execute(stack_a,stack_b,PB);
			execute(stack_a,stack_b,RB);
		}
		i++;
	}
}

int get_position(t_vec *stack_a, t_vec *stack_b)
{
	int i;
	int pos;

	i = stack_b->size - 1;
	pos = 0;
	while(i >= 0)
	{
		if(stack_b->vector[i] - 1 == stack_a->vector[stack_a->size - 1])
		{
			return(pos);
			break;
		}
		else if(stack_b->vector[i] + 1 == stack_a->vector[0])
		{

			return(-pos);
			break;
		}
		pos++;
		i--;
	}
	return (0);
}


void big_sort(t_vec *stack_a, t_vec *stack_b)
{
	int pos;
	int i;

	while(!is_empty(stack_b))
	{
		pos = get_position(stack_a,stack_b);
		// printf("stack_a\n");
		// stack_p(stack_a);
		// printf("stack_b\n");
		// stack_p(stack_b);
		// printf("pos: %d\n",pos);
		// getc(stdin);
		if(ft_abs(pos) < stack_b->size / 2)
		{
			i = 0;
			while(i < ft_abs(pos))
			{
				execute(stack_a,stack_b,RB);
				i++;
			}
		}
		else
		{
			i = 0;
			while(i < stack_b->size - ft_abs(pos))
			{
				execute(stack_a,stack_b,RRB);
				i++;
			}
		}
		execute(stack_a,stack_b,PA);
		if(pos < 0)
			execute(stack_a,stack_b,RA);
	}
}

void	sort(t_vec *sorted)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(sorted,&stack_a);
	stack_sort(sorted);
	stack_index_dereference(sorted, stack_a);
	pre_sort(stack_a,stack_b);
	big_sort(stack_a,stack_b);
}
