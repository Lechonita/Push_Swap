/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:45:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 15:53:20 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate(t_stack *stack)
// {
// 	int	tmp_value;
// 	int	tmp_pos;
// 	int	tmp_index;
// 	int	tmp_lis_flag;

// 	if (!stack)
// 		return ;
// 	tmp_value = stack->value;
// 	tmp_pos = stack->pos;
// 	tmp_index = stack->index;
// 	tmp_lis_flag = stack->lis_flag;
// 	while (stack->next)
// 	{
// 		stack->value = stack->next->value;
// 		stack->pos = stack->next->pos;
// 		stack->index = stack->next->index;
// 		stack->lis_flag = stack->next->lis_flag;
// 		stack = stack->next;
// 	}
// 	stack->value = tmp_value;
// 	stack->pos = tmp_pos;
// 	stack->index = tmp_index;
// 	stack->lis_flag = tmp_lis_flag;
// }

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