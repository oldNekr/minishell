/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Создаёт новый массив строк с элементами arr и строкой str
 * и возвращает его.
 */

char	**add_str(char **arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	len = 0;
	if (arr)
		while (arr[len])
			len++;
	new_arr = malloc(sizeof(char *) * (len + 2));
	if (!new_arr)
		return (NULL);
	new_arr[len + 1] = NULL;
	new_arr[len] = str;
	i = 0;
	while (arr && arr[i] != NULL)
	{
		new_arr[i] = arr[i];
		i++;
	}
	free(arr);
	return (new_arr);
}
