/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:31:19 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:31:20 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		max;
	int		down;
	int		pos;
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
}			t_op;

t_vec		*parse(int size, char **args);
int			convert_to_int(t_vec *result, char **numbers);
int			is_valid_number(t_vec *vector, long num);
void		sort(t_chunk *chunk);
void		push_to_stack(t_vec *sorted, t_vec *stack_a);
int			p(t_vec *stack_a, t_vec *stack_b, char *msg);
int			rrr(t_vec *stack_a, char *msg);
int			rr(t_vec *stack, char *msg);
int			execute(t_vec *stack_a, t_vec *stack_b, t_op op);
int			swap(t_vec *stack, char *msg);
void		sort_three(t_vec *stack_a);
void		stack_p(t_vec *stack);
int			sort_five(t_vec *stack_a, t_vec *stack_b);
int			all_in_range(t_vec *sorted, int start, int end, t_vec *stack_b);
void		stack_sort(t_vec *stack);
void		update_offset(t_chunk *chunk, t_vec *stack_b);
void		init_chunk(t_chunk *chunk);
int			in_range(int value, t_vec *sorted, int start, int end);
int			get_index(t_vec *stack);
void		fetch_max_element(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk);
void		push_to_b(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk);
void		push_back_to_a(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk);
int			get_pos(t_vec *stack_a, t_chunk *chunk);
int			get_max_pos(t_vec *stack_b, int max);

#endif
