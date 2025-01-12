int get_chunk_size(int stack_size)
{
    if (stack_size <= 10)
        return 5;
    else if (stack_size <= 150)
        return 8;
    else
        return 18;
}

void init_chunk_params(t_chunk *chunk, int stack_size)
{
    chunk->n = get_chunk_size(stack_size);
    chunk->offset = stack_size / chunk->n;
    chunk->middle = stack_size / 2;
    chunk->start = chunk->middle - chunk->offset;
    chunk->end = chunk->middle + chunk->offset;
}

int is_in_chunk(int value, int *sorted, int start, int end)
{
    int i = start;
    while (i <= end)
    {
        if (sorted[i] == value)
            return (1);
        i++;
    }
    return (0);
}

int push_chunks(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
    int pushed = 0;
    int total_size = stack_a->size;

    // Continue until all numbers are pushed
    while (pushed < total_size)
    {
        // Process current chunk
        int i = 0;
        while (i < stack_a->size)
        {
            // Check if current number belongs to chunk range
            if (is_in_chunk(stack_a->vector[0], chunk->sorted->vector,
                          chunk->start, chunk->end))
            {
                // Push to stack B
                if (execute(stack_a, stack_b, PB) == -1)
                    return (-1);

                // If number is below middle, rotate it in stack B
                if (stack_b->vector[0] <=
                    chunk->sorted->vector[chunk->middle])
                {
                    if (execute(stack_a, stack_b, RB) == -1)
                        return (-1);
                }
                pushed++;
            }
            else
            {
                // Rotate stack A to check next number
                if (execute(stack_a, stack_b, RA) == -1)
                    return (-1);
            }
            i++;
        }

        // Update chunk range for next iteration
        chunk->start -= chunk->offset;
        chunk->end += chunk->offset;

        // Ensure bounds don't exceed array limits
        if (chunk->start < 0)
            chunk->start = 0;
        if (chunk->end >= total_size)
            chunk->end = total_size - 1;
    }
    return (0);
}

int sort_first_phase(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
    // Initialize chunk parameters
    init_chunk_params(chunk, stack_a->size);

    // Push numbers in chunks to stack B
    if (push_chunks(stack_a, stack_b, chunk) == -1)
        return (-1);

    return (0);
}
