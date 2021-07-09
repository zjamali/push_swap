/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:51:49 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/09 14:55:40 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_align_stacks_using_rotate(t_vector *stack_a, t_vector *stack_b,
			int move_a, int move_b)
{
	while (move_a > 0 && move_b > 0)
	{
		ft_putstr_fd("rr\n", 1);
		ft_rotate_both_stacks(stack_a, stack_b);
		move_a--;
		move_b--;
	}
	while (move_a > 0)
	{
		ft_putstr_fd("ra\n", 1);
		ft_rotate(stack_a);
		move_a--;
	}
	while (move_b > 0)
	{
		ft_putstr_fd("rb\n", 1);
		ft_rotate(stack_b);
		move_b--;
	}
}

void	ft_align_stacks_using_rev_rotate(t_vector *stack_a, t_vector *stack_b,
			int move_a, int move_b)
{
	while (move_a < 0 && move_b < 0)
	{
		ft_putstr_fd("rrr\n", 1);
		ft_reverse_rotate_both_stacks(stack_a, stack_b);
		move_a = move_a + 1;
		move_b = move_b + 1;
	}
	while (move_a < 0)
	{
		ft_putstr_fd("rra\n", 1);
		ft_reverse_rotate(stack_a);
		move_a = move_a + 1;
	}
	while (move_b < 0)
	{
		ft_putstr_fd("rrb\n", 1);
		ft_reverse_rotate(stack_b);
		move_b = move_b + 1;
	}	
}

void	ft_align_stacks(t_vector *stack_a, t_vector *stack_b,
			int move_a, int move_b)
{
	while (move_a < 0)
	{
		ft_putstr_fd("rra\n", 1);
		ft_reverse_rotate(stack_a);
		move_a = move_a + 1;
	}
	while (move_b < 0)
	{
		ft_putstr_fd("rrb\n", 1);
		ft_reverse_rotate(stack_b);
		move_b = move_b + 1;
	}
	while (move_a > 0)
	{
		ft_putstr_fd("ra\n", 1);
		ft_rotate(stack_a);
		move_a--;
	}
	while (move_b > 0)
	{
		ft_putstr_fd("rb\n", 1);
		ft_rotate(stack_b);
		move_b--;
	}
}

void	ft_align_both_stacks(t_vector *stack_a, t_vector *stack_b,
			int move_a, int move_b)
{
	if ((move_a * move_b) > 0)
	{
		if (move_a > 0)
			ft_align_stacks_using_rotate(stack_a, stack_b, move_a, move_b);
		else
			ft_align_stacks_using_rev_rotate(stack_a, stack_b, move_a, move_b);
	}
	else
		ft_align_stacks(stack_a, stack_b, move_a, move_b);
}

void	ft_sort_stack_a(t_vector *stack_a)
{
	int	min_index;

	min_index = ft_find_min_index(stack_a);
	if (min_index == 0)
		return ;
	if (min_index > (stack_a->used / 2))
	{
		while (min_index < stack_a->used)
		{
			ft_putstr_fd("rra\n", 1);
			ft_reverse_rotate(stack_a);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
			min_index--;
		}
	}
}
