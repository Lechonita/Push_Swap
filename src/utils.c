/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:39 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/29 16:18:57 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	highest_pos(t_stack *stack)
{
	int	pos;

	pos = stack->pos;
	while (stack)
	{
		if (stack->pos > pos)
			pos = stack->pos;
		stack = stack->next;
	}
	return (pos);
}

int	lowest_pos(t_stack *stack)
{
	int	pos;

	pos = stack->pos;
	while (stack)
	{
		if (stack->pos < pos)
			pos = stack->pos;
		stack = stack->next;
	}
	return (pos);
}


/* This function finds the index of the stack 
	that we want to rotate (smallest / highest) */

int	find_stack_index(t_stack *stack, int pos)
{
	while (stack)
	{
		if (stack->pos != pos)
			stack = stack->next;
		if (stack->pos == pos)
			return (stack->index);
	}
	return (0);
}
