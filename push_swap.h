#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_chunk
{
	t_vec	*sorted;
	t_vec	*start;
	t_vec	*end;
	int		offset;
}			t_chunk;

t_vec		*parse(int size, char **args);
int			convert_to_int(t_vec *result, char **numbers);
int			is_valid_number(t_vec *vector, long num);
void		sort(t_chunk *chunk);
void		push_to_stack(t_vec *sorted, t_vec **stack_a);
int			p(t_vec *stack_a, t_vec *stack_b, char *msg);
int			rrr(t_vec *stack_a, char *msg);
int			rr(t_vec *stack, char *msg);
int			rr_ab(t_vec *stack_a, t_vec *stack_b, char *msg);
int			rrr_ab(t_vec *stack_a, t_vec *stack_b, char *msg);
void		pre_sort(t_vec *sorted);
int			s(t_vec *stack, char *msg);
int			ss(t_vec *stack, t_vec *stack_b, char *msg);
#endif
