/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 03:18:14 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/11 03:18:15 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_echo(char **argv)
{
	int it;

	it = 0;
	if(!ft_strcmp(argv[1], "-n"))
		it++;
	while (argv[++it])
	{
		ft_putstr_fd(argv[it], STDOUT_FILENO);
		if (argv[it + 1] && argv[it][0] != '\0')
			write(STDOUT_FILENO, " ", 1);
	}
	if (!ft_strcmp(argv[1], "-n"))
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}