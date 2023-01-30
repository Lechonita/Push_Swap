/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:18:02 by lechon            #+#    #+#             */
/*   Updated: 2023/01/30 14:59:12 by jrouillo         ###   ########.fr       */
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
				// printf("cost target = %d\n", target);
				return (stack->cost);
			}
				
		}
	}
	return (size_a);
}