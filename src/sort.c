/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:41:58 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 17:20:20 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_position(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!stack_a)
		return ;
	tmp = stack_a;
	first = stack_a;
	while (stack_a)
	{
		tmp = first;
		while (tmp)
		{
			if (stack_a->value > tmp->value)
				stack_a->pos += 1;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

int	sorted_args(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	highest = highest_pos(*stack);
	if (sorted_args(*stack))
		return ;
	if ((*stack)->pos == highest)
		rotate_a(stack);
	else if ((*stack)->next->pos == highest)
		rev_rotate_a(stack);
	if ((*stack)->pos > (*stack)->next->pos)
		swap_a(stack);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	smallest;

	if (sorted_args(*stack_a))
		return ;
	size = stack_size(*stack_a);
	while (size > 3)
	{
		smallest = lowest_pos(*stack_a);
		if ((*stack_a)->pos != smallest)
			rotate_a(stack_a);
		else if ((*stack_a)->pos == smallest)
			push_b(stack_a, stack_b);
		size = stack_size(*stack_a);
	}
	size = stack_size(*stack_b);
	if (size == 2 && sorted_args(*stack_b) == 1)
		swap_b(stack_b);
	sort_three(stack_a);
	while ((*stack_b))
		push_a(stack_b, stack_a);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int const_chunk)
{
	int	size_a;

	smart_push(stack_a, stack_b, const_chunk);
	if (sorted_args(*stack_b))
	{
		while (*stack_b)
		{
			push_a(stack_b, stack_a);
			rotate_a(stack_a);
		}
	}
	while (*stack_b)
	{
		get_cost(stack_a);
		get_cost(stack_b);
		size_a = stack_size(*stack_a);
		find_cheapest(stack_a, stack_b, size_a);
	}
	while ((*stack_a)->pos != lowest_pos(*stack_a))
		smart_rotate_a(stack_a, lowest_pos(*stack_a));
}
