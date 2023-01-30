/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:38 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 17:18:10 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function determines whether CONST_CHUNK100 (20) is used
	or wheter CONST_CHUNK500 (50) is used.*/

int	get_const_chunk(t_stack *stack_a)
{
	int		size;
	int		const_chunk;

	size = stack_size(stack_a);
	const_chunk = 0;
	if (size < 500)
		const_chunk = CONST_CHUNK100;
	else if (size >= 500)
		const_chunk = CONST_CHUNK500;
	return (const_chunk);
}

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

void	push_swap(t_stack **stack_a, t_stack **stack_b, int const_chunk)
{
	int		size;

	size = stack_size(*stack_a);
	if (size == 2 && !sorted_args(*stack_a))
		swap_a(stack_a);
	else if (size == 3 && !sorted_args(*stack_a))
		sort_three(stack_a);
	else if ((size > 3 && size <= 5) && !sorted_args(*stack_a))
		sort_small(stack_a, stack_b);
	else if (size > 5 && !sorted_args(*stack_a))
		sort_big(stack_a, stack_b, const_chunk);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			const_chunk;

	if (argc < 2)
		return (0);
	if (!check_args(argv))
	{
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	const_chunk = get_const_chunk(stack_a);
	sort_position(stack_a);
	flag_lis_values(stack_a, assign_lis_count(stack_a));
	push_swap(&stack_a, &stack_b, const_chunk);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
