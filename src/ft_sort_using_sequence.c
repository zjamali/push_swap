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

int	*compute_lis_value(t_vector *stack, int *max)
{
	int	*items;
	int	*long_squence;
	int	i;
	int	j;

	i = 0;
	items = stack->items;
	long_squence = (int *)malloc(sizeof(int) * stack->used);
	long_squence[0] = 1;
	i = 1;
	while (i < stack->used)
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
	printf("\n\n");
	for (int i = 0; i < stack->used; i++)
	{
		printf("%d ",long_squence[i]);
	}
	return (long_squence);
}

t_vector	*find_longest_inc_sorted_sequence(t_vector stack)
{
	int			i;
	int			max;
	t_vector	*long_increasing_seq;
	int			*long_squence;

	max = 0;
	long_squence = compute_lis_value(&stack, &max);
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

int	ft_check_number_in_squence(int number, t_vector *longet_inc_sequence)
{
	int	i;
	int	*items;

	i = 0;
	items = longet_inc_sequence->items;
	while (i < longet_inc_sequence->used)
	{
		if (number == items[i])
			return 0;
		i++;
	}
	return 1;
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
		if (ft_check_number_in_squence(top,longet_inc_sequence))
		{
			ft_putstr_fd("sb\n", 1);
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

void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	tmp_stack;
	t_vector	*long_inc_sequence;
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
	long_inc_sequence = find_longest_inc_sorted_sequence(tmp_stack);
	printf("\n\n");
	for (int i = 0; i < long_inc_sequence->used; i++)
	{
		printf("%d  ",*(int *)long_inc_sequence->vector_get(long_inc_sequence,i));
	}
	ft_push_to_b(stack_a, stack_b, long_inc_sequence);
}