#include "push_swap.h"

int p(t_vec *stack_a, t_vec *stack_b,char *msg)
{
	if(is_empty(stack_a))
		return (0);
	if(push(stack_b, pop(stack_a)) == -1)
		return (-1);
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int rrr(t_vec *stack_a,char *msg)
{
	int i;
	int temp;

	if(stack_a->size < 2)
		return (0);
	i = stack_a->size - 1;
	temp = stack_a->vector[i];
	while(i > 0)
	{
		stack_a->vector[i] = stack_a->vector[i - 1];
		i--;
	}
	stack_a->vector[0] = temp;
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int rr(t_vec *stack,char *msg)
{
	int tmp;
	int i;

	i = 0;
	if(stack->size < 2)
		return (0);
	tmp = stack->vector[0];
	while(i < stack->size - 1)
	{
		stack->vector[i] = stack->vector[i + 1];
		i++;
	}
	stack->vector[i] = tmp;
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int rr_ab(t_vec *stack_a,t_vec *stack_b,char *msg)
{
	if(rr(stack_a,NULL) == -1)
		return (-1);
	if(rr(stack_b,NULL) == -1)
		return (-1);
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int rrr_ab(t_vec *stack_a,t_vec *stack_b,char *msg)
{
	if(rrr(stack_a,NULL) == -1)
		return (-1);
	if(rrr(stack_b,NULL) == -1)
		return (-1);
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int s(t_vec *stack,char *msg)
{
	int tmp;

	if(stack->size < 2)
		return (0);
	tmp = stack->vector[stack->size - 1];
	stack->vector[stack->size - 1] = stack->vector[stack->size - 2];
	stack->vector[stack->size - 2] = tmp;
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}

int ss(t_vec *stack ,t_vec *stack_b,char *msg)
{
	if(s(stack,NULL) == -1)
		return (-1);
	if(s(stack_b,NULL) == -1)
		return (-1);
	if(msg)
		ft_putstr_fd(msg,1);
	return (0);
}


