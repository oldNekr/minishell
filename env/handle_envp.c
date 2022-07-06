/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Подсчитывает и возвращает количество
 * записей в переданном массиве строк.
 */

int	envp_size(char	**envp)
{
	int	length;

	length = 0;
	while (envp[length])
		length++;
	return (length);
}

/*
 * Создаёт хэш-таблицу размером ('количество записей env' * 2)
 * и инициализирует её. Переносит значения из переданной env
 * в созданную нами хэш-таблицу.
 * В случае ошибки malloc'a возвращает F_ALLOC.
 */

int	handle_envp(t_data *data, char **env)
{
	int		i;
	char	**spl_str;

	if (init_hashmap(data, envp_size(env) * 2) == F_ALLOC)
		return (F_ALLOC);
	i = 0;
	while (i < data->hashmap_size / 2)
	{
		spl_str = ft_split2(env[i], '=');
		if (spl_str != NULL
			&& add_to_hashmap(data, spl_str[0], spl_str[1]) == F_ALLOC)
			return (F_ALLOC);
		free(spl_str);
		i++;
	}
	return (1);
}
