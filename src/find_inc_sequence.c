/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inc_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:48:40 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/14 15:25:00 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*compute_lis_indexs_values(int *items, int len, int *max)
{
	int	*long_squence;
	int	i;
	int	j;

	long_squence = (int *)malloc(sizeof(int) * len);
	long_squence[0] = 1;
	i = 1;
	*max = 0;
	while (i < len)
	{
		long_squence[i] = 1;
		j = 0;
		while (j < i)
		{
			if (items[i] > items[j] && long_squence[i] < long_squence[j] + 1)
			{
				long_squence[i] = long_squence[j] + 1;
				if (long_squence[i] > *max)
					*max = long_squence[i];
			}
			j++;
		}
		i++;
	}
	return (long_squence);
}

t_vector	*find_longest_inc_sorted_sequence(t_vector stack)
{
	int			i;
	int			max;
	t_vector	*long_increasing_seq;
	int			*long_squence;

	long_squence = compute_lis_indexs_values(stack.items, stack.used, &max);
	long_increasing_seq = (t_vector *)malloc(sizeof(t_vector));
	ft_vector_init(long_increasing_seq, sizeof(int));
	i = stack.used - 1;
	while (i >= 0)
	{
		if (long_squence[i] == max)
		{
			if (long_increasing_seq->used == 0)
				long_increasing_seq->vector_add(long_increasing_seq,
					stack.vector_get(&stack, i));
			else
				long_increasing_seq->vector_insert(long_increasing_seq, 0,
					stack.vector_get(&stack, i));
			max--;
		}
		i--;
	}
	free(long_squence);
	return (long_increasing_seq);
}

void	ft_move_min_number_to_top(t_vector *stack)
{
	int	min_index;

	min_index = ft_find_min_index(stack);
	if (min_index > ((stack->used - 1) / 2))
	{
		while (min_index < stack->used)
		{
			ft_reverse_rotate(stack);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ft_rotate(stack);
			min_index--;
		}
	}
}

t_vector	*ft_long_inc_sequnce(t_vector *stack_a)
{
	t_vector	*long_inc_sequence;
	t_vector	tmp_stack;
	int			i;

	i = 0;
	ft_vector_init(&tmp_stack, sizeof(int));
	while (i < stack_a->used)
	{
		tmp_stack.vector_add(&tmp_stack, stack_a->vector_get(stack_a, i));
		i++;
	}
	ft_move_min_number_to_top(&tmp_stack);
	long_inc_sequence = find_longest_inc_sorted_sequence(tmp_stack);
	tmp_stack.vector_free(&tmp_stack);
	return (long_inc_sequence);
}
