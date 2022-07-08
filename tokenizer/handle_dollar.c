/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Ищет на что заменить доллар и возвращает строку с этим значением
 */

int	is_eq(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*get_add2(t_data *data, char **line)
{
	char	*tmp;
	char	*to_add;

	tmp = ft_strdup("");
	while (**line && **line != '\'' && **line != '\"' && **line != '$'
		&& !is_special_char(*line) && is_eq(**line) && **line != '\\')
	{
		add_char(&tmp, **line);
		*line = *line + 1;
	}
	to_add = ft_strdup(get_value(data, tmp));
	if (!to_add)
		to_add = ft_strdup("");
	free(tmp);
	return (to_add);
}

static char	*get_add(t_data *data, char **line)
{
	*line = *line + 1;
	if (**line == '?')
	{
		*line = *line + 1;
		return (ft_itoa(data->exit_code));
	}
	else if (!ft_isdigit(**line))
		return (get_add2(data, line));
	else
	{
		*line = *line + 1;
		return (ft_strdup(""));
	}
}

/*
 * Собирает посимвольно строку.
 * Если встречается $ происходит расширение строки и замена
 * переменных среды.
 */

int	handle_check(char *str, int single_quote)
{
	if (*str == '$' && *(str + 1) && !single_quote && (ft_isalnum(*(str + 1))
			|| *(str + 1) == '_') && !ft_isspace(*(str + 1))
		&& *(str + 1) != '\'' && *(str + 1) != '\"')
		return (1);
	return (0);
}

char	*handle_dollar(t_data *data, char *str)
{
	int		single_quote;
	int		double_quote;
	char	*new_line;
	char	*to_add;
	char	*result;

	new_line = ft_strdup("");
	single_quote = 0;
	double_quote = 0;
	while (*str)
	{
		quote_pick(*str, &single_quote, &double_quote);
		if (handle_check(str, single_quote))
		{
			to_add = get_add(data, &str);
			result = ft_strjoin(new_line, to_add);
			free(new_line);
			free(to_add);
			new_line = result;
		}
		else
			add_char(&new_line, *str++);
	}
	return (new_line);
}
