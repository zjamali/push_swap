/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:41:23 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 21:56:09 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two_mins(t_vector *stack_a, t_vector *stack_b, int *mins)
{
	while (stack_a->used > 3)
	{
		if (mins[0] == *(int *)stack_a->vector_get(stack_a, 0)
			|| mins[1] == *(int*)stack_a->vector_get(stack_a, 0))
		{
			ft_putstr_fd("pb\n", 1);
			ft_push(stack_a, stack_b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
		}
	}
}

void	ft_push_b_two_min_numbers(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	tmp;
	int			min_index;
	int			i;
	static int	mins[2];

	ft_vector_init(&tmp, sizeof(int));
	min_index = ft_find_min_index(stack_a);
	mins[0] = *(int *)stack_a->vector_get(stack_a, min_index);
	i = 0;
	while (i < stack_a->used)
	{
		if (min_index != i)
			tmp.vector_add(&tmp, stack_a->vector_get(stack_a, i));
		i++;
	}
	min_index = ft_find_min_index(&tmp);
	mins[1] = *(int *)tmp.vector_get(&tmp, min_index);
	tmp.vector_free(&tmp);
	push_two_mins(stack_a, stack_b, mins);
}

void	ft_push_b_min_number(t_vector *stack_a, t_vector *stack_b)
{
	int			min_index;
	int			i;
	int			min_number;

	i = 0;
	min_index = ft_find_min_index(stack_a);
	min_number = *(int *)stack_a->vector_get(stack_a, min_index);
	while (i < stack_a->used)
	{
		if (min_number == *(int *)stack_a->vector_get(stack_a, 0))
		{
			ft_putstr_fd("pb\n", 1);
			ft_push(stack_a, stack_b);
			break ;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
		}
	}
}

void	push_min_numbers(t_vector *stack_a, t_vector *stack_b)
{
	if (stack_a->used == 5)
		ft_push_b_two_min_numbers(stack_a, stack_b);
	else
		ft_push_b_min_number(stack_a, stack_b);
}

void	ft_sort_five_numbers(t_vector *stack_a, t_vector *stack_b)
{
	int		*items;

	push_min_numbers(stack_a, stack_b);
	if (stack_b->used == 2)
	{
		items = stack_b->items;
		if (items[0] < items[1])
		{
			ft_putstr_fd("sb\n", 1);
			ft_swap(stack_b);
		}
	}
	ft_sort_three_numbers(stack_a);
	ft_putstr_fd("pa\n", 1);
	ft_push(stack_b, stack_a);
	if (stack_b->used == 1)
	{
		ft_putstr_fd("pa\n", 1);
		ft_push(stack_b, stack_a);
	}
}
