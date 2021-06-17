/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:01:07 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/17 14:10:41 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include <stdlib.h>

# define VECTOR_INIT_CAPACITY 4
# define UNDEFINE  -1
# define SUCCESS 0

typedef struct s_vector	t_vector;

struct s_vector {
	void	*items;
	int		size;
	int		used;
	int		item_size;
	int		(*vector_used)(t_vector *);
	int		(*vector_resize)(t_vector *, int);
	int		(*vector_add)(t_vector *, void *);
	int		(*vector_set)(t_vector *, int, void *);
	void	*(*vector_get)(t_vector *, int);
	int		(*vector_delete)(t_vector *, int);
	int		(*vector_free)(t_vector *);
	int		(*vector_insert)(t_vector *, int, void *);
};

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_vector_init(t_vector *vec, int type);
int			ft_vector_resize(t_vector *vector, int new_capacity);
int			vector_push_back(t_vector *vector, void *item);
int			ft_vector_insert(t_vector *vector, int index, void *item);
int			ft_vector_set(t_vector *vector, int index, void *item);
void		*ft_vector_get(t_vector *vector, int index);
int			ft_vector_delete(t_vector *vector, int index);
int			ft_free_vector(t_vector *vector);
int			ft_vector_used(t_vector *vector);
#endif