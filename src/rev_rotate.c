/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:10:49 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/26 11:55:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*second_last;

	if (stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	second_last = *stack;
	last = (*stack)->next;
	*stack = last;
	(*stack)->next = tmp;
	second_last->next = NULL;
}

void	rev_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, RRA, ft_strlen(RRA));
	write(1, "\n", 1);
}

void	rev_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, RRB, ft_strlen(RRB));
	write(1, "\n", 1);
}

void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, RVROT_AB, ft_strlen(RVROT_AB));
	write(1, "\n", 1);
}
