/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:29:27 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 17:23:27 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*stack_a_last(t_stack *stack_a)
{
	while (stack_a && stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

/*********************************/
/********* TO BE REMOVED *********/
/*********************************/

void	display_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a)
	{
		printf("~A~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_a->index, tmp_a->pos, tmp_a->lis_count, tmp_a->lis_flag,
			tmp_a->cost, tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	if (!tmp_b)
		return ;
	printf("--------------------------\n");
	while (tmp_b)
	{
		printf("~B~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_b->index, tmp_b->pos, tmp_b->lis_count, tmp_b->lis_flag,
			tmp_b->cost, tmp_b->value);
		tmp_b = tmp_b->next;
	}
	printf("\n");
	printf("--------------------------\n");
}

void	display_onestack(t_stack *stack_a)
{
	t_stack	*tmp_a;

	tmp_a = stack_a;
	if (!tmp_a)
		return ;
	while (tmp_a)
	{
		printf("~X~  [ind%3d] [pos%3d] [lis_count%3d] [lis_flag%3d] [cost%3d] %3d\n",
			tmp_a->index, tmp_a->pos, tmp_a->lis_count, tmp_a->lis_flag,
			tmp_a->cost, tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf("--------------------------\n");
}