/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:24:52 by lechon            #+#    #+#             */
/*   Updated: 2023/01/30 16:46:09 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rev_rotate_rrr(a, b);
	}
}

void	cheapest_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_rr(a, b);
	}
}

void	ra_rra(t_stack **stack_a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if ((*cost_a) < 0)
		{
			(*cost_a)++;
			rev_rotate_a(stack_a);
		}
		else if ((*cost_a) > 0)
		{
			(*cost_a)--;
			rotate_a(stack_a);
		}
	}
}

void	rb_rrb(t_stack **stack_b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if ((*cost_b) < 0)
		{
			(*cost_b)++;
			rev_rotate_b(stack_b);
		}
		else if ((*cost_b) > 0)
		{
			(*cost_b)--;
			rotate_b(stack_b);
		}
	}
}
