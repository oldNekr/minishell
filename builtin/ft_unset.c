/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(t_data *data, char *str)
{
	if (!is_letter(str))
	{
		perror("Ошибка в значении ключа!\n");
		return (1);
	}
	del_from_hashmap(data, str);
	if (get_value(data, "SHLVL") == NULL)
		ft_export(data, "SHLVL=0");
	return (0);
}
