#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

int		is_sorted(t_vec *stack);
int		execute(t_vec *stack_a, t_vec *stack_b, char *op);
int		p(t_vec *pop_stack, t_vec *push_stack, char *msg);
int		rr(t_vec *stack, char *msg);
int		rrr(t_vec *stack, char *msg);
int		swap(t_vec *stack, char *msg);
int		is_valid_number(t_vec *vector, long num);
int		is_digits(char *number);
int		convert_to_int(t_vec *result, char **numbers);
t_vec	*parse(int size, char **args);

#endif
