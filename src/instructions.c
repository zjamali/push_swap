/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:02:58 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/18 18:30:52 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
*	ft_swap : swap TOP  two numbers in stack giving 
*/
void	ft_swap(t_vector *stack)
{
	int	tmp;

	if (stack->used > 1)
	{
		tmp = *(int *)stack->vector_get(stack, 0);
		stack->vector_set(stack, 0, stack->vector_get(stack, 1));
		stack->vector_set(stack, 1, &tmp);
	}
}

/*
*	ft_push : push TOP number of stack_from to stack_to 
*/
void	ft_push(t_vector *stack_from, t_vector *stack_to)
{
	if (stack_from->used > 1)
	{
		stack_to->vector_insert(stack_to, 0,
			stack_from->vector_get(stack_from, 0));
		stack_from->vector_delete(stack_from, 0);
	}
}

/*
*	ft_rotate : shift up all elements of stack by 1
*/
void	ft_rotate(t_vector *stack)
{
	int	tmp;

	if (stack->used > 1)
	{
		tmp = *(int *)stack->vector_get(stack, 0);
		stack->vector_delete(stack, 0);
		stack->vector_add(stack, &tmp);
	}
}


/*
*	ft_reverse_rotate : shift down all elements of stack by 1
*/
void	ft_reverse_rotate(t_vector *stack)
{
	int	tmp;

	if (stack->used > 1)
	{
		tmp = *(int *)stack->vector_get(stack, stack->used - 1);
		stack->vector_delete(stack, stack->used - 1);
		stack->vector_insert(stack, 0, &tmp);
	}
}