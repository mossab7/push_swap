#include "push_swap.h"

int main(int argc, char **argv)
{
	t_vec *sorted;

	if(argc < 2)
	{
		ft_putstr_fd("Error <./push_swap args>\n",2);
		return (1);
	}
	constructor(&sorted);
	sorted = parse(argc - 1,argv + 1);
	if(!sorted)
	{
		cleanup_memory_tracker(get_memory_tracker());
		return (1);
	}
	sort(sorted);
	cleanup_memory_tracker(get_memory_tracker());
	return (0);
}
