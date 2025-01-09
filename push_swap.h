#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

t_vec	*parse(int size, char **args);
int		convert_to_int(t_vec *result, char **numbers);
int		is_valid_number(t_vec *vector, long num);
void sort(t_vec *sorted);
void push_to_stack(t_vec *sorted, t_vec **stack_a);
#endif
