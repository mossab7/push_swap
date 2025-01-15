
#include "push_swap.h"
int get_index(t_vec *stack, int find_max)
{
    int i = 0;
    int target_idx = 0;
    int target = stack->vector[0];

    while (i < stack->size)
    {
        if ((find_max && stack->vector[i] > target) ||
            (!find_max && stack->vector[i] < target))
        {
            target = stack->vector[i];
            target_idx = i;
        }
        i++;
    }
    return (target_idx);
}

void sort_three(t_vec *stack_a, t_vec *stack_b)
{
    int top = stack_a->vector[0];
    int mid = stack_a->vector[1];
    int bot = stack_a->vector[2];

    if (top > mid && mid < bot && top < bot)
        execute(stack_a, stack_b, SA);
    else if (top > mid && mid > bot)
    {
        execute(stack_a, stack_b, SA);
        execute(stack_a, stack_b, RRA);
    }
    else if (top > mid && mid < bot && top > bot)
        execute(stack_a, stack_b, RA);
    else if (top < mid && mid > bot && top < bot)
    {
        execute(stack_a, stack_b, SA);
        execute(stack_a, stack_b, RA);
    }
    else if (top < mid && mid > bot && top > bot)
        execute(stack_a, stack_b, RRA);
}

int sort_five(t_vec *stack_a, t_vec *stack_b)
{
    int idx;
    
    idx = get_index(stack_a, 0);
    while (idx > 0)
    {
        execute(stack_a, stack_b, RA);
        idx--;
    }
    execute(stack_a, stack_b, PB);
    
    idx = get_index(stack_a, 0);
    while (idx > 0)
    {
        execute(stack_a, stack_b, RA);
        idx--;
    }
    execute(stack_a, stack_b, PB);
    
    sort_three(stack_a, stack_b);
    
    execute(stack_a, stack_b, PA);
    execute(stack_a, stack_b, PA);
    
    return (0);
}