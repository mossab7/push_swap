#include "push_swap.h"

int		execute(t_vec *stack_a, t_vec *stack_b, e_op op)
{
	if (op == SA)
		return (swap(stack_a, "sa\n"));
	else if (op == SB)
		return (swap(stack_b, "sb\n"));
	else if (op == SS)
		return (swap(stack_a, NULL) && swap(stack_b, "ss\n"));
	else if (op == PA)
		return (p(stack_b, stack_a, "pa\n"));
	else if (op == PB)
		return (p(stack_a, stack_b, "pb\n"));
	else if (op == RA)
		return (rr(stack_a, "ra\n"));
	else if (op == RB)
		return (rr(stack_b, "rb\n"));
	else if (op == RR)
		return (rr(stack_a, NULL) && rr(stack_b, "rr\n"));
	else if (op == RRA)
		return (rrr(stack_a, "rra\n"));
	else if (op == RRB)
		return (rrr(stack_b, "rrb\n"));
	else if (op == RRR)
		return (rrr(stack_a, NULL) && rrr(stack_b, "rrr\n"));
	return (0);
}
