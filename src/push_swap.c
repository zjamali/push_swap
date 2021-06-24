/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:54:19 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/24 20:20:24 by zjamali          ###   ########.fr       */
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
		stack->vector_add(stack, &number);
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
			ft_push(stack_a, stack_b);
			i++;
		}
		else
			ft_rotate(stack_a);
	}
	return (0);
}

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
	is_sorted->is_sorted = 2;
	*i = index_min_or_max;
	is_sorted->prev_num = items[*i];
	is_sorted->items_compared = 0;
	(*i)++;
}

int	ft_check_array_circular_sorted_dwn(int *items, int len, int min_index)
{
	t_is_sorted	check_sorted;
	int			i;

	init_check_is_sort(&check_sorted, min_index, &i, items);
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
		{
			return (-1);
		}
	}
	return (check_sorted.is_sorted);
}

int	ft_check_array_circular_sorted_up(int *items, int len, int max_index)
{
	t_is_sorted	check_sorted;
	int			i;

	init_check_is_sort(&check_sorted, max_index, &i, items);
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
	printf("min index = %d \t max index = %d \n", min_index, max_index);
	is_sorted = ft_check_array_circular_sorted_dwn(stack->items, stack->used,
			min_index);
	if (is_sorted == -1)
	{
		is_sorted = ft_check_array_circular_sorted_up(stack->items, stack->used,
				max_index);
	}
	if (is_sorted == 1)
		printf("UP SORTED\n");
	else if (is_sorted == 2)
		printf("DOWN SORTED\n");
	else
		printf("NOT SORTED\n");
	return (is_sorted);
}

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	double	median;

	median = finding_the_median(stack_a);
	printf("the median = %f \n", median);
	ft_push_median_lowests(stack_a, stack_b, median);
	//ft_check_stack_circular_sorted(stack_a);
	printf("stack b :");
	for (int i = 0; i < stack_b->used; i++)
	{
		printf("%d ", *(int *)stack_b->vector_get(stack_b, i));
	}
	printf("\nstack a :");
	for (int i = 0; i < stack_a->used; i++)
	{
		printf("%d ", *(int *)stack_a->vector_get(stack_a, i));
	}
}

void	push_swap(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;

	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	if (ft_check_data_is_sorted(stack_a))
	{
		for (int i = 0; i < stack_a.used; i++)
		{
			printf("%d ",*(int *)stack_a.vector_get(&stack_a, i));
		}
		printf("\n sort: \n");
		//ft_sort_stack(&stack_a, &stack_b);

	}
	ft_check_stack_circular_sorted(&stack_a);
	stack_a.vector_free(&stack_a);
	stack_a.vector_free(&stack_b);
}
