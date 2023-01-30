/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:45:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 16:50:12 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_a_last(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	write(1, RA, ft_strlen(RA));
	write(1, "\n", 1);
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	write(1, RB, ft_strlen(RB));
	write(1, "\n", 1);
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, ROT_AB, ft_strlen(ROT_AB));
	write(1, "\n", 1);
}
