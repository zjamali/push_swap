/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:54:19 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/23 18:07:11 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_data_stack(t_vector *stack, char **data)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (data[i])
	{
		number = ft_atoi(data[i]);
		stack->vector_add(stack,&number);
		i++;
		number = 0;
	}
}

int	ft_check_data_is_sorted(t_vector stack)
{
	int	i;
	int	big_number;

	i = 0;
	big_number = 0;
	while (i < stack.used)
	{
		if (big_number > *(int *)stack.vector_get(&stack, i))
			return (1);
		big_number = *(int *)stack.vector_get(&stack, i);
		i++;
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
		if (*(items + i) < *min)
			*min = *(items + i);
		if (*(items + i) >  *max)
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
				if (lower_upper[0] > lower_upper[1])
				{
					mid.max = median;
					return (get_the_median(items, index + 1, mid));
				}
				else
				{
					mid.min = median;
					return (get_the_median(items, index + 1, mid));
				}
			}
		}
		else
			index++;
		if (mid.array_leng % 2 == 0)
			median = (mid.min + mid.max) / 2;
	}
	return (median);
}

void	finding_the_median(t_vector *stack)
{
	t_medain	median;
	int			max;
	int			min;

	min = INT_MAX;
	max = INT_MIN;
	ft_get_max_and_min(stack->items, stack->used, &min, &max);
	printf("min = %d \t max = %d\t", min, max);
	median.array_leng = stack->used;
	printf("used = %d\n\n",stack->used);
	median.items = stack->items;
	median.min = min + 0.0;
	median.max = max + 0.0;
	median.median = get_the_median(stack->items, 0, median);
	printf(" the median = %f\n",median.median);
}

void	push_swap(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;

	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	ft_push_to_data_stack(&stack_b, data);
	if (ft_check_data_is_sorted(stack_a))
	{
		for (int i = 0; i < stack_a.used; i++)
		{
			printf("%d ",*(int *)stack_a.vector_get(&stack_a,i));
		}
		printf("\n");
	}
	finding_the_median(&stack_a);
	stack_a.vector_free(&stack_a);
}