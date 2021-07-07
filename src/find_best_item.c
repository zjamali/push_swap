/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:52:59 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/07 19:54:46 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_op(t_vector *stack_a, t_vector *stack_b, int idx_in_a,
		int idx_in_b)
{
	int	ops;

	if (idx_in_a < stack_a->used - idx_in_a)
		ops = idx_in_a;
	else
		ops = stack_a->used - idx_in_a;
	if (idx_in_b < stack_b->used - idx_in_b)
		ops = ops + idx_in_b;
	else
		ops = ops + stack_b->used - idx_in_b ;
	return (ops);
}

int	find_place_continue(t_vector *stack, int number, int last_index)
{
	int	min_index;
	int	max_index;
	int	*items;

	items = stack->items;
	min_index = ft_find_min_index(stack);
	max_index = ft_find_max_index(stack);
	if (items[max_index] < number)
	{
		if (max_index + 1 > last_index)
			return (0);
		else
			return (max_index + 1);
	}
	if (number > items[min_index] && number > items[max_index])
	{
		if (min_index == 0)
			return (0);
		return (min_index - 1);
	}
	return (0);
}

int	find_place(t_vector *stack, int number)
{
	int	i;
	int	*items;
	int	last_index;
	int	best_index;

	last_index = stack->used - 1;
	items = stack->items;
	i = 0;
	best_index = 0;
	while (i < last_index)
	{
		if ((number > items[i] && number < items[i + 1]))
			return (i + 1);
		i++;
	}
	if (items[0] < number && number < items[last_index])
		return (last_index - 1);
	return (find_place_continue(stack, number, last_index));
}

int	find_best(t_vector *stack_a, t_vector *stack_b)
{
	int			i;
	t_vector	find_best;
	int			index_in_a;
	int			op_count;
	int			min_ops_index;

	ft_vector_init(&find_best, sizeof(int));
	i = 0;
	while (i < stack_b->used)
	{
		index_in_a = find_place(stack_a,
				*(int *)stack_b->vector_get(stack_b, i));
		op_count = ft_count_op(stack_a, stack_b, index_in_a, i);
		find_best.vector_add(&find_best, &op_count);
		i++;
	}
	min_ops_index = 0;
	min_ops_index = ft_find_min_index(&find_best);
	find_best.vector_free(&find_best);
	return (min_ops_index);
}
