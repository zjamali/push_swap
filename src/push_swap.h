/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:28:50 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/04 18:54:30 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector_lib/vectors.h"
# include "libft/libft.h"
# include <limits.h>

# include <stdio.h>

typedef struct s_median
{
	int		max;
	int		min;
	float	median;
	int		*items;
	int		array_leng;
}				t_medain;

typedef struct s_is_sorted
{
	int	i;
	int	items_compared;
	int	is_sorted;
	int	prev_num;
	int	curr_num;
}				t_is_sorted;

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
double	get_the_median(int *items, int array_length, int min, int max);
double	finding_the_median(t_vector *stack);
int		ft_check_stack_circular_sorted(t_vector *stack);
void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b);
void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b);
int		ft_find_min_index(t_vector *stack);
int		ft_find_max_index(t_vector *stack);
void	ft_get_max_and_min(int *items, int len, int *min, int *max);
#endif