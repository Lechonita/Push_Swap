/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:05:30 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/01 11:44:57 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assigns the cost for each node. The cost represents the number of operations
	it would take to bring each node to the top of the stack. */

void	get_cost(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	tmp = *stack;
	size = stack_size(tmp);
	assign_index(tmp);
	while (tmp)
	{
		tmp->cost = tmp->index;
		if (tmp->index > size / 2)
			tmp->cost = (size - tmp->index) * -1;
		tmp = tmp->next;
	}
}

/* This function finds the cheapest cost it would take to push a stack_b
	node into stack_a, in the right position of stack_a. It compares the costs
	for each stack_b node of keeps the cheapest one. */

void	find_cheapest(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	t_stack	*tmp;
	int		cheapest;
	int		target_cost_a;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	target_cost_a = 0;
	while (tmp)
	{
		target_cost_a = find_stack_cost(*stack_a, tmp->pos, size_a);
		if (target_cost_a != size_a)
		{
			if (ft_abs(tmp->cost) + ft_abs(target_cost_a) < ft_abs(cheapest))
			{
				cheapest = ft_abs(tmp->cost) + ft_abs(target_cost_a);
				cost_a = target_cost_a;
				cost_b = tmp->cost;
			}
		}
		tmp = tmp->next;
	}
	move_cheapest(stack_a, stack_b, cost_a, cost_b);
}

/* After finding the nodes to be moved with find_cheapest, this function
	does the operations to push the targeted stack_b node in the right position
	in stack_a. */

void	move_cheapest(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		cheapest_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		cheapest_rr(a, b, &cost_a, &cost_b);
	ra_rra(a, &cost_a);
	rb_rrb(b, &cost_b);
	push_a(b, a);
}
