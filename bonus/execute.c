#include "checker.h"

int		execute(t_vec *stack_a, t_vec *stack_b, char *op)
{
	if (ft_strncmp(op, "sa\n", ft_strlen("sa\n")) == 0)
		return (swap(stack_a, NULL));
	else if (ft_strncmp(op, "sb\n", ft_strlen("sb\n")) == 0)
		return (swap(stack_b,NULL));
	else if (ft_strncmp(op, "ss\n", ft_strlen("ss\n")) == 0)
		return (swap(stack_a, NULL) && swap(stack_b, "ss\n"));
	else if (ft_strncmp(op, "pa\n", ft_strlen("pa\n")) == 0)
		return (p(stack_b, stack_a, NULL));
	else if (ft_strncmp(op, "pb\n", ft_strlen("pb\n")) == 0)
		return (p(stack_a, stack_b, NULL));
	else if (ft_strncmp(op, "ra\n", ft_strlen("ra\n")) == 0)
		return (rr(stack_a, NULL));
	else if (ft_strncmp(op, "rb\n", ft_strlen("rb\n")) == 0)
		return (rr(stack_b, NULL));
	else if (ft_strncmp(op, "rr\n", ft_strlen("rr\n")) == 0)
		return (rr(stack_a, NULL) && rr(stack_b, NULL));
	else if (ft_strncmp(op, "rra\n", ft_strlen("rra\n")) == 0)
		return (rrr(stack_a, NULL));
	else if (ft_strncmp(op, "rrb\n", ft_strlen("rrb\n")) == 0)
		return (rrr(stack_b, NULL));
	else if (ft_strncmp(op, "rrr\n", ft_strlen("rrr\n")) == 0)
		return (rrr(stack_a, NULL) && rrr(stack_b, NULL));
	return (-1);
}
