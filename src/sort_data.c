/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:08:31 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 20:23:57 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	stack_b->used = 0;
	if (stack_a->used == 2)
		ft_sort_two_numbers(stack_a);
	else if (stack_a->used == 3)
		ft_sort_three_numbers(stack_a);
	else if (stack_a->used <= 5)
		ft_sort_five_numbers(stack_a, stack_b);
	else
		ft_sort_using_sequence(stack_a, stack_b);
}
