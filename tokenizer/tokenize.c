/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Считывает токен до спец. символа или спец. символ как токен
 */

char	*get_token_str(char **line)
{
	int		single_quote;
	int		double_quote;
	char	*token_str;

	single_quote = 0;
	double_quote = 0;
	token_str = NULL;
	while (**line)
	{
		if (quote_pick(**line, &single_quote, &double_quote))
			;
		else if (!double_quote && !single_quote
			&& (is_special_char(*line) || ft_isspace(**line)))
		{
			if (!ft_isspace(**line) && token_str == NULL)
				token_str = get_special_char(line);
			break ;
		}
		else
			add_char(&token_str, **line);
		*line = *line + 1;
	}
	return (token_str);
}

/*
 * Инициализирует лист токенов, в цикле проходит по всем токенам,
 * добавляет их в список и устанавливает их тип
 */

int	create_token_list(t_data *data, char *line)
{
	char	*token_str;

	token_lstinit(&(data->head));
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		if (!*line)
			break ;
		token_str = get_token_str(&line);
		if (token_str == NULL)
			token_str = ft_strdup("");
		if (!token_lstadd_back(&(data->head), token_str, 0))
			return (0);
		set_type(data->head->prev);
	}
	return (1);
}

/*
 * Превращает строку с список токенов. В случае ошибки очищает память.
 */

int	tokenize(t_data *data, char *line)
{
	char	*new_line;

	if (!check_quotes(line))
	{
		printf("Несовпадение скобок!\n");
		return (0);
	}
	new_line = handle_dollar(data, line);
	if (!create_token_list(data, new_line) || validate(data) != 1)
	{
		token_lstclear(&(data->head));
		free(new_line);
		return (0);
	}
	free(new_line);
	return (1);
}
