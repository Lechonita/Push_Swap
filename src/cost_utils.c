/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:18:02 by lechon            #+#    #+#             */
/*   Updated: 2023/02/01 11:18:22 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function returns the absolute value of a number,
	so it's distance to zero. Here, it is used to get the absolute value of
	the negative costs (for the numbers that are below size / 2),
	in the function find_cheapest (in cost.c). */

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

/* This function returns the cost of the targeted node. It utilizes
	the function find_target_node to first localize the node that
	we want on top of stack_a (through it's pos). Once the node has been
	defined, find_stack_cost will allow us to determine it's predefined cost.
	Ths function is used in find_cheapest (in cost.c). */

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

/* This function returns the pos of the target node that should be on top 
	of stack_a for the given node of stack_b.
	If stack_a has 3 values, with [stack_a->pos = 1], [stack_a->pos = 2] and
	[stack_a->pos = 4].	And stack_b has[stack_b->pos = 3]. We want to find the 
	best node to put on top	of stack_a in order to push the node B in the right 
	position of stack_a. In this example, that would be [stack_a->pos = 4]. */

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
