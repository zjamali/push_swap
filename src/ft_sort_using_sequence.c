/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_using_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:09:16 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/14 15:26:21 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_number_in_squence(int number, t_vector *longet_inc_sequence)
{
	int	i;
	int	*items;

	i = 0;
	items = longet_inc_sequence->items;
	while (i < longet_inc_sequence->used)
	{
		if (number == items[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_push_to_b(t_vector *stack_a, t_vector *stack_b,
		t_vector *longet_inc_sequence)
{
	int	i;
	int	top;

	i = 0;
	while (stack_a->used > longet_inc_sequence->used)
	{
		top = *(int *)stack_a->vector_get(stack_a, 0);
		if (ft_check_number_in_squence(top, longet_inc_sequence))
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
}

int	count_moves_in_stack_b(t_vector *stack, int best_index)
{
	int	ops;
	int	sign;

	if (best_index == stack->used)
		return (-1);
	sign = 1;
	if (best_index < stack->used - best_index)
		ops = best_index;
	else
	{
		sign = -1;
		ops = (stack->used - best_index);
	}
	return (sign * ops);
}

int	count_moves_in_stack_a(t_vector *stack, int best_number)
{
	int	half_stack;
	int	best_number_place;

	half_stack = (stack->used + 1) / 2;
	best_number_place = find_place(stack, best_number);
	if (best_number_place == 0)
		return (0);
	if (best_number_place == stack->used)
		return (-1);
	else
	{
		if (half_stack < best_number_place)
			return ((stack->used - best_number_place) * -1);
		else
			return (best_number_place);
	}
}

void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	*long_inc_sequence;
	int			best_index;
	int			count_moves_a;
	int			count_moves_b;

	long_inc_sequence = ft_long_inc_sequnce(stack_a);
	ft_push_to_b(stack_a, stack_b, long_inc_sequence);
	long_inc_sequence->vector_free(long_inc_sequence);
	free(long_inc_sequence);
	while (stack_b->used > 0)
	{
		best_index = find_best(stack_a, stack_b);
		count_moves_a = count_moves_in_stack_a(stack_a,
				*(int *)stack_b->vector_get(stack_b, best_index));
		count_moves_b = count_moves_in_stack_b(stack_b, best_index);
		ft_align_both_stacks(stack_a, stack_b, count_moves_a, count_moves_b);
		ft_putstr_fd("pa\n", 1);
		ft_push(stack_b, stack_a);
	}
	ft_sort_stack_a(stack_a);
}
