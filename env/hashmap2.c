/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Инициализирует главный массив и вспомогательные списки
 * хэш-таблицы размером size
 */

int	init_hashmap(t_data *data, int size)
{
	int			i;
	t_hashmap	**hashmap;

	data->hashmap_size = size;
	hashmap = malloc(sizeof(t_hashmap *) * data->hashmap_size);
	if (!hashmap)
		return (F_ALLOC);
	i = 0;
	while (i < (data->hashmap_size))
	{
		if (_ft_lstinit(&hashmap[i]) == F_ALLOC)
			return (F_ALLOC);
		i++;
	}
	data->hashmap = hashmap;
	return (1);
}

/*
 * Удаляет хэш-таблицу и освобождает выделенную память.
 */

void	free_hashmap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->hashmap_size)
	{
		_ft_lstclear(&data->hashmap[i]);
		i++;
	}
	free(data->hashmap);
}

/*
 * Создаёт массив строк "ключ=значение" на основе хэш-таблицы
 * и возвращает его.
 */

char	**hashmap_to_array(t_data *data)
{
	int			i;
	char		**arr;
	char		*str;
	char		*t;
	t_hashmap	*tmp;

	i = -1;
	arr = NULL;
	while (++i < data->hashmap_size)
	{
		if (!(&data->hashmap[i]->next == &data->hashmap[i]
				&& &data->hashmap[i]->prev == &data->hashmap[i]))
		{
			tmp = data->hashmap[i]->next;
			while (tmp != data->hashmap[i])
			{
				t = ft_strjoin(tmp->key, "=");
				str = ft_strjoin(t, tmp->value);
				free(t);
				arr = add_str(arr, str);
				tmp = tmp->next;
			}
		}
	}
	return (arr);
}
