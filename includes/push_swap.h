/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:41 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/09 14:42:27 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* LIBRARIES */

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

/* CONSTANTS */

# define SWAP_AB "ss"
# define ROT_AB "rr"
# define RVROT_AB "rrr"
# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB "sb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

# define CONST_CHUNK100 20
# define CONST_CHUNK500 50

# define BUFFER_SIZE BUFSIZ

/* STRUCTURE */

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				lis_count;
	int				lis_flag;
	int				cost;
	struct s_stack	*next;
}	t_stack;

/* PUSH SWAP */
void		push_swap(t_stack **stack_a, t_stack **stack_b, int const_chunk);
int			get_const_chunk(t_stack *stack_a);

/* UTILS */
void		assign_index(t_stack *stack);
int			highest_pos(t_stack *stack);
int			lowest_pos(t_stack *stack);
int			find_stack_index(t_stack *stack, int pos);
int			stack_size(t_stack *stack);

/* CONTROLS */
int			compare_nb(char *argv1, char *argv2);
int			check_duplicates(char **argv);
int			checkint_min_max(char *argv);
int			ft_signed_digit(char *argv);
int			check_args(char **argv);

/* STACKS */
t_stack		*fill_stack(int argc, char **argv);
t_stack		*stack_a_new(int nb, int ind);
t_stack		*stack_a_last(t_stack *stack_a);
void		stack_a_addback(t_stack **stack_a, t_stack *nb);
void		free_stack(t_stack **stack);

/* SORT */
int			sorted_args(t_stack *stack);
void		sort_position(t_stack *stack_a);
void		sort_three(t_stack **stack);
void		sort_small(t_stack **stack_a, t_stack **stack_b);
void		sort_big(t_stack **stack_a, t_stack **stack_b, int const_chunk);

/* SMART */
void		smart_push(t_stack **stack_a, t_stack **stack_b, int const_chunk);
void		push_rotate_b(t_stack **stack_a, t_stack **stack_b);
void		smart_rotate_a(t_stack **stack, int pos);

/* LIS */
int			assign_lis_count(t_stack *stack);
int			lis_length(t_stack *stack);
void		flag_lis_values(t_stack *stack, int max_lis);

/* COST */
void		get_cost(t_stack **stack);
void		find_cheapest(t_stack **stack_a, t_stack **stack_b, int size_a);
void		move_cheapest(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* CHEAPEST MOVES */
void		cheapest_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		cheapest_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		ra_rra(t_stack **stack_a, int *cost_a);
void		rb_rrb(t_stack **stack_b, int *cost_b);

/* COST UTILS */
int			ft_abs(int nb);
int			find_stack_cost(t_stack *stack, int pos, int size_a);
int			find_target_node(t_stack *stack_a, int pos_b);

/************************************************************/
/************************** RULLES **************************/
/************************************************************/

/* SWAP */
void		swap(t_stack *stack);
void		swap_a(t_stack **stack);
void		swap_b(t_stack **stack);
void		swap_ss(t_stack **stack_a, t_stack **stack_b);

/* PUSH */
void		push(t_stack **src, t_stack **dest);
void		push_a(t_stack **stack_b, t_stack **stack_a);
void		push_b(t_stack **stack_a, t_stack **stack_b);

/* ROTATE */
void		rotate(t_stack **stack);
void		rotate_a(t_stack **stack);
void		rotate_b(t_stack **stack);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b);

/* REVERSE ROTATE*/
void		reverse_rotate(t_stack **stack);
void		rev_rotate_a(t_stack **stack);
void		rev_rotate_b(t_stack **stack);
void		rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b);

/************************************************************/
/************************** BONUS ***************************/
/************************************************************/

/* CHECKER */
void		gnl_and_result(t_stack *stack_a, t_stack *stack_b);
void		do_op(char *line, t_stack **stack_a, t_stack **stack_b);
void		do_both_op(char *line, t_stack **stack_a, t_stack **stack_b);

/* GET NEXT LINE */
char		*ft_free_strjoin(char *s1, char *s2);
char		*get_line(char *str, char *tmp);
char		*get_line_store(char *str);
char		*get_str(int fd, char *str);
char		*get_next_line(int fd);

#endif