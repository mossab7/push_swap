#include "push_swap.h"

void pre_sort(t_vec *sorted)
{
	int i;
	int j;
	int temp;

	i = 0;
	while(i < sorted->size)
	{
		j = i + 1;
		while(j < sorted->size)
		{
			if(sorted->vector[i] > sorted->vector[j])
			{
				temp = sorted->vector[i];
				sorted->vector[i] = sorted->vector[j];
				sorted->vector[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void init_chunk(t_chunk *chunk)
{
	pre_sort(chunk->sorted);
	if(chunk->sorted->size <= 10)
		chunk->offset = chunk->sorted->size / 5;
	else if(chunk->sorted->size <= 150)
		chunk->offset = chunk->sorted->size / 8;
	else
		chunk->offset = chunk->sorted->size / 18;
	chunk->mid = chunk->sorted->size / 2;
	chunk->start = chunk->mid - chunk->offset;
	chunk->end = chunk->mid + chunk->offset;
}

void push_to_stack(t_vec *sorted, t_vec **stack)
{
	int i;

	i = sorted->size - 1;
	while(i >= 0)
	{
		push(*stack, sorted->vector[i]);
		i--;
	}
}

int is_in_range(t_vec *stack, t_chunk *chunk, int start, int end)
{
    if (!stack || !chunk || start < 0 || end > chunk->sorted->size)
	{
        return (0);
	}
    while (start < end)
    {
        if (stack->vector[stack->size - 1] == chunk->sorted->vector[start])
            return (1);
        start++;
    }
    return (0);
}

int check_range(t_vec *stack,t_vec *sorted,int start,int end)
{
	int i;
	int is_in_range;
	int j;

    if (!stack || !sorted || start < 0 || end > sorted->size)
	{
    	return (0);
	}
	i = start;
	while(i < end)
	{
		j = 0;
		is_in_range = 0;
		while(j < stack->size)
		{
			if(sorted->vector[i] == stack->vector[j])
			{
				is_in_range = 1;
				break;
			}
			j++;
		}
		if(!is_in_range)
			return (0);
		i++;
	}
	return (1);
}

void update_offset(t_vec *stack_b,t_chunk *chunk)
{

	if(check_range(stack_b,chunk->sorted,chunk->start,chunk->mid))
	{
		if(chunk->start - chunk->offset >= 0)
			chunk->start -= chunk->offset;
		else
			chunk->start = 0;
	}
	if(check_range(stack_b,chunk->sorted,chunk->mid,chunk->end))
	{
		if(chunk->end + chunk->offset < chunk->sorted->size)
			chunk->end += chunk->offset;
		else
		chunk->end = chunk->sorted->size;
	}
}

int get_position(t_vec *stack, t_chunk *s_chunk)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->vector[i] >= s_chunk->sorted->vector[s_chunk->start] &&
			stack->vector[i] <= s_chunk->sorted->vector[s_chunk->end])
			return i;
		i++;
	}
	return -1;
}


// int push_to_b(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
// {
// 	int pos;

// 	while(!is_empty(stack_a))
// 	{
// 		update_offset(stack_b,chunk);
// 		if(is_in_range(stack_a,chunk,chunk->start,chunk->end))
// 		{
// 			if(execute(stack_a, stack_b, PB) == -1)
// 				return (-1);
// 			if(is_in_range(stack_b,chunk,chunk->start,chunk->mid))
// 			{
// 				if(execute(stack_a, stack_b, RB) == -1)
// 					return (-1);
// 			}
// 		}
// 		else
// 		{
// 			pos = get_position(stack_a, chunk);
// 			if(pos < stack_a->size / 2)
// 			{
// 				if(execute(stack_a, stack_b, RA) == -1)
// 					return (-1);
// 			}
// 			else
// 			{
// 				if(execute(stack_a, stack_b, RRA) == -1)
// 					return (-1);
// 			}
// 		}
// 	}
// 	return (0);
// }

int find_max(t_vec *stack)
{
	int i;
	int max;

	i = 0;
	max = stack->vector[0];
	while(i < stack->size)
	{
		if(stack->vector[i] > max)
		{
			max = stack->vector[i];
		}
		i++;
	}
	return (max);
}


int find_insert_position(t_vec *stack_a, int value)
{
    int i;

    if (is_empty(stack_a))
        return 0;

    i = 0;
    while (i < stack_a->size - 1)
    {
        if (value > stack_a->vector[i] && value < stack_a->vector[i + 1])
            return i + 1;
        i++;
    }
    if (value < stack_a->vector[0])
        return 0;
    return i + 1;
}

//if (stack_b->vector[stack_b->size - 1] == stack_b->vector[max])
int max_in_b(int max,t_vec *sorted)
{
	int i;

	i = 0;
	while(i < sorted->size)
	{
		if(sorted->vector[i] == max)
			return (1);
		i++;
	}
	return (0);
}

//start

int find_max_index(t_vec *stack_b, int limit)
{
    int i;
    int max;
    int max_index;

    if (stack_b->size == 0)
        return (-1);
    i = 0;
    max = stack_b->vector[0];
    max_index = 0;
    while (i < stack_b->size && i < limit)
    {
        if (stack_b->vector[i] > max)
        {
            max = stack_b->vector[i];
            max_index = i;
        }
        i++;
    }
    return (max_index);
}

// int smart_sort(t_vec *stack_a, t_vec *stack_b)
// {
//     int down;
//     int target_index;
//     int target_value;

//     down = 0;
//     while (!is_empty(stack_b) || down > 0)
//     {
//         target_index = find_max_index(stack_b, stack_b->size);

//         // If no suitable number found in stack_b but we have numbers down in stack_a
//         if (target_index == -1 && down > 0)
//         {
//             // Bring back numbers from bottom of stack_a
//             while (down > 0)
//             {
//                 if (execute(stack_a, stack_b, RRA) == -1)
//                     return (-1);
//                 down--;
//             }
//             continue;
//         }

//         // If we found a target number in stack_b
//         if (target_index != -1)
//         {
//             target_value = stack_b->vector[target_index];

//             // If target is at top of stack_b
//             if (target_index == 0)
//             {
//                 if (execute(stack_a, stack_b, PA) == -1)
//                     return (-1);
//             }
//             // If we can store current number at bottom of stack_a
//             else if (down == 0 || stack_b->vector[0] > stack_a->vector[0])
//             {
//                 if (execute(stack_a, stack_b, PA) == -1)
//                     return (-1);
//                 if (execute(stack_a, stack_b, RA) == -1)
//                     return (-1);
//                 down++;
//             }
//             // Need to rotate stack_b to get target number
//             else
//             {
//                 // Choose rotation direction based on target position
//                 if (target_index <= stack_b->size / 2)
//                 {
//                     if (execute(stack_a, stack_b, RB) == -1)
//                         return (-1);
//                 }
//                 else
//                 {
//                     if (execute(stack_a, stack_b, RRB) == -1)
//                         return (-1);
//                 }
//             }
//         }
//     }
//     return (0);
// }

//end

// int push_back(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
// {
//     int max;
// 	int down;
//     int pos;
//     (void)chunk;

// 	down = 0;
//     while (!is_empty(stack_b))
//     {
// 		max = chunk->sorted->vector[chunk->sorted->size - 1];
// 		if(max_in_b(max,chunk->sorted))
// 		{
// 			if (stack_b->vector[stack_b->size - 1] == max)
//         	{
//         	    if (execute(stack_a, stack_b, PA) == -1)
//         	        return (-1);
// 				chunk->sorted->size--;
//         	}
// 			else if(down == 0 || stack_b->vector[stack_b->size - 1] > stack_a->vector[0])
// 			{
// 				if (execute(stack_a, stack_b, PA) == -1)
// 					return (-1);
// 				if (execute(stack_a, stack_b, RA) == -1)
// 					return (-1);
// 			}
// 			else
// 			{
// 				pos = find_insert_position(stack_a, stack_b->vector[stack_b->size - 1]);
// 				while (pos > 0 && pos < stack_a->size)
// 				{
// 					if (pos <= stack_a->size / 2)
// 					{
// 						if (execute(stack_a, stack_b, RA) == -1)
// 							return (-1);
// 					}
// 					else
// 					{
// 						if (execute(stack_a, stack_b, RRA) == -1)
// 							return (-1);
// 					}
// 					pos--;
// 				}
// 			}
// 		}
// 		else
// 		{
// 			execute(stack_a, stack_b, RRA);
// 			down--;
// 			chunk->sorted->size--;
// 		}
// 	}
//     return (0);
// }

// int	big_sort(t_vec *stack_a,t_vec *stack_b,t_chunk *chunk)
// {
// 	if(push_to_b(stack_a,stack_b,chunk) == -1)
// 		return (-1);
// 	// if(push_back(stack_a,stack_b,chunk) == -1)
// 	// 	return (-1);
// 	// smart_sort(stack_a,stack_b);
// 	return (0);
// }

int sort_three(t_vec *stack)
{
    int first;
    int second;
    int third;

    if (stack->size < 3)
        return (0);
        
    first = stack->vector[stack->size - 1];   // Top element
    second = stack->vector[stack->size - 2];  // Middle element
    third = stack->vector[stack->size - 3];   // Bottom element

    if (first > second && second < third && first < third)
    {
        if (execute(stack, NULL, SA) == -1)
            return (-1);
    }
    else if (first > second && second > third)
    {
        if (execute(stack, NULL, SA) == -1 || 
            execute(stack, NULL, RRA) == -1)
            return (-1);
    }
    else if (first > second && second < third && first > third)
    {
        if (execute(stack, NULL, RA) == -1)
            return (-1);
    }
    else if (first < second && second > third && first < third)
    {
        if (execute(stack, NULL, SA) == -1 ||
            execute(stack, NULL, RA) == -1)
            return (-1);
    }
    else if (first < second && second > third && first > third)
    {
        if (execute(stack, NULL, RRA) == -1)
            return (-1);
    }
    // If first < second && second < third, it's already sorted

    return (0);
}

int sort_top_three(t_vec *stack_a)
{
    // Check if we have at least 3 elements
    if (stack_a->size < 3)
        return (0);

    // Sort only the top 3 elements
    return sort_three(stack_a);
}

// First, modify push_to_b to handle separate chunk updates
int push_to_b(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
    int pos;
    int numbers_to_keep = 3;  // Keep top 3 numbers in stack_a

    while (stack_a->size > numbers_to_keep)
    {
        // Check if lower chunk is complete
        if (check_range(stack_b, chunk->sorted, chunk->start, chunk->mid))
        {
            if (chunk->start - chunk->offset >= 0)
                chunk->start -= chunk->offset;
            else
                chunk->start = 0;
        }
        
        // Check if upper chunk is complete
        if (check_range(stack_b, chunk->sorted, chunk->mid, chunk->end))
        {
            if (chunk->end + chunk->offset < chunk->sorted->size)
                chunk->end += chunk->offset;
            else
                chunk->end = chunk->sorted->size;
        }

        if (is_in_range(stack_a, chunk, chunk->start, chunk->end))
        {
            if (execute(stack_a, stack_b, PB) == -1)
                return (-1);
            if (is_in_range(stack_b, chunk, chunk->start, chunk->mid))
            {
                if (execute(stack_a, stack_b, RB) == -1)
                    return (-1);
            }
        }
        else
        {
            pos = get_position(stack_a, chunk);
            if (pos < stack_a->size / 2)
            {
                if (execute(stack_a, stack_b, RA) == -1)
                    return (-1);
            }
            else
            {
                if (execute(stack_a, stack_b, RRA) == -1)
                    return (-1);
            }
        }
    }
    return sort_top_three(stack_a);  // New function to sort top 3 numbers
}

// New optimized push_back function using up and down areas
int optimized_push_back(t_vec *stack_a, t_vec *stack_b)
{
    int up = 0;    // Track numbers in upper area
    int down = 0;  // Track numbers in bottom area
    int target_index;
    int can_push_down;

    while (!is_empty(stack_b) || up > 0 || down > 0)
    {
        target_index = find_max_index(stack_b, stack_b->size);
        
        // No target in stack_b, handle numbers in stack_a
        if (target_index == -1)
        {
            if (up > 0)
            {
                if (execute(stack_a, stack_b, RA) == -1)
                    return (-1);
                up--;
            }
            else if (down > 0)
            {
                if (execute(stack_a, stack_b, RRA) == -1)
                    return (-1);
                down--;
            }
            continue;
        }

        // Target found in stack_b
        if (target_index == 0)  // Target at top of stack_b
        {
            // Rotate stack_a until only one number remains in up area
            while (up > 1)
            {
                if (execute(stack_a, stack_b, RA) == -1)
                    return (-1);
                up--;
            }
            if (execute(stack_a, stack_b, PA) == -1)
                return (-1);
            if (up == 1)  // One number in up area, swap if needed
            {
                if (stack_a->vector[stack_a->size - 1] < stack_a->vector[stack_a->size - 2])
                    if (execute(stack_a, stack_b, SA) == -1)
                        return (-1);
                up = 0;
            }
        }
        else  // Target not at top
        {
            can_push_down = (down == 0 || stack_b->vector[0] > stack_a->vector[0]);
            
            if (can_push_down)
            {
                // Push to bottom area
                if (execute(stack_a, stack_b, PA) == -1)
                    return (-1);
                // Rotate while head of stack_a is smaller than head of stack_b and we have numbers in up area
                while (up > 0 && !is_empty(stack_b) && 
                       stack_a->vector[stack_a->size - 1] < stack_b->vector[0])
                {
                    if (execute(stack_a, stack_b, RA) == -1)
                        return (-1);
                    up--;
                    down++;
                }
                if (execute(stack_a, stack_b, RA) == -1)
                    return (-1);
                down++;
            }
            else
            {
                // Rotate stack_b towards target
                if (target_index <= stack_b->size / 2)
                {
                    if (execute(stack_a, stack_b, RB) == -1)
                        return (-1);
                }
                else
                {
                    if (execute(stack_a, stack_b, RRB) == -1)
                        return (-1);
                }
            }
        }
    }
    return (0);
}

// Modified big_sort to use the optimized functions
int big_sort(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
    if (push_to_b(stack_a, stack_b, chunk) == -1)
        return (-1);
    if (optimized_push_back(stack_a, stack_b) == -1)
        return (-1);
    return (0);
}

void sort(t_chunk *chunk)
{
	t_vec *stack_a;
	t_vec *stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(chunk->sorted, &stack_a);
	init_chunk(chunk);
	big_sort(stack_a, stack_b,chunk);
	// for(int i = 0; i < stack_a->size; i++)
	// {
	// 	printf("%d\n",stack_a->vector[i]);
	// }
	// printf("----------------\n");
	// for(int i = 0; i < chunk->sorted->size; i++)
	// {
	// 	printf("%d\n",chunk->sorted->vector[i]);
	// }
	// printf("----------------\n");
	// for(int i = stack_b->size - 1; i >= 0; i--)
	// {
	// 	printf("%d\n",stack_b->vector[i]);
	// }
}

