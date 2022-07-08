/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Проверяет на соответствие одиночные и двойные кавычки
 */

int	check_quotes(char *b)
{
	int		i;
	char	c;

	i = 0;
	while (b[i])
	{
		if (b[i] == '\\' && (b[i + 1] == '\"' || b[i + 1] == '\''))
			i = i + 2;
		else
		{
			if (b[i] == '\'' || b[i] == '\"')
			{
				c = b[i];
				i++;
				while (b[i] && b[i] != c)
					if (b[i] == '\\' && (b[i + 1] == '\"' || b[i + 1] == '\''))
						i = i + 2;
				else
						i++;
			}
			if (b[i++] == '\0')
				return (0);
		}
	}
	return (1);
}

/*
 * Проверяет, являет ли токен оператором или аргументом, командой
 */

int	is_operator(t_token *t)
{
	int	type;

	type = t->type;
	if (type == INPUT || type == HEREDOC
		|| type == TRUNC || type == APPEND
		|| type == PIPE)
		return (1);
	return (0);
}

/*
 * Проверяет отдельно стоящие спец. символы и логические ошибки
 */

int	validate(t_data *data)
{
	t_token	*tmp;

	tmp = data->head->next;
	if (is_operator(tmp))
		return (printf("Оператор не должен стоять на первом месте!\n"));
	if (is_operator(data->head->prev))
		return (printf("Оператор не должен стоять на последнем месте!\n"));
	while (tmp != data->head)
	{
		if (tmp->prev != data->head && tmp->prev)
		{
			if (is_operator(tmp) && is_operator(tmp->prev))
			{
				printf("Операторы не должны стоять рядом!\n");
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
