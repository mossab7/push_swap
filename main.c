#include "push_swap.h"

int main(int argc, char **argv)
{
	t_chunk	*chunk;

	if(argc < 2)
	{
		ft_putstr_fd("Error <./push_swap args>\n",2);
		return (1);
	}
	chunk = allocate_tracked_memory(sizeof(t_chunk));
	chunk->sorted = parse(argc - 1,argv + 1);
	if(!chunk->sorted)
	{
		cleanup_memory_tracker(get_memory_tracker());
		return (1);
	}
	sort(chunk);
	cleanup_memory_tracker(get_memory_tracker());
	return (0);
}
