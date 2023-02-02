/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:19:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/02 14:32:16 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* LONGEST INCREASING SUBSEQUENCE */

/* Function that finds the longest sorted list in stack_a
	so we don't need to push them in stack_b, nor sort them. */

int	assign_lis_count(t_stack *stack)
{
	int		max_lis;
	t_stack	*prev;
	t_stack	*curr;

	if (stack->next)
		curr = stack->next;
	stack->lis_count = 1;
	while (curr)
	{
		max_lis = 0;
		prev = stack;
		while (prev != curr)
		{
			if (curr->pos > prev->pos)
			{
				if (prev->lis_count > max_lis)
					max_lis = prev->lis_count;
			}
			prev = prev->next;
		}
		curr->lis_count = max_lis + 1;
		curr = curr->next;
	}
	max_lis = lis_length(stack);
	return (max_lis);
}

/* Function that finds the highest lis_count in stack_a */

int	lis_length(t_stack *stack)
{
	int	lis_length;

	lis_length = 0;
	while (stack)
	{
		if (lis_length < stack->lis_count)
			lis_length = stack->lis_count;
		stack = stack->next;
	}
	return (lis_length);
}

/* Function that flags the values that shouldn't be pushed
	in stack_b.
	Scans stack_a from the back to search for the first 
	stack->lis_count = max_lis, and flag it with 
	stack->lis_flag = 1
	Then, it will look for next lis => stack->lis_count = max_lis - 1
	and flag it, etc. */

void	flag_lis_values(t_stack *stack, int max_lis)
{
	t_stack	*ele;
	t_stack	*curr;
	int		i;

	ele = stack;
	i = max_lis + 1;
	while (i > 1)
	{
		i -= 1;
		curr = stack;
		while (curr && curr->lis_flag != 1)
		{
			if (curr->lis_count == i)
				ele = curr;
			curr = curr->next;
		}
		ele->lis_flag = 1;
	}
}
