/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:28:50 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/23 13:57:19 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector_lib/vectors.h"
# include "libft/libft.h"
# include <limits.h>

# include <stdio.h>

int		ft_check_data(char **data);
void	push_swap(char **data);
void	ft_swap(t_vector *stack);
void	ft_push(t_vector *stack_from, t_vector *stack_to);
void	ft_rotate(t_vector *stack);
void	ft_rotate(t_vector *stack);
void	ft_reverse_rotate(t_vector *stack);
void	ft_swap_both_stacks(t_vector *stack_a, t_vector *stack_b);
void	ft_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b);
void	ft_reverse_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b);
#endif