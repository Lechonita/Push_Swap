/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:56:11 by jrouillo          #+#    #+#             */
/*   Updated: 2023/01/30 15:44:07 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_push(t_stack **a, t_stack **b, int const_chunk)
{
	// display_stack(*a, *b);
	int	size;
	int	nb;
	int	i;

	nb = stack_size(*a) / const_chunk;
	// printf("nb = size_a / const_chunk\nnb = %d / %d\n", stack_size(*a), const_chunk);
	i = nb / 2;
	// printf("i ===== nb / 2\n%d ===== %d / 2\n", i, nb);
	while (i >= 0)
	{
		size = stack_size(*a);
		// printf("size = %d\n", size);
		// printf("i = %d\n", i);
		while (size)
		{
			// printf("while size >= 0 ---> %d\n", size);
			// printf("nb = %d\ni = %d\n", nb, i);
			// printf("pb if pos_a < (nb - i + 1) * chk\n");
			// printf("pb if %d < (%d - %d + 1) * %d\n", (*a)->pos, nb, i, const_chunk);
			// display_stack(*a, *b);
			if (((*a)->pos < ((nb - i + 1) * const_chunk))
				&& ((*a)->pos >= (nb - i) * const_chunk) && !(*a)->lis_flag)
				{
					push_b(a, b);
					// display_stack(*a, *b);
				}
			else if (((*a)->pos >= (i * const_chunk))
				&& ((*a)->pos < ((i + 1) * const_chunk)) && !(*a)->lis_flag)
				push_rotate_b(a, b);
			else
				rotate_a(a);
			size--;
		}
		i--;
	}
}

void	push_rotate_b(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	rotate_b(stack_b);
}

void	smart_rotate_a(t_stack **stack, int pos)
{
	int	size;
	int	i;

	if (!(*stack))
		return ;
	assign_index(*stack);
	size = stack_size(*stack);
	i = find_stack_index(*stack, pos);
	if (i > size / 2)
	{
		while ((*stack)->index != i)
			rev_rotate_a(stack);
	}
	else if (i < size / 2 || i == size / 2)
	{
		while ((*stack)->index != i)
			rotate_a(stack);
	}
}
