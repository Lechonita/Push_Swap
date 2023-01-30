/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:05:30 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 16:47:00 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
