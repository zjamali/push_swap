/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:28:50 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/17 18:45:16 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector_lib/vectors.h"
# include "libft/libft.h"
# include <limits.h>






#include <stdio.h>

typedef struct s_stacks
{
	t_vector	a;
	t_vector	b;
}				t_stack;

int	ft_check_data(char **data);
#endif