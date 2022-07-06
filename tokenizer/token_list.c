/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Создаёт токен и добавляет в конец списка
 */

int	token_lstadd_back(t_token **token_list, char *str, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_hashmap));
	if (new == NULL)
		return (F_ALLOC);
	new->str = str;
	new->type = type;
	new->prev = (*token_list)->prev;
	new->next = *token_list;
	(*token_list)->prev->next = new;
	(*token_list)->prev = new;
	return (1);
}

/*
 * Инициализирует заголовок списка
 * head->next = head;
 * head->prev = head;
 */

int	token_lstinit(t_token **token_list)
{
	*token_list = malloc(sizeof(t_hashmap));
	if (token_list == NULL)
		return (F_ALLOC);
	(*token_list)->str = NULL;
	(*token_list)->type = -42;
	(*token_list)->prev = *token_list;
	(*token_list)->next = *token_list;
	return (1);
}

/*
 * Очищает список.
 */

void	token_lstclear(t_token **lst)
{
	t_token	*tmp;
	t_token	*next;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		free(tmp->str);
		next = next->next;
		free(tmp);
	}
	free(*lst);
}
