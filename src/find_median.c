/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:26:04 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/23 18:33:29 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_max_and_min(int *items, int len, int *min, int *max)
{
	int	i;

	i = 0;
	*max = INT_MIN;
	*min = INT_MAX;
	while (i < len)
	{
		if (*(items + i) < *min)
			*min = *(items + i);
		if (*(items + i) > *max)
			*max = *(items + i);
		i++;
	}
}

int	*count_lower_upper(int *items, double median, int len)
{
	int	i;
	int	*lower_upper;

	lower_upper = (int *)malloc(sizeof(int) * 2);
	lower_upper[0] = 0;
	lower_upper[1] = 0;
	i = 0;
	while (i < len)
	{
		if (median > *(items + i))
			lower_upper[0] = lower_upper[0] + 1;
		if (median < *(items + i))
			lower_upper[1] = lower_upper[1] + 1;
		i++;
	}
	return (lower_upper);
}

double	recur_get_the_medina(int *items, int index, t_medain mid,
	int *lower_upper)
{
	if (lower_upper[0] > lower_upper[1])
	{
		mid.max = mid.median;
		return (get_the_median(items, index + 1, mid));
	}
	else
	{
		mid.min = mid.median;
		return (get_the_median(items, index + 1, mid));
	}
	return (mid.median);
}

double	get_the_median(int *items, int index, t_medain mid)
{
	double	median;
	int		*lower_upper;

	while (index < mid.array_leng)
	{
		median = *(items + index);
		if (median < mid.max && median > mid.min)
		{
			lower_upper = count_lower_upper(items, median, mid.array_leng);
			if (lower_upper[0] == lower_upper[1])
				return (median);
			else
			{
				mid.median = median;
				return (recur_get_the_medina(items, index, mid, lower_upper));
			}
		}
		else
			index++;
		if (mid.array_leng % 2 == 0)
			median = (mid.min + mid.max) / 2;
	}
	return (median);
}

double 	finding_the_median(t_vector *stack)
{
	t_medain	median;
	int			max;
	int			min;

	min = INT_MAX;
	max = INT_MIN;
	ft_get_max_and_min(stack->items, stack->used, &min, &max);
	median.array_leng = stack->used;
	median.items = stack->items;
	median.min = min + 0.0;
	median.max = max + 0.0;
	median.median = get_the_median(stack->items, 0, median);
	return (median.median);
}
