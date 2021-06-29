/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_using_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:09:16 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/29 21:46:00 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_sequence(t_vector *stack, int *max)
{
	int	*items;
	int	*long_squence;
	int	i;
	int	j;

	i = 0;
	items = stack->items;
	long_squence = (int *)malloc(sizeof(int) * stack->used);
	while (i < stack->used)
		long_squence[i++] = 1;
	i = 1;
	while (i < stack->used)
	{
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
	printf("\n\n");
	for (int i = 0; i < stack->used; i++)
	{
		printf("%d ",long_squence[i]);
	}
	return (long_squence);
}

t_vector	*find_longest_sorted_sequence(t_vector stack)
{
	int			i;
	int			max;
	t_vector	*long_increasing_seq;
	int			*long_squence;

	max = 0;
	long_squence = find_sequence(&stack, &max);
	long_increasing_seq = (t_vector *)malloc(sizeof(t_vector));
	ft_vector_init(long_increasing_seq, sizeof(int));
	i = stack.used;
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
	return (long_increasing_seq);
}

void	ft_move_min_number_to_top(t_vector *stack)
{
	int	min_index;

	min_index = ft_get_min_index(stack);
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

void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	tmp_stack;
	t_vector	*long_sequence;
	int			i;

	(void)stack_b;
	ft_vector_init(&tmp_stack, sizeof(int));
	i = 0;
	while (i < stack_a->used)
	{
		tmp_stack.vector_add(&tmp_stack, stack_a->vector_get(stack_a, i));
		i++;
	}
	for (int i = 0; i < stack_a->used; i++)
	{
		printf("%d ",*(int *)stack_a->vector_get(stack_a, i));
	}
	ft_move_min_number_to_top(&tmp_stack);
	printf("\n\n");
	for (int i = 0; i < tmp_stack.used; i++)
	{
		printf("%d ",*(int *)tmp_stack.vector_get(&tmp_stack, i));
	}
	printf("\n\n");
	long_sequence = find_longest_sorted_sequence(tmp_stack);
	//for (int i = 0; i < tmp_stack.used; i++)
	//{
	//	printf("%d  ",long_sequence[i]);
	//}

	printf("\n\n");
	for (int i = 0; i < long_sequence->used; i++)
	{
		printf("%d  ",*(int *)long_sequence->vector_get(long_sequence,i));
	}
}