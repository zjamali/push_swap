/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_then_five_numbers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:05:35 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 21:06:03 by zjamali          ###   ########.fr       */
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
