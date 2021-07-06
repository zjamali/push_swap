/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:41:23 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 16:47:12 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_continue(int *items, t_vector *stack)
{
	if (items[1] > items[2] && items[0] < items[2])
	{
		ft_putstr_fd("sa\n", 1);
		ft_swap(stack);
		ft_putstr_fd("ra\n", 1);
		ft_rotate(stack);
	}
	else if (items[0] < items[1] && items[0] > items[2])
	{
		ft_putstr_fd("rra\n", 1);
		ft_reverse_rotate(stack);
	}
}

void	ft_sort_three_numbers(t_vector *stack)
{
	int	*items;

	items = stack->items;
	if (items[0] > items[1] && items[0] < items[2])
	{
		ft_putstr_fd("sa\n", 1);
		ft_swap(stack);
	}
	else if (items[0] > items[1] && items[1] > items[2])
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
		ft_swap(stack);
		ft_reverse_rotate(stack);
	}
	else if (items[0] > items[1] && items[1] < items[2])
	{
		ft_putstr_fd("ra\n", 1);
		ft_rotate(stack);
	}
	else
		ft_sort_three_continue(items, stack);
}

void	ft_sort_two_numbers(t_vector *stack)
{
	int	*items;

	items = stack->items;
	if (items[0] > items[1])
	{
		ft_putstr_fd("sa\n", 1);
		ft_swap(stack);
	}
}

void	push_two_min_numbers(t_vector *stack_a, t_vector *stack_b)
{
	int	min_index;

	min_index = ft_find_min_index(stack_a);
	if (min_index > ((stack_a->used - 1) / 2))
	{
		while (min_index < stack_a->used)
		{
			ft_putstr_fd("rra\n", 1);
			ft_reverse_rotate(stack_a);
			min_index++;
		}
		ft_putstr_fd("pb\n", 1);
		ft_push(stack_a, stack_b);
	}
	else
	{
		while (min_index > 0)
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
			min_index--;
		}
		ft_putstr_fd("pb\n", 1);
		ft_push(stack_a, stack_b);
	}
}

void	ft_sort_five_numbers(t_vector *stack_a, t_vector *stack_b)
{
	double	median;
	int		*items;

	median = finding_the_median(stack_a);
	ft_push_median_lowests(stack_a, stack_b, median);
	items = stack_b->items;
	if (items[0] < items[1])
	{
		ft_putstr_fd("sb\n", 1);
		ft_swap(stack_b);
	}
	ft_sort_three_numbers(stack_a);
	ft_putstr_fd("pa\n", 1);
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
	ft_push(stack_b, stack_a);
}
