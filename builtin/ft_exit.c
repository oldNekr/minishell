/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_exit(t_data *data, char **args)
{
	int	ret;

	ret = 0;
	if (args[1] && is_number(args[1]) && !(args[2]))
		ret = ft_atoi(args[1]);
	else if ((args[1] && !is_number(args[1])) || args[2])
	{
		ret = 2;
		write(1, "Error in parameters\n", 21);
		exit(ret);
	}
	ft_putstr_fd("exit\n", 1);
	token_lstclear(&(data->head));
	cmd_lstclear(&(data->cmds));
	free_hashmap(data);
	exit(ret);
}
