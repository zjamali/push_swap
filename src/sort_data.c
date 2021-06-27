/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:08:31 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/27 21:01:01 by zjamali          ###   ########.fr       */
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
			ft_push(stack_a, stack_b);
			i++;
		}
		else
			ft_rotate(stack_a);
	}
	return (0);
}

/*
* desired_stack = 0 -> a || desired_stack = 1 ->b
* 0 = no_move ; 1  = rr ; 2 = swap + rr ;
*/

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

void	ft_sort_three_numbers(t_vector *stack)
{
	int	*items;

	items = stack->items;
	if (items[0] > items[1] && items[0] < items[2])
	{
		ft_putstr_fd("sa", 1);
		ft_swap(stack);
	}
	else if (items[0] > items[1] && items[1] > items[2])
	{
		ft_putstr_fd("sa", 1);
		ft_putstr_fd("rra", 1);
		ft_swap(stack);
		ft_reverse_rotate(stack);
	}
	else if (items[0] > items[1] && items[1] < items[2])
	{
		ft_putstr_fd("ra", 1);
		ft_rotate(stack);
	}
	else if (items[1] > items[2] && items[0] < items[2])
	{
		ft_putstr_fd("sa", 1);
		ft_putstr_fd("ra", 1);
		ft_swap(stack);
		ft_rotate(stack);
	}
	else if (items[0] < items[1] && items[0] > items[2])
	{
		ft_putstr_fd("rra", 1);
		ft_reverse_rotate(stack);
	}
}

void	ft_sort_two_numbers(t_vector *stack)
{
	int *items;

	items = stack->items;
	if ( items[0] > items[1])
	{
		ft_putstr_fd("sa", 1);
		ft_swap(stack);
	}
}

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	stack_b->used = 0;
	printf("%d\n", stack_a->used);
	if (stack_a->used == 2)
		ft_sort_two_numbers(stack_a);
	if (stack_a->used == 3)
	{
		ft_sort_three_numbers(stack_a);
	}
}
