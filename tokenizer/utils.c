/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Динамически добавляет символ к строке.
 */

void	add_char(char **line, char c)
{
	int		len;
	char	*tmp;
	char	*result;

	if (*line == NULL)
		len = 0;
	else
		len = ft_strlen(*line);
	result = malloc(sizeof(char) * (len + 2));
	if (!result)
		return ;
	ft_memcpy(result, *line, len);
	result[len] = c;
	result[len + 1] = '\0';
	tmp = *line;
	(*line) = result;
	free(tmp);
}

/*
 * Проверяет, является ли вхождение спец. символом
 */

int	is_special_char(char *str)
{
	if (str && ft_strlen(str) >= 2)
	{
		if (ft_strncmp(str, "<<", 2) == 0)
			return (1);
		else if (ft_strncmp(str, ">>", 2) == 0)
			return (1);
	}
	if (str && ft_strlen(str) >= 1)
	{
		if (ft_strncmp(str, "<", 1) == 0)
			return (1);
		else if (ft_strncmp(str, ">", 1) == 0)
			return (1);
		else if (ft_strncmp(str, "|", 1) == 0)
			return (1);
	}
	return (0);
}

/*
 * Меняет переменные single_quote, double_quote, которые говорят о том,
 * что указатель сейчас находится / не находится в скобках.
 */

int	quote_pick(char c, int *single_quote, int *double_quote)
{
	if (c == '\'' && !(*single_quote) && !(*double_quote))
	{
		(*single_quote) = 1;
		return (1);
	}
	else if (c == '\"' && !(*single_quote) && !(*double_quote))
	{
		(*double_quote) = 1;
		return (1);
	}
	else if (c == '\'' && (*single_quote) && !(*double_quote))
	{
		(*single_quote) = 0;
		return (1);
	}
	else if (c == '\"' && (*double_quote) && !(*single_quote))
	{
		(*double_quote) = 0;
		return (1);
	}
	return (0);
}

/*
 * Считывает и возвращает спец. символ и сдвигает указатель line
 * на длину символа.
 */

char	*get_special_char(char **line)
{
	char	*special_char;

	special_char = NULL;
	if (ft_strncmp(*line, "<<", 2) == 0)
		special_char = ft_strdup("<<");
	else if (ft_strncmp(*line, ">>", 2) == 0)
		special_char = ft_strdup(">>");
	else if (ft_strncmp(*line, "<", 1) == 0)
		special_char = ft_strdup("<");
	else if (ft_strncmp(*line, ">", 1) == 0)
		special_char = ft_strdup(">");
	else if (ft_strncmp(*line, "|", 1) == 0)
		special_char = ft_strdup("|");
	*line = *line + ft_strlen(special_char);
	return (special_char);
}

/*
 * Устанавливает тип токена в зависимости от строки токена
 */

void	set_type(t_token *token)
{
	if (ft_strcmp(token->str, "<") == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->str, "<<") == 0)
		token->type = HEREDOC;
	else if (ft_strcmp(token->str, ">") == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->str, ">>") == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->str, "|") == 0)
		token->type = PIPE;
	else if (token->prev->type == -42 || token->prev->type == PIPE)
		token->type = CMD;
	else
		token->type = ARG;
}
