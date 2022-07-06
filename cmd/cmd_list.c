/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Иницализирует заголовок списка команд
 */

int	cmd_lstinit(t_cmd **cmd_list)
{
	*cmd_list = malloc(sizeof(t_cmd));
	if (cmd_list == NULL)
		return (F_ALLOC);
	(*cmd_list)->args = NULL;
	(*cmd_list)->infile = -42;
	(*cmd_list)->outfile = -42;
	(*cmd_list)->to_skip = -42;
	(*cmd_list)->prev = *cmd_list;
	(*cmd_list)->next = *cmd_list;
	return (1);
}

/*
 * Добавляет команду в конец списка команд
 */

int	cmd_lstadd_back(t_cmd **cmd_list, t_cmd *cmd)
{
	cmd->prev = (*cmd_list)->prev;
	cmd->next = *cmd_list;
	(*cmd_list)->prev->next = cmd;
	(*cmd_list)->prev = cmd;
	return (1);
}

/*
 * Создаёт пустую команду без указателей на предыдущий
 * и следующий элемент
 */

t_cmd	*cmd_create_elem(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->args = NULL;
	cmd->infile = -2;
	cmd->outfile = -2;
	cmd->to_skip = 0;
	return (cmd);
}

/*
 * Очищает список команд.
 */

void	cmd_lstclear(t_cmd **lst)
{
	int		i;
	t_cmd	*tmp;
	t_cmd	*next;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		i = -1;
		while (tmp->args[++i])
			free(tmp->args[i]);
		if (tmp->infile >= 0)
			close(tmp->infile);
		if (tmp->outfile >= 0)
			close(tmp->outfile);
		free(tmp->args);
		next = next->next;
		free(tmp);
	}
	free(*lst);
}
