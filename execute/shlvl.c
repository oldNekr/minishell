/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_lvl(t_data *data)
{
	int		prev;
	char	*str1;
	char	*str2;
	char	*shlvl;

	shlvl = get_value(data, "SHLVL");
	if (shlvl == NULL)
		ft_export(data, "SHLVL=0");
	else
	{
		prev = ft_atoi(shlvl);
		if (prev < 0 || prev >= 999)
			ft_export(data, "SHLVL=0");
		else
		{
			str1 = ft_itoa(prev + 1);
			str2 = ft_strjoin("SHLVL=", str1);
			ft_export(data, str2);
			free(str1);
			free(str2);
		}
	}
}
