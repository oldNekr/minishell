/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Простая хэш-функция, которая возвращает сумму аски кодов строки
 * делённую по модулю на размер хэш-таблцы.
 */

static int	get_hash(char *str)
{
	int	hash;

	hash = 0;
	while (*str)
		hash += *str++;
	return (hash);
}

/*
 * Создаёт новый элемент с полями key и value и
 * добавляет во вспомогательный список хэш-таблицы
 */

int	add_to_hashmap(t_data *data, char *key, char *value)
{
	int	hash_code;

	hash_code = get_hash(key) % data->hashmap_size;
	if (_ft_lstadd_back(&data->hashmap[hash_code], key, value) == F_ALLOC)
		return (F_ALLOC);
	return (1);
}

/*
 * Удаляет элемент из хэш-таблицы по переданному ключу
 */

int	del_from_hashmap(t_data *data, char *key)
{
	int	hash_code;

	hash_code = get_hash(key) % data->hashmap_size;
	if (_ft_lstdel(&data->hashmap[hash_code], key) == 0)
		return (0);
	return (1);
}

/*
 * Возвращает значение по ключу в строковом виде.
 */

char	*get_value(t_data *data, char *key)
{
	t_hashmap	*current;
	int			hash_code;

	hash_code = get_hash(key) % data->hashmap_size;
	current = (data->hashmap[hash_code])->next;
	while (current != data->hashmap[hash_code])
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/*
 * Возвращает указатель на запись с ключом "key"
 */

t_hashmap	*get_record(t_data *data, char *key)
{
	t_hashmap	*current;
	int			hash_code;

	hash_code = get_hash(key) % data->hashmap_size;
	current = (data->hashmap[hash_code])->next;
	while (current != data->hashmap[hash_code])
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
