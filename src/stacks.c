/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:29:27 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/01 18:37:56 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Determines whether it is the creation of a new stack or an addition of
	a new node to an existing stack. */

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	int			nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = stack_a_new(nb, (i - 1));
		else
			stack_a_addback(&stack_a, stack_a_new(nb, (i - 1)));
		i++;
	}
	return (stack_a);
}

/* Creation of a new stack */

t_stack	*stack_a_new(int nb, int ind)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nb;
	new->index = ind;
	new->pos = 0;
	new->lis_count = 0;
	new->lis_flag = 0;
	new->cost = 0;
	new->next = NULL;
	return (new);
}

/* Addition of a new node to an existing stack. */

void	stack_a_addback(t_stack **stack_a, t_stack *nb)
{
	t_stack	*last;

	if (!nb)
		return ;
	if (!*stack_a)
	{
		*stack_a = nb;
		return ;
	}
	last = stack_a_last(*stack_a);
	last->next = nb;
}

/* Returns the last node of a stack. */

t_stack	*stack_a_last(t_stack *stack_a)
{
	while (stack_a && stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

/* Frees the stack once done. */

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
