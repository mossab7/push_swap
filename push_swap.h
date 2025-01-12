#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_chunk
{
	t_vec	*sorted;
	int		start;
	int		mid;
	int		end;
	int		offset;
	int		n;
}			t_chunk;

typedef enum operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}e_op;

t_vec		*parse(int size, char **args);
int			convert_to_int(t_vec *result, char **numbers);
int			is_valid_number(t_vec *vector, long num);
void		sort(t_vec *chunk);
void		push_to_stack(t_vec *sorted, t_vec **stack_a);
int			p(t_vec *stack_a, t_vec *stack_b, char *msg);
int			rrr(t_vec *stack_a, char *msg);
int			rr(t_vec *stack, char *msg);
int			execute(t_vec *stack_a, t_vec *stack_b, e_op op);
int			swap(t_vec *stack,char *msg);
void		push_to_stack(t_vec *sorted, t_vec **stack_a);
#endif
