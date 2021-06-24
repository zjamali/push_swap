/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:26:04 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/24 16:35:57 by zjamali          ###   ########.fr       */
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

void	count_uppers(int *items, int curr_num, int len, int *uppers)
{
	int	i;

	i = 0;
	*uppers = 0;
	while (i < len)
	{
		if (curr_num < items[i])
			*uppers = *uppers + 1;
		i++;
	}
}

void	count_lowers(int *items, int curr_num, int len, int *lowes)
{
	int	i;

	i = 0;
	*lowes = 0;
	while (i < len)
	{
		if (curr_num > items[i])
			*lowes = *lowes + 1;
		i++;
	}
}

void	new_min_max(int curr_num, int *min, int *max, int *lower_upper)
{
	if (lower_upper[0] > lower_upper[1])
		*max = curr_num;
	else
		*min = curr_num;
}

double	get_the_median(int *items, int array_length, int min, int max)
{
	int			index;
	float		median;
	int			curr_num;
	static int	lower_upper[2];

	median = 0.0;
	index = 0;
	while (index < array_length)
	{
		curr_num = items[index];
		if (curr_num > min && curr_num < max)
		{
			count_lowers(items, curr_num, array_length, &lower_upper[0]);
			count_uppers(items, curr_num, array_length, &lower_upper[1]);
			if (lower_upper[0] == lower_upper[1])
				return (curr_num);
			else
				new_min_max(curr_num, &min, &max, lower_upper);
		}
		index++;
	}
	if (array_length % 2 == 0)
		median = (min + max) / 2.0;
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
	printf("min:%d \t max:%d\n", min, max);
	median.array_leng = stack->used;
	median.items = stack->items;
	median.min = min + 0.0;
	median.max = max + 0.0;
	median.median = get_the_median(stack->items, stack->used, min, max);
	return (median.median);
}
