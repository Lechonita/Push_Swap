/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:06:50 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:31 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b, int const_chunk)
{
	int	size_a;

	smart_push(stack_a, stack_b, const_chunk);
	while (*stack_b)
	{
		get_cost(stack_a);
		get_cost(stack_b);
		size_a = stack_size(*stack_a);
		find_cheapest(stack_a, stack_b, size_a);
	}
	while ((*stack_a)->pos != lowest_pos(*stack_a))
		smart_rotate_a(stack_a, lowest_pos(*stack_a));
	// display_stack(*stack_a, *stack_b);
}

void	sort_insert(t_stack **stack_a, t_stack **stack_b)
{
	int	target;

	while (*stack_b)
	{
		target = find_target_node(*stack_a, (*stack_b)->pos);
		if (target >= 0)
		{
			push_to_top(stack_a, target);
			push_a(stack_b, stack_a);
		}
		else
			rotate_a(stack_a);
	}
}

/* Function that takes as arguments :
	- *stack_a
	- stack_b->pos (first value on top of stack).
	Return = the pos of the target node that should be on top of stack_a. */

int	find_target_node(t_stack *stack_a, int pos_b)
{
	// printf("FIND TARGET NODE\n");
	int	min;
	int	max;

	min = lowest_pos(stack_a);
	max = highest_pos(stack_a);
	// printf("pos_b = %d\n", pos_b);
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

/*		WITH SMART ROTATE
	Function that takes as arguments :
	- **stack_a
	- stack_a->pos == return of function find_target_node
	Action (no return / void) :
	- pushes the target node to the top of stack_a */

void	push_to_top(t_stack **stack_a, int pos_a)
{
	int	ind;

	if (!*stack_a || !stack_a)
		return ;
	assign_index(*stack_a);
	ind = find_stack_index(*stack_a, pos_a);
	if ((*stack_a)->index == ind)
		return ;
	else
		smart_rotate_a(stack_a, pos_a);
}
