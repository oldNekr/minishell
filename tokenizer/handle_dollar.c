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

int	ft_eq(char c)
{
	return (c == '=');
}

static char	*get_add(t_data *data, char **line)
{
	char	*tmp;
	char	*to_add;

	*line = *line + 1;
	if (**line == '?')
	{
		*line = *line + 1;
		return (ft_itoa(data->exit_code));
	}
	else
	{
		tmp = ft_strdup("");
		while (**line && **line != '\'' && **line != '\"' && **line != '$'
			&& !is_special_char(*line) && !ft_isspace(**line) && !ft_eq(**line))
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
}

/*
 * Собирает посимвольно строку.
 * Если встречается $ происходит расширение строки и замена
 * переменных среды.
 */

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
		if (*str == '$' && *(str + 1) && !single_quote && \
			!ft_isspace(*(str + 1)) && *(str + 1) != '\'' && *(str + 1) != '\"')
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
