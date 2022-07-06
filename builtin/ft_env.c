/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->hashmap_size)
	{
		if (!(&data->hashmap[i]->next == &data->hashmap[i]
				&& &data->hashmap[i]->prev == &data->hashmap[i]))
			print_list(&data->hashmap[i]);
		i++;
	}
	return (0);
}
