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

/*********************************/
/********* TO BE REMOVED *********/
/*********************************/

void	display_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a)
	{
		printf("~A~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_a->index, tmp_a->pos, tmp_a->lis_count, tmp_a->lis_flag,
			tmp_a->cost, tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	if (!tmp_b)
		return ;
	printf("--------------------------\n");
	while (tmp_b)
	{
		printf("~B~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_b->index, tmp_b->pos, tmp_b->lis_count, tmp_b->lis_flag,
			tmp_b->cost, tmp_b->value);
		tmp_b = tmp_b->next;
	}
	printf("\n");
	printf("--------------------------\n");
}

void	display_onestack(t_stack *stack_a)
{
	t_stack	*tmp_a;

	tmp_a = stack_a;
	if (!tmp_a)
		return ;
	while (tmp_a)
	{
		printf("~X~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_a->index, tmp_a->pos, tmp_a->lis_count, tmp_a->lis_flag,
			tmp_a->cost, tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf("--------------------------\n");
}