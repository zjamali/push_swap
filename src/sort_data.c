/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:08:31 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/29 19:25:58 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* desired_stack = 0 -> a || desired_stack = 1 ->b
* 0 = no_move ; 1  = rr ; 2 = swap + rr ;
*/
/*
int	ft_check_stack_top(t_vector *stack, int desired_stack, int min, int max)
{
	int	*stack_items;

	printf("stack = %d\t",desired_stack);
	for (int i = 0; i < stack->used; i++)
	{
		printf("%d ", *(int *)stack->vector_get(stack, i));
	}
	stack_items = stack->items;
	if (desired_stack == 0)
	{
		if (stack_items[0] > stack_items[1])
		{
			if (stack_items[0] == max && stack_items[1] == min)
				return (1);
			return (2);
		}
		else
			return (1);
	}
	else if (desired_stack == 1)
	{
		if (stack_items[0] < stack_items[1])
		{
			if (stack_items[0] == min && stack_items[1] == max)
				return (1);
			return (2);
		}
	}
	return (0);
}
*/

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

int	ft_get_min_index(t_vector *stack)
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

	min_index = ft_get_min_index(stack_a);
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
/*
void	ft_sort_ten_numbers(t_vector *stack_a, t_vector *stack_b)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		push_two_min_numbers(stack_a, stack_b);
		i++;
	}
	ft_sort_five_numbers(stack_a, stack_b);
	i = 0;
	while (i < 5)
	{
		ft_putstr_fd("pa\n", 1);
		ft_push(stack_b, stack_a);
		i++;
	}
}
*/
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
/*
void	select_sort_swap(int *array, int i, int min_index)
{
	int	tmp;

	tmp = array[min_index];
	array[min_index] = array[i];
	array[i] = tmp;
}

void	ft_select_sort(int *sorted,int array_len)
{
	int	min_index;
	int	i;
	int	j;

	i = 0;
	while (i < array_len)
	{
		min_index = i;
		j = i + 1;
		while (j < array_len)
		{
			if (sorted[j] < sorted[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
			select_sort_swap(sorted, i, min_index);
		i++;
	}
}

void	ft_sort_hundr_less_numbers(t_vector *stack_a, t_vector *stack_b)
{
	int	i;
	int	*sorted;

	(void)stack_b;
	i = 0;
	sorted = (int *)malloc(sizeof(int) * stack_a->used + 0);
	i = 0;
	while (i < stack_a->used)
	{
		sorted[i] = *(int *)stack_a->vector_get(stack_a, i);
		i++;
	}
	ft_select_sort(sorted, stack_a->used);
	for (int i = 0; i < stack_a->used; i++)
		printf("%d\n",sorted[i]);	
}
*/

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	stack_b->used = 0;
	if (stack_a->used == 2)
		ft_sort_two_numbers(stack_a);
	else if (stack_a->used == 3)
		ft_sort_three_numbers(stack_a);
	else
	{
		ft_sort_using_sequence(stack_a, stack_b);
		printf("stack a:\n");
		for (int i = 0; i < stack_a->used; i++)
			printf("%d\t",*(int *)stack_a->vector_get(stack_a,i));
		printf("\nstack b:\n");
		for (int i = 0; i < stack_b->used; i++)
			printf("%d\t",*(int *)stack_b->vector_get(stack_b,i));
	}
	//else if (stack_a->used == 5)
	//	ft_sort_five_numbers(stack_a, stack_b);
	//else if (stack_a->used == 10)
	//	ft_sort_ten_numbers(stack_a, stack_b);
	//else if (stack_a->used > 10 && stack_a->used <= 100)
	//	ft_sort_hundr_less_numbers(stack_a, stack_b);
}
