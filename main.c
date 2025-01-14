#include "push_swap.h"

int is_sorted(t_vec *stack)
{
	int i;

	i = 0;
	while(i < stack->size - 1)
	{
		if(stack->vector[i] > stack->vector[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_chunk *chunk;

	if(argc < 2)
	{
		ft_putstr_fd("Error <./push_swap args>\n",2);
		return (1);
	}
	chunk = (t_chunk *)allocate_tracked_memory(sizeof(t_chunk));
	chunk->sorted = parse(argc - 1,argv + 1);
	if(!chunk->sorted)
	{
		printf("Error\n");
		cleanup_memory_tracker(get_memory_tracker());
		return (1);
	}
	if(is_sorted(chunk->sorted))
	{
		cleanup_memory_tracker(get_memory_tracker());
		return (0);
	}
	sort(chunk);
	cleanup_memory_tracker(get_memory_tracker());
	return (0);
}
