/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_nb_arg(char **params)
{
	int	count;

	count = 0;
	while (params[count])
		count++;
	return (count);
}

static void	update_oldpwd(t_data *data)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return ;
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	if (!oldpwd)
		return ;
	ft_export(data, oldpwd);
	free(oldpwd);
}

static void	update_currpwd(t_data *data)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return ;
	oldpwd = ft_strjoin("PWD=", cwd);
	if (!oldpwd)
		return ;
	ft_export(data, oldpwd);
	free(oldpwd);
}

int	dummy(void)
{
	write(1, "HOME unset.\n", 13);
	return (1);
}

int	ft_cd(t_data *data, char **args)
{
	int		ret;
	char	*value;

	if (count_nb_arg(args) <= 2)
	{
		value = get_value(data, "HOME");
		if (!value)
			return (dummy());
		update_oldpwd(data);
		if (args[1] == NULL)
			ret = chdir(get_value(data, "HOME"));
		else
			ret = chdir(args[1]);
		update_currpwd(data);
		if (ret < 0)
			ret *= -1;
		if (ret == 1)
		{
			write(1, args[1], ft_strlen(args[1]));
			write(1, " : Такого файла или папки не существует\n",
				ft_strlen(" : Такого файла или папки не существует\n"));
		}
		return (ret);
	}
	return (1);
}
