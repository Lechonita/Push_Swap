/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:21:39 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/01 18:38:03 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assigns/Reassigns the index of the given stack, starting from zero. */

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

/* Finds the highest value of the given stack. */

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

/* Finds the lowest value of the given stack. */

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

/* This function finds the index of the stack that we want to
	rotate. It will allow us to know how many times we need to 
	rotate in order	to get the targeted node on top of the stack. */

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

/* Determines the size of a given stack. */

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*first;

	i = 0;
	if (!stack)
		return (0);
	first = stack;
	while (first)
	{
		i++;
		first = first->next;
	}
	return (i);
}
