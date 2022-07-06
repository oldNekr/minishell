/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Делит строку str на две: слева и справа от 'token'.
 * Возвращает массив из двух строк и NULL.
 */

char	**ft_split2(char *str, char token)
{
	int		i;
	char	**arr;

	arr = malloc(sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != token)
		i++;
	arr[0] = ft_substr(&str[0], 0, i);
	if (arr[0] == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr[1] = ft_substr(&str[0], i + 1, ft_strlen(&str[i + 1]));
	if (arr[1] == NULL)
	{
		free(arr[0]);
		free(arr);
		return (NULL);
	}
	arr[2] = NULL;
	return (arr);
}
