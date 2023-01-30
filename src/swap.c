/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:45:53 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/25 16:26:38 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->pos;
	stack->pos = stack->next->pos;
	stack->next->pos = tmp;
}

void	swap_a(t_stack **stack)
{
	swap(*stack);
	write(1, SA, ft_strlen(SA));
	write(1, "\n", 1);
}

void	swap_b(t_stack **stack)
{
	swap(*stack);
	write(1, SB, ft_strlen(SB));
	write(1, "\n", 1);
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, SWAP_AB, ft_strlen(SWAP_AB));
	write(1, "\n", 1);
}
