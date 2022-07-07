/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	if (!args)
		return (0);
	if (args[0] && ft_strcmp(args[0], "-n") == 0)
		nl = ++i;
	while (args[i])
	{
		write(1, args[i], ft_strlen(args[i]));
		i++;
	}
	if (!nl)
		printf("\n");
	return (0);
}
