#include "push_swap.h"

int main(int argc, char **argv)
{
	t_vec	*result;

	if(argc < 2)
	{
		ft_putstr_fd("Error <./push_swap args>\n",2);
		return (1);
	}
	result = parse(argc - 1,argv + 1);
	if(!result)
	{
		cleanup_memory_tracker(get_memory_tracker());
		return (1);
	}
	sort(result);
	// for(int i = 0; i < result->size; i++)
	// {
	// 	printf("%d\n",result->vector[i]);
	// }
	cleanup_memory_tracker(get_memory_tracker());
	return (0);
}
