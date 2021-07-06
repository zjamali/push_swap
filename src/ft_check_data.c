/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:26:53 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 16:27:24 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_errors(char *data)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (data[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	if (data[0] == '+')
		i = 1;
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
			ft_display_error_and_exit();
		i++;
	}
	ft_check_max_and_min(data);
	return (0);
}

int	ft_check_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		ft_check_errors(data[i]);
		i++;
	}
	ft_check_duplicated(data);
	return (1);
}
