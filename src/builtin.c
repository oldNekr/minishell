/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:12:04 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/17 09:12:05 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int builtins(char **argv)
{
	int result;

	result = 0;
	if (ft_strcmp(argv[0], "cd") == 0)
		result = 1;
	if (ft_strcmp(argv[0], "echo") == 0)
		result = 2;
	if (ft_strcmp(argv[0], "env") == 0)
		result = 3;
	if (ft_strcmp(argv[0], "exit") == 0)
		result = 4;
	if (ft_strcmp(argv[0], "export") == 0)
		result = 5;
	if (ft_strcmp(argv[0], "pwd") == 0)
		result = 6;
	if (ft_strcmp(argv[0], "uset") == 0)
		result = 7;
	return (result);
}
