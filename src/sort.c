/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:41:58 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/29 16:37:43 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
