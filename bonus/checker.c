#include "checker.h"

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

int is_sorted(t_vec *stack)
{
	int i;

	i = stack->size - 1;
	while(i > 0)
	{
		if(stack->vector[i] > stack->vector[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	read_instructions(t_vec *parsed,t_vec *stack_a,t_vec *stack_b)
{
	char *instruction;

	push_to_stack(parsed,&stack_a);
	while(1)
	{
		instruction = get_next_line(0);
		if(!instruction)
			return (1);
		if(instruction[ft_strlen(instruction)] != '\n')
			ft_strjoin(instruction,"\n");
		if (execute(stack_a,stack_b,instruction) == -1)
		{
			ft_putstr_fd("Error\n",2);
			cleanup_memory_tracker(get_memory_tracker());
			return (0);
		}
		detach_resource(get_memory_tracker(),instruction);
	}
}

int main(int ac,char **av)
{
	t_vec *stack_a;
	t_vec *stack_b;
	t_vec *parsed;

	if(ac < 2)
		return (0);
	parsed = parse(ac-1,av+1);
	if(!parsed)
	{
		ft_putstr_fd("Error\n",2);
		cleanup_memory_tracker(get_memory_tracker());
		return (1);
	}
	constructor(&stack_a);
	constructor(&stack_b);
	if(!read_instructions(parsed,stack_a,stack_b))
		return (0);
	if(is_sorted(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n",1);
	else
		ft_putstr_fd("KO\n",1);
	cleanup_memory_tracker(get_memory_tracker());
	return (0);
}
