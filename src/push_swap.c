/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:54:19 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/18 16:59:06 by zjamali          ###   ########.fr       */
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
		ft_reverse_rotate(&stack_b);
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
	stack_a.vector_free(&stack_a);
}