/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:56:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/09 15:14:45 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_op & do_both_op :
	Checks that the operations entered in the standard output are valid
	operations. */

void	do_both_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "ss\n"))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free(line);
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

void	do_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(line, "sa\n"))
		swap(*stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(*stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(stack_b);
	else
		do_both_op(line, stack_a, stack_b);
}

/* Reads the line in the standard output and checks that it is a 
	correct operation (do_op & do_both_op).
	If the stack A is sorted correctly and stack B is empty,
	return "OK" on the standard output. Else, return "KO". */

void	gnl_and_result(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_op(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (stack_a && sorted_args(stack_a) && !stack_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit (0);
	if (!check_args(argv))
	{
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	gnl_and_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
