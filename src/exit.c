/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 03:18:33 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/11 03:18:35 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void ft_exit(char **argv)
{
	ft_putstr_fd("exit ", STDERR_FILENO);
	if (ft_strlen(*argv) > 1 && ft_strisnum(argv[1]))
	{
		ft_putstr_fd("shell: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required", STDERR_FILENO);
		exit(255);
	}
	else if (ft_strlen(*argv) > 2 && !ft_strisnum(argv[1]))
	{
		ft_putstr_fd("shell: exit: too many arguments", STDERR_FILENO);
	}
	else if (ft_strlen(*argv) == 2 && ft_strisnum(argv[1]) != 0)
		exit(ft_atoi(argv[1]));
	else(EXIT_SUCCESS);
}