#include "libft.h"

int resize(t_vec *vector)
{
	int *new_arr;

	new_arr = allocate_tracked_memory(((vector->capacity * 2) * sizeof(int)));
	if(!new_arr)
		return (-1);
	ft_memmove(new_arr,vector->vector,vector->size*sizeof(int));
	detach_resource(get_memory_tracker(),vector->vector);
	vector->vector = new_arr;
	vector->capacity *= 2;
	return (0);
}

int push(t_vec *vector,int num)
{
	if(vector->capacity - 1 == vector->size)
	{
		if(resize(vector) == -1)
			return (-1);
	}
	vector->vector[vector->size++] = num;
	return (0);
}

int pop(t_vec *vector)
{
	return (vector->vector[(vector->size--) - 1]);
}

int is_empty(t_vec *vector)
{
	return (vector->size == 0);
}

int	constructor(t_vec **vector)
{
	*vector = allocate_tracked_memory(sizeof(t_vec));
	if(!*vector)
		return (-1);
	(*vector)->vector = allocate_tracked_memory(sizeof(int) * 2);
	if(!(*vector)->vector)
		return (-1);
	(*vector)->capacity = 2;
	(*vector)->size = 0;
	return (0);
}
