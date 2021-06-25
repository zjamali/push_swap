/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_circular_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 06:58:51 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/25 14:56:02 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(int *items, int len, int min_max)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (min_max == items[i])
			break ;
		i++;
	}
	return (i);
}

void	init_check_is_sort(t_is_sorted *is_sorted, int index_min_or_max, int *i,
		int *items)
{
	*i = index_min_or_max;
	is_sorted->prev_num = items[*i];
	is_sorted->items_compared = 0;
	is_sorted->curr_num = 0;
	(*i)++;
}

int	ft_check_array_circular_sorted_dwn(int *items, int len, int min_index)
{
	t_is_sorted	check_sorted;
	int			i;

	init_check_is_sort(&check_sorted, min_index, &i, items);
	check_sorted.is_sorted = 1;
	if (i == len)
		i = 0;
	while (i < len && check_sorted.items_compared < len - 1)
	{
		check_sorted.curr_num = items[i];
		if (check_sorted.curr_num > check_sorted.prev_num)
		{
			check_sorted.prev_num = check_sorted.curr_num;
			check_sorted.items_compared++;
			i++;
			if (i == len && check_sorted.items_compared < len - 1)
				i = 0;
		}
		else
			return (-1);
	}
	return (check_sorted.is_sorted);
}

int	ft_check_array_circular_sorted_up(int *items, int len, int max_index)
{
	t_is_sorted	check_sorted;
	int			i;

	init_check_is_sort(&check_sorted, max_index, &i, items);
	check_sorted.is_sorted = 2;
	if (i == len)
		i = 0;
	while (i < len && check_sorted.items_compared < len - 1)
	{
		check_sorted.curr_num = items[i];
		if (check_sorted.curr_num < check_sorted.prev_num)
		{
			check_sorted.prev_num = check_sorted.curr_num;
			check_sorted.items_compared++;
			i++;
			if (i == len && check_sorted.items_compared < len - 1)
				i = 0;
		}
		else
			return (-1);
	}
	return (check_sorted.is_sorted);
}

/*
* int	is_sorted; // 1 down sorted 2 up sorted
*/

int	ft_check_stack_circular_sorted(t_vector *stack)
{
	int	min;
	int	max;
	int	min_index;
	int	max_index;
	int	is_sorted;

	ft_get_max_and_min(stack->items, stack->used, &min, &max);
	min_index = ft_get_index(stack->items, stack->used, min);
	max_index = ft_get_index(stack->items, stack->used, max);
	is_sorted = ft_check_array_circular_sorted_dwn(stack->items, stack->used,
			min_index);
	if (is_sorted == -1)
	{
		is_sorted = ft_check_array_circular_sorted_up(stack->items, stack->used,
				max_index);
	}
	return (is_sorted);
}
