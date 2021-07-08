/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:08:16 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/08 17:41:09 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

static long int	ft_str_to_number(char *str)
{
	long int	number;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	number = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

void	ft_check_max_and_min(char *data)
{
	long int	number;

	number = 0;
	number = ft_str_to_number(data);
	if (number < INT_MIN || number > INT_MAX)
		ft_display_error_and_exit();
}

size_t	ft_lenght(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= len2)
		return (len1);
	else
		return (len2);
}

void	ft_check_duplicated(char **data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data[i])
	{
		j = 0;
		while (data[j])
		{
			if (i != j && (ft_atoi(data[i]) == ft_atoi(data[j])))
			{
				ft_display_error_and_exit();
			}
			j++;
		}
		i++;
	}
}
