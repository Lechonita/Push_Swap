/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:18:02 by lechon            #+#    #+#             */
/*   Updated: 2023/01/30 17:11:32 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

int	find_stack_cost(t_stack *stack, int pos, int size_a)
{
	int	target;

	target = find_target_node(stack, pos);
	if (target >= 0)
	{
		while (stack)
		{
			if (stack->pos != target)
				stack = stack->next;
			if (stack->pos == target)
			{
				return (stack->cost);
			}		
		}
	}
	return (size_a);
}

/* Function that takes as arguments :
	- *stack_a
	- stack_b->pos (first value on top of stack).
	Return = the pos of the target node that should be on top of stack_a. */

int	find_target_node(t_stack *stack_a, int pos_b)
{
	int	min;
	int	max;

	min = lowest_pos(stack_a);
	max = highest_pos(stack_a);
	if (pos_b > stack_a_last(stack_a)->pos && pos_b < stack_a->pos)
		return (stack_a->pos);
	while (stack_a && stack_a->next)
	{
		if (pos_b > stack_a->pos && pos_b < stack_a->next->pos)
			return (stack_a->next->pos);
		else if (pos_b > max || pos_b < min)
			return (min);
		stack_a = stack_a->next;
	}
	return (-1);
}
