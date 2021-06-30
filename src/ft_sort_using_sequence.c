/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_using_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:09:16 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/30 21:28:10 by zjamali          ###   ########.fr       */
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
	//printf("\n\n");
	//for (int i = 0; i < stack->used; i++)
	//{
	//	printf("%d ",long_squence[i]);
	//}
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

	last_index = stack->used - 1;
	items = stack->items;
	printf("\nitems\n");
	for (int i = 0; i <= last_index; i++)
	{
		printf("items[%d]= %d\n",i ,items[last_index - i]);
	}
	printf("\n");
	i = 0;
	while (i < stack->used)
	{
		if (number > items[i] && number < items[last_index - i])
		{
			printf("%d < %d < %d\n",items[i],number,items[last_index - i]);
			return (i);
		}
		if (number > items[i] && number < items[i + 1])
		{
			printf("%d < %d < %d\n",items[i],number,items[i + 1]);
			return (i);
		}
		if (number > items[last_index - i]
			&& number < items[last_index - i - 1])
		{
			printf("%d < %d < %d\n",items[last_index - i],number,items[last_index - i - 1]);
			return (last_index - i);
		}
		i++;
	}
	//// need to max index position
	max_val_position = ft_find_max_index(stack) + 1;
	printf()
	if (max_val_position == stack->used)
		max_val_position = 0;
	printf(" %d out of stack a\n",number);
	return (last_index);
}

int	find_best(t_vector *stack_a, t_vector *stack_b)
{
	int			i;
	t_vector	find_best;
	int			index_in_a;
	int			op_count;
	int			min_ops_index;

	ft_vector_init(&find_best ,sizeof(int));
	i = 0;
	while (i < stack_b->used)
	{
		index_in_a = find_place(stack_a, *(int*)stack_b->vector_get(stack_b ,i));
		op_count = ft_count_op(stack_a, stack_b, index_in_a, i);
		find_best.vector_add(&find_best, &op_count);
		i++;
	}
	printf("find best: \n");
	for (int i = 0; i < find_best.used ; i++)
	{
		printf("[%d] = %d \n",i , *(int *)find_best.vector_get(&find_best,i));
	}
	printf("\n");
	min_ops_index = ft_find_min_index(&find_best);
	printf("the best is : %d\n", min_ops_index);
	find_best.vector_free(&find_best);
	return (min_ops_index);
}

void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b)
{
	t_vector	tmp_stack;
	t_vector	*long_inc_sequence;
	int			i;
	int			best_index;

	ft_vector_init(&tmp_stack, sizeof(int));
	i = 0;
	while (i < stack_a->used)
	{
		tmp_stack.vector_add(&tmp_stack, stack_a->vector_get(stack_a, i));
		i++;
	}
	ft_move_min_number_to_top(&tmp_stack);
	long_inc_sequence = find_longest_inc_sorted_sequence(tmp_stack);
	ft_push_to_b(stack_a, stack_b, long_inc_sequence);
	best_index = find_best(stack_a, stack_b);
	printf("the BEST ITEM in B to MOVE to A= %d\n",*(int *)stack_b->vector_get(stack_b, best_index));
	
//	int operatio = ft_count_op(index_in_a, 0);
	//printf("place of %d  stack a : %d\n",top_b, index_in_a);	
}

///  7  6  5  2  4  3  1
///  7  6  5  2  4  3  10

/// 6 10 8 5 3 9 0 1 7 2 4
