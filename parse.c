#include "push_swap.h"
#include <limits.h>

int is_valid_number(t_vec *vector,long num)
{
	int i;

	if(num > INT_MAX || num < INT_MIN)
	{
		printf("%ld is too large\n",num);
		return (-1);
	}
	i = 0;
	while(i < vector->size)
	{
		if(vector->vector[i] == num)
		{
			printf("%ld is a duplicate\n",num);
			return (-1);
		}
		i++;
	}
	return (0);
}

int convert_to_int(t_vec *result, char **numbers)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while(numbers[i])
		i++;
	j = 0;
	while(j < i)
	{
		num = ft_atoi(numbers[j]);
		if(is_valid_number(result,num) == -1)
			return (-1);
		if(push(result, num) == -1)
			return (-1);
		j++;
	}
	return (0);
}

t_vec 	*parse(int size,char **args)
{
	int		i;
	char	**numbers;
	t_vec	*result;

	i = 0;
	constructor(&result);
	if (!result)
		return (NULL);
	while(i < size)
	{
		numbers = ft_split(args[i],' ');
		if(!numbers)
			return (NULL);
		if(convert_to_int(result,numbers) == -1)
			return (NULL);
		i++;
	}
	return (result);
}


