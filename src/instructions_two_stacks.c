/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:30:03 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/18 18:31:43 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both_stacks(t_vector *stack_a, t_vector *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}