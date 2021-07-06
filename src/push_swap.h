/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:28:50 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 16:46:22 by zjamali          ###   ########.fr       */
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
void	ft_check_max_and_min(char *data);
void	ft_check_duplicated(char **data);
void	ft_display_error_and_exit(void);
void	push_swap(char **data);
void	ft_swap(t_vector *stack);
void	ft_push(t_vector *stack_from, t_vector *stack_to);
void	ft_rotate(t_vector *stack);
void	ft_rotate(t_vector *stack);
void	ft_reverse_rotate(t_vector *stack);
void	ft_swap_both_stacks(t_vector *stack_a, t_vector *stack_b);
void	ft_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b);
void	ft_reverse_rotate_both_stacks(t_vector *stack_a, t_vector *stack_b);
double	finding_the_median(t_vector *stack);
void	ft_sort_five_numbers(t_vector *stack_a, t_vector *stack_b);
void	ft_sort_two_numbers(t_vector *stack);
void	ft_sort_three_numbers(t_vector *stack);
int		ft_push_median_lowests(t_vector *stack_a, t_vector *stack_b,
			double median);
void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b);
void	ft_sort_using_sequence(t_vector *stack_a, t_vector *stack_b);
int		ft_find_min_index(t_vector *stack);
int		ft_find_max_index(t_vector *stack);
void	ft_get_max_and_min(int *items, int len, int *min, int *max);
#endif