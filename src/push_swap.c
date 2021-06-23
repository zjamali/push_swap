/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:54:19 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/23 14:02:35 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_data_stack(t_vector *stack, char **data)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (data[i])
	{
		number = ft_atoi(data[i]);
		stack->vector_add(stack,&number);
		i++;
		number = 0;
	}
}

int	ft_check_data_is_sorted(t_vector stack)
{
	int	i;
	int	big_number;

	i = 0;
	big_number = 0;
	while (i < stack.used)
	{
		if (big_number > *(int *)stack.vector_get(&stack, i))
			return (1);
		big_number = *(int *)stack.vector_get(&stack, i);
		i++;
	}
	return (0);
}

void	ft_get_max_and_min(int *items, int len, int *min, int *max)
{
	int	i;

	i = 0;
	*max = INT_MIN;
	*min = INT_MAX;
	while (i < len)
	{
		if (*(items + i) < *min)
			*min = *(items + i);
		if (*(items + i) >  *max)
			*max = *(items + i);
		i++;
	}
}

void	finding_the_median(t_vector *stack)
{
	int	min;
	int	max;
	static int	begin_end[2];

	min = INT_MAX;
	max = INT_MIN;
	begin_end[0] = 0;
	begin_end[1] = stack->used - 1;
	ft_get_max_and_min(stack->items,stack->used, &min, &max);
	printf("min = %d \t max = %d\n", min, max);
}

void	push_swap(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;

	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	ft_push_to_data_stack(&stack_b, data);
	if (ft_check_data_is_sorted(stack_a))
	{
		for (int i = 0; i < stack_a.used; i++)
		{
			printf("a[%d] = %d\n", i, *(int *)stack_a.vector_get(&stack_a,i));
		}
		printf("\n");
		for (int i = 0; i < stack_b.used; i++)
		{
			printf("b[%d] = %d\n", i, *(int *)stack_a.vector_get(&stack_b,i));
		}
		printf("\n\n\n");
		ft_rotate_both_stacks(&stack_a, &stack_b);
		for (int i = 0; i < stack_a.used; i++)
		{
			printf("a[%d] = %d\n", i, *(int *)stack_a.vector_get(&stack_a,i));
		}
		printf("\n");
		for (int i = 0; i < stack_b.used; i++)
		{
			printf("b[%d] = %d\n", i, *(int *)stack_a.vector_get(&stack_b,i));
		}
	}
	finding_the_median(&stack_a);
	stack_a.vector_free(&stack_a);
}