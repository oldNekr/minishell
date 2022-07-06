/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmaplist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Выводит на экран вспомогательный список.
 */

void	print_list(t_hashmap **hashmap)
{
	t_hashmap	*tmp;

	tmp = (*hashmap)->next;
	while (tmp != (*hashmap))
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

/*
 * Добавляет элемент в конец вспомогательного списка.
 */

int	_ft_lstadd_back(t_hashmap **hashmap, char *key, char *value)
{
	t_hashmap	*new;

	new = malloc(sizeof(t_hashmap));
	if (new == NULL)
		return (F_ALLOC);
	new->key = key;
	new->value = value;
	new->prev = (*hashmap)->prev;
	new->next = *hashmap;
	(*hashmap)->prev->next = new;
	(*hashmap)->prev = new;
	return (1);
}

/*
 * Удаляет элемент из вспомогательного списка.
 */

int	_ft_lstdel(t_hashmap **hashmap, char *key)
{
	t_hashmap	*tmp;

	tmp = (*hashmap)->next;
	while (tmp != (*hashmap))
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
 * Инициализирует заголовок вспомогательного списка.
 * head->next = head;
 * head->prev = head;
 */

int	_ft_lstinit(t_hashmap **hashmap)
{
	*hashmap = malloc(sizeof(t_hashmap));
	if (hashmap == NULL)
		return (F_ALLOC);
	(*hashmap)->key = NULL;
	(*hashmap)->value = NULL;
	(*hashmap)->prev = *hashmap;
	(*hashmap)->next = *hashmap;
	return (1);
}

/*
 * Удаляет вспомогательный список с освобождением выделенной памяти.
 */

void	_ft_lstclear(t_hashmap **lst)
{
	t_hashmap	*tmp;
	t_hashmap	*next;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		free(tmp->key);
		free(tmp->value);
		next = next->next;
		free(tmp);
	}
	free(*lst);
}
