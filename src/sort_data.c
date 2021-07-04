/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:08:31 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/04 13:40:04 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_continue(int *items, t_vector *stack)
{
	if (items[1] > items[2] && items[0] < items[2])
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("ra\n", 1);
		ft_swap(stack);
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

int	ft_push_median_lowests(t_vector *stack_a, t_vector *stack_b,
		double median)
{
	int	i;
	int	half_stack;

	i = 0;
	half_stack = 0;
	half_stack = stack_a->used / 2;
	while (i < half_stack)
	{
		if ((*(int *)stack_a->vector_get(stack_a, 0) + 0.0) < median)
		{
			ft_putstr_fd("pb\n", 1);
			ft_push(stack_a, stack_b);
			i++;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
		}
	}
	return (0);
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

void	ft_get_max_and_min(int *items, int len, int *min, int *max)
{
	int	i;

	i = 0;
	*max = INT_MIN;
	*min = INT_MAX;
	while (i < len)
	{
		if (items[i] < *min)
			*min = items[i];
		if (items[i] > *max)
			*max = items[i];
		i++;
	}
}

int	ft_find_max_index(t_vector *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	ft_get_max_and_min(stack->items, stack->used, &min, &max);
	while (i < stack->used - 1)
	{
		if (*(int *)stack->vector_get(stack, i) == max)
			break ;
		i++;
	}
	return (i);
}

int	ft_find_min_index(t_vector *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	ft_get_max_and_min(stack->items, stack->used, &min, &max);
	while (i < stack->used - 1)
	{
		if (*(int *)stack->vector_get(stack, i) == min)
			break ;
		i++;
	}
	return (i);
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

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	stack_b->used = 0;
	if (stack_a->used == 2)
		ft_sort_two_numbers(stack_a);
	else if (stack_a->used == 3)
		ft_sort_three_numbers(stack_a);
	else if (stack_a->used == 5)
		ft_sort_five_numbers(stack_a, stack_b);
	else
		ft_sort_using_sequence(stack_a, stack_b);
}
