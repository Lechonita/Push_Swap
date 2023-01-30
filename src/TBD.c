/* FIND CLOSEST : 
	Finds in stack_a the closest value (pos) to the first node in stack_b.
	If the value (pos) of stack_b is higher than all values (pos) in stack_a,
	it returns the stack_b value (pos). */

int	find_closest_above(t_stack *stack_a, int pos_b)
{
	int	max;
	int	size;

	max = highest_pos(stack_a);
	// printf("max = %d\n", max);
	size = stack_size(stack_a);
	// printf("size = %d\n", size);
	if (pos_b > max)
		return (pos_b);
	while (size >= 0)
	{
		if (stack_a->pos > pos_b && stack_a->pos < max)
			max = stack_a->pos;
		size--;
	}
	return (max);
}

int	find_closest_below(t_stack *stack_a, int pos_b)
{
	int	min;
	int	size;

	min = lowest_pos(stack_a);
	// printf("min = %d\n", min);
	size = stack_size(stack_a);
	// printf("size = %d\n", size);
	if (pos_b < min)
		return (pos_b);
	while (size >= 0)
	{
		if (stack_a->pos < pos_b && stack_a->pos > min)
			min = stack_a->pos;
		size--;
	}
	return (min);
}


int	lowest_pos_index(t_stack *stack)
{
	int	pos;
	int	ind;

	pos = stack->pos;
	ind = stack->index;
	while (stack)
	{
		if (stack->pos < pos)
		{
			pos = stack->pos;
			ind = stack->index;
		}
		stack = stack->next;
	}
	return (ind);
}