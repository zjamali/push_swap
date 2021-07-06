/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:18:18 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/06 15:48:49 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

void	*ft_vector_get(t_vector *vector, int index)
{
	void	*read_data;

	read_data = NULL;
	if (vector)
	{
		if (index >= 0 && index < vector->used)
			read_data = vector->items + (vector->item_size * index);
	}
	return (read_data);
}

int	ft_vector_delete(t_vector *vector, int index)
{
	int	status;
	int	i;

	status = UNDEFINE;
	if (vector)
	{
		if (index >= 0 && index < vector->used)
		{
			i = index;
			while (i < vector->used - 1)
			{
				ft_memcpy(vector->vector_get(vector, i),
					vector->vector_get(vector, i + 1), vector->item_size);
				i++;
			}
			vector->used--;
		}
		if (vector->used < vector->size / 4)
		{
			vector->vector_resize(vector, vector->size / 2);
			vector->size = vector->size / 2;
		}
		status = SUCCESS;
	}
	return (status);
}

int	ft_free_vector(t_vector *vector)
{
	int	status;

	status = UNDEFINE;
	if (vector)
	{
		free(vector->items);
		vector->items = NULL;
		status = SUCCESS;
	}
	return (status);
}

int	ft_vector_used(t_vector *vector)
{
	int	total_count;

	total_count = UNDEFINE;
	if (vector)
	{
		total_count = vector->used;
	}
	return (total_count);
}

void	ft_vector_init(t_vector *vec, int type)
{
	vec->vector_add = vector_push_back;
	vec->vector_delete = ft_vector_delete;
	vec->vector_free = ft_free_vector;
	vec->vector_get = ft_vector_get;
	vec->vector_resize = ft_vector_resize;
	vec->vector_set = ft_vector_set;
	vec->vector_used = ft_vector_used;
	vec->vector_insert = ft_vector_insert;
	vec->size = VECTOR_INIT_CAPACITY;
	vec->used = 0;
	vec->item_size = type;
	vec->items = malloc(vec->item_size * vec->size);
}
