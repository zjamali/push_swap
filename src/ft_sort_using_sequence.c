/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_using_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:09:16 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/04 18:49:59 by zjamali          ###   ########.fr       */
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

int	find_place(t_vector *stack, int number)
{
	int	i;
	int	*items;
	int	last_index;
	int	max_val_position;
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
	max_val_position = ft_find_max_index(stack);
	if (items[max_val_position] < number)
	{
		if (max_val_position + 1 > last_index)
			return (0);
		else
			return (max_val_position + 1);
	}
	int min_index = ft_find_min_index(stack);
	int	max_index = ft_find_max_index(stack);
	if (number > items[min_index] && number > items[max_index])
	{
		if (min_index == 0)
			return (0);
		return (min_index - 1);
	}
	if (items[0] > number && number > items[last_index])
		return (0);
	return (last_index);
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

int	count_moves_in_stack_b(t_vector *stack, int best_index)
{
	int	ops;
	int	sign;

	if (best_index == stack->used)
		return (0);
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

void	ft_align_both_stacks(t_vector *stack_a, t_vector *stack_b,
			int move_a, int move_b)
{
	if ((move_a * move_b) > 0)
	{
		if (move_a > 0)
		{
			while (move_a > 0 && move_b > 0)
			{
				ft_putstr_fd("rr\n",1);
				ft_rotate_both_stacks(stack_a, stack_b);
				move_a--;
				move_b--;
			}
			while (move_a > 0)
			{
				ft_putstr_fd("ra\n",1);
				ft_rotate(stack_a);
				move_a--;
			}
			while (move_b > 0)
			{
				ft_putstr_fd("rb\n",1);
				ft_rotate(stack_b);
				move_b--;
			}
		}
		else
		{
			while (move_a < 0 && move_b < 0)
			{
				ft_putstr_fd("rrr\n", 1);
				ft_reverse_rotate_both_stacks(stack_a, stack_b);
				move_a = move_a + 1;
				move_b = move_b + 1;
			}
			while (move_a < 0)
			{
				ft_putstr_fd("rra\n",1);
				ft_reverse_rotate(stack_a);
				move_a = move_a + 1;
			}
			while (move_b < 0)
			{
				ft_putstr_fd("rrb\n",1);
				ft_reverse_rotate(stack_b);
				move_b = move_b + 1;
			}
		}
	}
	else
	{
		while (move_a < 0)
		{
			ft_putstr_fd("rra\n",1);
			ft_reverse_rotate(stack_a);
			move_a = move_a + 1;
		}
		while (move_b < 0)
		{
			ft_putstr_fd("rrb\n",1);
			ft_reverse_rotate(stack_b);
			move_b = move_b + 1;
		}
		while (move_a > 0)
		{
			ft_putstr_fd("ra\n",1);
			ft_rotate(stack_a);
			move_a--;
		}
		while (move_b > 0)
		{
			ft_putstr_fd("rb\n",1);
			ft_rotate(stack_b);
			move_b--;
		}
	}
}

void	ft_sort_stack_a(t_vector *stack_a)
{
	int	min_index;

	min_index = ft_find_min_index(stack_a);
	if (min_index == 0)
		return ;
	if (min_index > (stack_a->used / 2))
	{
		while (min_index < stack_a->used)
		{
			ft_putstr_fd("rra\n", 1);
			ft_reverse_rotate(stack_a);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ft_putstr_fd("ra\n", 1);
			ft_rotate(stack_a);
			min_index--;
		}
	}
}

void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	tmp_stack;
	t_vector	*long_inc_sequence;
	int			i;
	int			best_index;
	int			count_moves_a;
	int			count_moves_b;

	ft_vector_init(&tmp_stack, sizeof(int));
	i = 0;
	while (i < stack_a->used)
	{
		tmp_stack.vector_add(&tmp_stack, stack_a->vector_get(stack_a, i));
		i++;
	}
	ft_move_min_number_to_top(&tmp_stack);
	long_inc_sequence = find_longest_inc_sorted_sequence(tmp_stack);
	tmp_stack.vector_free(&tmp_stack);
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
